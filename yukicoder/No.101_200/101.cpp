#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 置換, 最小公倍数

ll gcd(ll a, ll b){
  if(b==0) return a;
  else return gcd(b, a%b);
}

int main(void){
  int n, k; cin >> n >> k;
  vector<int> p(n);
  for(int i=0; i<n; i++) p[i]=i;
  while(k--){
    int x, y; cin >> x >> y; x--, y--;
    swap(p[x], p[y]);
  }
  ll ans=1;
  vector<int> seen(n);
  for(int i=0; i<n; i++){
    if(seen[i]) continue;
    int c=0, now=i;
    while(!seen[now]){
      seen[now]=1, c++;
      now=p[now];
    }
    ll g=gcd(ans, c);
    ans=ans/g*c;
  }
  cout << ans << endl;
  return 0; 
}