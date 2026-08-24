#include<iostream>
using namespace std;

//Tags: dp, 期待値
//Level: 3

double dp[101][101][101];
bool seen[101][101][101];
int cnt[4];
int main(void){
  int n; cin >> n;
  for(int i=0; i<n; i++){
    int a; cin >> a;
    a=min(a, 3);
    cnt[a]++;
  }
  auto dfs=[&](auto dfs, int a, int b, int c)->double {
    if(seen[a][b][c]) return dp[a][b][c];
    if(a<0||b<0||c<0) return 0;
    seen[a][b][c]=1;
    if(a+b+c==0){
      return dp[a][b][c]=0;
    }
    double ans=0;
    ans=1.0*n/(a+b+c)*(
          1.0+
          dfs(dfs, a-1, b+1, c)*a/n+
          dfs(dfs, a, b-1, c+1)*b/n+
          dfs(dfs, a, b, c-1)*c/n
        );
    return dp[a][b][c]=ans;
  };
  printf("%.10f\n", dfs(dfs, cnt[0], cnt[1], cnt[2]));
  return 0; 
}