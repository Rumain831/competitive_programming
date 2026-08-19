#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

ll f(ll x){
  if(x==0) return 0ll;
  string n=to_string(x);
  int d=n.size();
  vector dp(d+1, vector(2, vector<ll>(2)));
  dp[0][0][0]=1;
  for(int i=0; i<d; i++){
    int now=n[i]-'0';
    for(int ika=0; ika<2; ika++)for(int st=0; st<2; st++){
      int r=(ika?9:now);
      for(int p=0; p<=r; p++){
        if(p==4||p==9) continue;
        int nika=(ika||p<now);
        int nst=(st||p);
        dp[i+1][nika][nst]+=dp[i][ika][st];
      }
    }
  }
  return x-(dp[d][0][1]+dp[d][1][1]);
}

int main(void){
  ll a, b; cin >> a >> b;
  cout << f(b)-f(a-1) << endl;
  return 0;
}