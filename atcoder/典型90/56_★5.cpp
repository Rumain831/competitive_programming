#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: dp, 解の復元
//解説URL: https://twitter.com/e869120/status/1400221404109230082

int main(void){
  int n, s; cin >> n >> s;
  vector<int> a(n), b(n);
  for(int i=0; i<n; i++) cin >> a[i] >> b[i];
  vector pre(n+1, vector<int>(s+1, -1));
  vector<int> dp(s+1);
  dp[0]=1;
  for(int i=0; i<n; i++){
    vector<int> old(s+1);
    swap(old, dp);
    for(int j=0; j<=s; j++)if(old[j]){
      if(j+a[i]<=s) dp[j+a[i]]=1, pre[i+1][j+a[i]]=0;
      if(j+b[i]<=s) dp[j+b[i]]=1, pre[i+1][j+b[i]]=1;
    }
  }
  if(!dp[s]) cout << "Impossible" << endl;
  else{
    string ans;
    int now=s, id=n;
    while(id){
      ans+=(char)('A'+pre[id][now]);
      if(id==1) break;
      now-=(pre[id][now]==0?a[id-1]:b[id-1]);
      id--;
    }
    reverse(begin(ans), end(ans));
    cout << ans << endl;
  }
  return 0; 
}