#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 順列, 二分探索, セグ木

template<class Tr=ll>
struct BIT{
  int n;
  vector<Tr> bit;
  BIT(int size): n(size), bit(size+1, 0) {};

  void add(int i, Tr x){ //1-indexed
    while(i<=n){
      bit[i]+=x;
      i+=i&-i;
    }
  }

  Tr sum(int i){ //1-indexed
    Tr ans=0;
    while(i>0){
      ans+=bit[i];
      i-=i&-i;
    }
    return ans;
  }

  Tr range(int l, int r){ //1-indexed
    if(l>r) return 0;
    return sum(r)-sum(l-1);
  }
};


int main(void){
  int n; cin >> n;
  vector<int> a(n), ans(n);
  for(auto&x:a) cin >> x;
  BIT bit(n+1);
  for(int i=1; i<=n+1; i++) bit.add(i, 1);
  for(int i=0; i<n; i++){
    int left=1, right=n+1;
    while(right-left>1){
      int mid=(left+right)/2;
      int x=bit.range(1, mid-1);
      if(x>a[i]) right=mid;
      else left=mid;
    }
    ans[left-1]=i+1;
    bit.add(left, -1);
  }
  for(auto x:ans) cout << x << ' ';
  return 0; 
}