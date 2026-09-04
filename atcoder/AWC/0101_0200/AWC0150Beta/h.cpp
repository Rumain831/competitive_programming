#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 貪欲法

int main(void){
  int n, k; cin >> n >> k;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  ll ans=0;
  sort(begin(a), end(a));
  for(int t=0; t<2; t++){
    ll now=0, nk=k;
    ll L=a[0], R=a[0], c=0, l=1, r=n-1;
    while(nk){
      ll putl, putr;
      if(c&1) putl=a[l++];
      else putl=a[r--];
      now+=abs(L-putl), L=putl, nk--;
      if(nk==0) break;
      if(c&1) putr=a[l++];
      else putr=a[r--];
      now+=abs(R-putr), R=putr, nk--;
      c++;
    }
    ans=max(ans, now);
    reverse(begin(a), end(a));
  }
  cout << ans << endl;
  return 0; 
}