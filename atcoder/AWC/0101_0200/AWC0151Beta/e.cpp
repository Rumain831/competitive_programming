#include<iostream>
#include<vector>
#include<set>
using namespace std;
using ll = long long;

//Tags: Simulation, 整数

ll gcd(ll a, ll b){
  if(b==0) return a;
  return gcd(b, a%b);
}

int main(void){
  int n; cin >> n;
  if(n==1){
    cout << 1 << endl; return 0;
  }
  vector<vector<int>> gp(n+1);
  vector<int> seen(n+1), prime;
  set<int> yet;
  vector<set<int>> remain(n+1);
  for(int i=2; i<=n; i++){
    int now=i;
    yet.insert(i);
    if(gp[i].size()) continue;
    prime.push_back(i);
    while(now<=n){
      gp[now].push_back(i);
      remain[i].insert(now);
      now+=i;
    }
  }
  int ans=0, rem=n-1;
  seen[1]=1;
  while(rem){
    ans++;
    int now=*begin(yet);
    while(now<=n){
      seen[now]=1, rem--, yet.erase(now);
      int nxt=1e9;
      for(auto p:gp[now]){
        remain[p].erase(now);
        auto it=remain[p].upper_bound(now);
        if(it!=end(remain[p])){
          nxt=min(nxt, *it);
        }
      }
      now=nxt;
    }
  }
  cout << ans << endl;
  return 0; 
}