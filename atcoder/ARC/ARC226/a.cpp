#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<int, int>;

//Tags: 数え上げ
//3つ以上会議が重なる時間帯があれば答えは0
//sの昇順に並べておく
//dp[i][p] = i番目の会議までの割り当て方であって、終了時刻が最も遅い会議を担当するのが人pである場合の数

int main(void){
  int n; cin >> n;
  vector<P> meet;
  vector<int> imos(2*n+2);
  for(int i=0; i<n; i++){
    int s, t; cin >> s >> t;
    meet.emplace_back(s, t);
    imos[s]++, imos[t]--;
  }
  for(int i=2; i<=2*n; i++) imos[i]+=imos[i-1];
  sort(begin(meet), end(meet));
  {
    int mx=*max_element(begin(imos), end(imos));
    if(mx>2){
      cout << 0 << endl; return 0;
    }
  }
  ll mod=998244353;
  ll dp[2]={1, 1};
  int last=meet[0].second;
  for(int i=1; i<n; i++){
    ll old[2]={};
    swap(old, dp);
    auto [s, t]=meet[i];
    if(last<s){
      dp[0]+=old[0]+old[1], dp[0]%=mod;
      dp[1]+=old[0]+old[1], dp[1]%=mod;
    }
    else if(t<last){
      dp[0]+=old[0], dp[0]%=mod;
      dp[1]+=old[1], dp[1]%=mod;
    }
    else{
      dp[0]+=old[1], dp[0]%=mod;
      dp[1]+=old[0], dp[1]%=mod;
    }
    last=max(last, t);
  }
  cout << (dp[0]+dp[1])%mod << endl;
  return 0; 
}