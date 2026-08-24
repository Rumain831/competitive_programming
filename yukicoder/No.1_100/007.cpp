#include<iostream>
#include<vector>
using namespace std;

//Tags: dp, ゲーム
//Level: 2

int main(void){
  int n; cin >> n;
  int nn=10000;
  vector<int> yakusu(nn+1, -1), prime;
  for(int i=2; i<=nn; i++){
    if(yakusu[i]!=-1) continue;
    int copy=i;
    prime.push_back(i);
    while(copy<=nn){
      if(yakusu[copy]==-1) yakusu[copy]=i;
      copy+=i;
    }
  }
  vector<bool> dp(n+1);
  dp[0]=dp[1]=true;
  for(int i=3; i<=n; i++){
    for(auto p:prime){
      if(p>i) break;
      if(!dp[i-p]){
        dp[i]=true; break;
      }
    }
  }
  cout << (dp[n]?"Win":"Lose") << endl;
  return 0;
}