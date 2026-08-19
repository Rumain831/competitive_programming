#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
void chmax(int& a, int b){a=max(a, b);}

int main(void){
  int n; cin >> n;
  vector d(n, vector<int>(n));
  vector sum(n+1, vector<int>(n+1));
  for(int i=0; i<n; i++)for(int j=0; j<n; j++){
    cin >> d[i][j]; sum[i+1][j+1]=d[i][j];
  }
  for(int i=1; i<=n; i++)for(int j=1; j<=n; j++) sum[i][j]+=sum[i][j-1];
  for(int j=1; j<=n; j++)for(int i=1; i<=n; i++) sum[i][j]+=sum[i-1][j];
  vector<int> maxi(n*n+1);
  auto f=[&](int i1, int j1, int i2, int j2){
    return sum[i2][j2]-sum[i1-1][j2]-sum[i2][j1-1]+sum[i1-1][j1-1];
  };
  for(int i1=1; i1<=n; i1++)for(int j1=1; j1<=n; j1++){
    for(int i2=i1; i2<=n; i2++)for(int j2=j1; j2<=n; j2++){
      chmax(maxi[(i2-i1+1)*(j2-j1+1)], f(i1, j1, i2, j2));
    }
  }
  for(int i=2; i<=n*n; i++) chmax(maxi[i], maxi[i-1]);
  int q; cin >> q;
  while(q--){
    int p; cin >> p;
    cout << maxi[p] << '\n';
  }
  return 0;
}