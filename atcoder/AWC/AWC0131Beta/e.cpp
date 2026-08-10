#include<iostream>
using namespace std;
using ll = long long;

//Tags: 桁dp

int mx=160;
ll dp[20][160][10][2][2];
int main(void){
  string n; int k; cin >> n >> k;
  int d=n.size();
  dp[0][0][0][0][0]=1;
  for(int i=0; i<d; i++){
    int now=n[i]-'0';
    for(int pk=0; pk<mx; pk++)for(int pd=0; pd<10; pd++)for(int ika=0; ika<2; ika++)for(int st=0; st<2; st++){
      int r=(ika?9:now);
      for(int x=0; x<=r; x++){
        int npk=pk+abs(x-pd);
        int npd=x;
        int nika=(ika||x<now);
        int nst=(st||x);
        if(st==0&&nst) npk=0;
        if(npk>k) continue;
        dp[i+1][npk][npd][nika][nst]+=dp[i][pk][pd][ika][st];
      }
    }
  }
  ll ans=0;
  for(int i=0; i<10; i++) ans+=dp[d][k][i][0][1]+dp[d][k][i][1][1];
  cout << ans << endl;
  return 0; 
}