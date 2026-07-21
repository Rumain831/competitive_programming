#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: Simulation

ll f(ll st, ll la){
  if(st>la) return 0ll;
  ll num=la-st+1;
  return num*(st+la)/2;
}

int main(void){
  ll n, k; cin >> n >> k;
  vector<ll> a(n);
  ll sum=0, ans=0;
  for(auto&x:a) cin >> x, sum+=x, ans+=x*(x+1)/2;
  if(sum<=k){
    cout << ans << endl; return 0;
  }
  ans=0;
  a.push_back(0); 
  sort(rbegin(a), rend(a));
  for(int i=0; i<n; i++){
    ll c=(a[i]-a[i+1])*(i+1);
    if(k>=c){
      ans+=f(a[i+1]+1, a[i])*(i+1);
      k-=c;
    }
    else{
      ll d=k/(i+1), r=k%(i+1);
      ans+=f(a[i]-d+1, a[i])*(i+1)+r*(a[i]-d);
      break;
    }
  }
  cout << ans << endl;
  return 0;
}