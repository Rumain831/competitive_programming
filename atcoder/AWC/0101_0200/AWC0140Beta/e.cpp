#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 桁dp

ll dp[20][400][2];

int main(void){
  ll n, d; cin >> n >> d;
  ll add=200;
  string s=to_string(n);
  int m=s.size();
  dp[0][add][0]=1;
  for(int i=0; i<m; i++){
    int now=s[i]-'0';
    for(int x=-200; x<200; x++)for(int ika=0; ika<2; ika++){
      int r=(ika?9:now), y=x+add;
      for(int j=0; j<=r; j++){
        int sg=(i%2?-1:1);
        if(m%2) sg*=-1;
        int ny=y+sg*j;
        int nika=(ika||j<now);
        dp[i+1][ny][nika]+=dp[i][y][ika];
      }
    }
  }
  ll ans=-1;
  for(int i=0; i<400; i++)if(abs(i-add)<=d) ans+=dp[m][i][0]+dp[m][i][1];
  cout << ans << endl;
  return 0; 
}