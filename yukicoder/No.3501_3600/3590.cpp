#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 転倒数, インタラクティブ
//Level: 2.5

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
    return sum(r)-sum(l-1);
  }
};

int main(void){
  int n; cin >> n;
  vector<int> a(n);
  ll pre=0;
  for(int i=1; i<n; i++){
    cout << "? " << 1 << ' ' << i+1 << endl;
    ll now; cin >> now;
    a[i]=now-pre;
    pre=now;
  }
  BIT bit(n);
  vector<int> ans(n);
  for(int i=0; i<n; i++) bit.add(i+1, 1);
  reverse(begin(a), end(a));
  for(int i=0; i<n; i++){
    ll x=a[i];
    int left=1, right=n;
    if(bit.range(1, 1)>x){
      ans[i]=n;
      bit.add(1, -1);
      continue;
    }
    while(right-left>1){
      int mid=(left+right)/2;
      int y=bit.range(1, mid);
      if(y>x) right=mid;
      else left=mid;
    }
    ans[i]=n+1-right;
    bit.add(right, -1);
  }
  reverse(begin(ans), end(ans));
  cout << "! ";
  for(auto p:ans) cout << p << ' '; cout << endl;
  return 0; 
}