#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: bitDP

int main(void){
  int n, m; cin >> n >> m;
  vector<int> early(n), late(n);
  for(int i=0; i<m; i++){
    int x, y; cin >> x >> y; x--, y--;
    early[y]|=(1<<x);
    late[x]|=(1<<y);
  }
  int mx=(1<<n);
  vector<ll> dp(mx);
  dp[0]=1;
  for(int i=0; i<mx; i++)for(int j=0; j<n; j++)if(!(i>>j&1)){
    if(i&early[j]) continue;
    if((mx-1-i)&late[j]) continue;
    dp[i|(1<<j)]+=dp[i];
  }
  cout << dp[mx-1] << endl;
  return 0; 
}