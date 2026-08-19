#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 二分探索

int main(void){
  int n, m; cin >> n >> m;
  vector<ll> a(n+2), b(m+2);
  for(int i=0; i<n; i++) cin >> a[i];
  for(int i=0; i<m; i++) cin >> b[i];
  a[n]=-1e18, a[n+1]=1e18;
  b[m]=-1e18, b[m+1]=1e18;
  sort(begin(a), end(a));
  sort(begin(b), end(b));
  ll ans=1e18;
  for(int i=1; i<=n; i++){
    int p=lower_bound(begin(b), end(b), a[i])-begin(b);
    ans=min(ans, abs(a[i]-b[p]));
    ans=min(ans, abs(a[i]-b[p-1]));
  }
  cout << ans << endl;
  return 0; 
}