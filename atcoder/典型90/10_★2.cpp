#include<iostream>
#include<vector>
using namespace std;

//Tags: 累積和
//解説URL: https://twitter.com/e869120/status/1380652465834532865

int main(void){
  int n; cin >> n;
  vector sum(2, vector<int>(n+1));
  for(int i=0; i<n; i++){
    int c, p; cin >> c >> p; c--;
    sum[c][i+1]+=p;
    for(int j=0; j<2; j++) sum[j][i+1]+=sum[j][i];
  }
  int q; cin >> q;
  for(int i=0; i<q; i++){
    int l, r; cin >> l >> r;
    cout << sum[0][r]-sum[0][l-1] << ' ' << sum[1][r]-sum[1][l-1] << endl;
  }
  return 0;
}