#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using i128 = __int128_t;
void chmax(i128& a, i128 b){a=max(a, b);}

//Tags: 区間dp

using i128 = __int128_t; 
string to_string_128(i128 x){
  if(x==0) return "0";
  bool neg=false;
  if(x<0) neg=true, x=-x;
  string ans;
  while(x>0){
    int p=x%10;
    ans.push_back((char)('0'+p));
    x/=10;
  }
  if(neg) ans.push_back('-');
  reverse(ans.begin(), ans.end());
  return ans;
}
//i128用の入力オーバーロード
istream& operator>>(istream& is, i128& x){
  string s; cin >> s;
  bool neg=false;
  int i=0;
  if(s[0]=='-') neg=true, i++;
  i128 val=0;
  for(; i<s.size(); i++){
    int p=s[i]-'0';
    val=(val)*10+p;
  }
  x=(neg?-val:val);
  return is;
}
//i128用の出力オーバーロード
ostream& operator<<(ostream& os, i128 x){
  return os << to_string_128(x);
}

i128 dp[51][51][51];
int main(void){
  int n, K; cin >> n >> K;
  vector<i128> a(n);
  for(auto&x:a) cin >> x;
  for(int i=0; i<n; i++) dp[i][i][0]=a[i];
  for(int len=2; len<=n; len++)for(int l=0; l+len-1<n; l++){
    int r=l+len-1;
    for(int c=0; c<=min(len-1, K); c++)for(int p=l; p<r; p++)for(int lc=0; lc<=c; lc++){
      chmax(dp[l][r][c], dp[l][p][lc]+dp[p+1][r][c-lc]);
      if(lc) chmax(dp[l][r][c], (dp[l][p][lc-1]+dp[p+1][r][c-lc])*2);
    }
  }
  cout << dp[0][n-1][min(n-1, K)] << endl;
  return 0; 
}