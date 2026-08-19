#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
using ll = long long;
using P = pair<ll, int>;

//Tags: BFS

int main(void){
  ll a, n; cin >> a >> n;
  unordered_map<ll, int> dp;
  queue<P> bfs;
  bfs.emplace(1, 0);
  while(bfs.size()){
    auto [num, c]=bfs.front(); bfs.pop();
    if(num>n*10||dp.count(num)) continue;
    dp[num]=c;
    if(num>10&&num%10){
      string s=to_string(num), t=s.back()+s;
      t.pop_back();
      bfs.emplace(stoll(t), c+1);
    }
    bfs.emplace(num*a, c+1);
  }
  cout << (dp.count(n)?dp[n]:-1) << endl;
  return 0; 
}