#include<iostream>
#include<queue>
using namespace std;
using ll = long long;
using P = pair<ll, int>;

int main(void){
  int n, k, m; cin >> n >> k >> m;
  priority_queue<P> pri, rem;
  for(int i=0; i<n; i++){
    ll c, v;
    cin >> c >> v; c--;
    pri.emplace(v, c);
  }
  int cnt=0;
  ll ans=0;
  vector<int> used(n);
  while(cnt<m){
    auto [v, c]=pri.top(); pri.pop();
    if(used[c]) rem.emplace(v, c);
    else{
      used[c]++, cnt++;
      ans+=v;
    }
  }
  while(pri.size()){
    auto p=pri.top(); pri.pop();
    rem.emplace(p);
  }
  while(cnt<k){
    auto [v, c]=rem.top(); rem.pop();
    ans+=v; cnt++;
  }
  cout << ans << endl;
  return 0;
}