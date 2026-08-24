#include<iostream>
#include<vector>
using namespace std;
void chmax(string& a, string b){a=max(a, b);}

//Tags: dp
//Level: 4
//文字としては '+' > '*' だったのでmaxで処理している
//dp[i][x]=i番目までの数を使ってxを作る文字列の辞書順最大(上の意味で)のもの
int main(void){
  int n, total; cin >> n >> total;
  vector<int> a(n);
  for(auto&x:a) cin >> x;
  vector dp(n, vector<string>(total+1, ")"));
  if(a[0]<=total) dp[0][a[0]]="";
  for(int i=0; i<n-1; i++)for(int j=0; j<=total; j++){
    for(int k=0; k<2; k++)if(dp[i][j]!=")"){
      int nadd=j+a[i+1];
      if(nadd<=total) chmax(dp[i+1][nadd], dp[i][j]+'+');
      int nmul=j*a[i+1];
      if(nmul<=total) chmax(dp[i+1][nmul], dp[i][j]+'*');
    }
  }
  cout << dp[n-1][total] << endl;
  return 0; 
}