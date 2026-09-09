#include<iostream>
#include<vector>
#include<map>
using namespace std;
using ll = long long;

//Tags: 転倒数, 座標圧縮
//Level: 3

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
    if(r<l) return 0;
    return sum(r)-sum(l-1);
  }
};


int main(void){
  int n; cin >> n;
  vector<int> a(n);
  for(auto&x:a) cin >> x;
  int m;
  {
    map<int, int> mp;
    for(auto x:a) mp[x]++;
    int c=1;
    for(auto&p:mp) p.second=c++;
    for(auto&x:a) x=mp[x];
    m=mp.size();
  }
  BIT bit(m);
  ll ans=0;
  for(int i=0; i<n; i++){
    ans+=bit.range(a[i]+1, m);
    bit.add(a[i], 1);
  }
  cout << ans << endl;
  return 0; 
}