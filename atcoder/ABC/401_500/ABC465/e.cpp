#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

ll dp[505][4][2][2][(1<<10)+5];
ll MOD=998244353;

int main(void){
  string n; cin >> n;
  //dp[i][mod 3 or leading zero][include][n ika][2^10]
  int d=n.size();
  int mx=(1<<10);
  for(int i=0; i<d+1; i++)for(int j=0; j<4; j++)for(int k=0; k<2; k++)for(int l=0; l<2; l++)for(int p=0; p<mx; p++){
    dp[i][j][k][l][p]=0;
  }
  dp[0][3][0][0][0]=1;
  for(int i=0; i<d; i++){
    int now=n[i]-'0';
    for(int mod=0; mod<4; mod++)for(int in=0; in<2; in++)for(int ika=0; ika<2; ika++)for(int kind=0; kind<mx; kind++){
      int l=0, r=(ika?9:now);
      for(int j=l; j<=r; j++){
        int nmod;
        if(mod==3) nmod=(j==0?3:j%3);
        else nmod=(mod+j)%3;
        int nin=(in||j==3);
        int nika=(ika||j<now);
        int nkind;
        if(nmod!=3) nkind=(kind|(1<<j));
        else nkind=0;
        dp[i+1][nmod][nin][nika][nkind]+=dp[i][mod][in][ika][kind];
        dp[i+1][nmod][nin][nika][nkind]%=MOD;
      }
    }
  }
  ll ans=0;
  for(int mod=0; mod<3; mod++)for(int in=0; in<2; in++)for(int kind=0; kind<mx; kind++){
    int k=__builtin_popcount(kind);
    int c=(mod==0)+(in==1)+(k==3);
    if(c==1){
      ans+=dp[d][mod][in][0][kind]; ans%=MOD;
      ans+=dp[d][mod][in][1][kind]; ans%=MOD;
    }
  }
  cout << ans << endl;
  return 0; 
}