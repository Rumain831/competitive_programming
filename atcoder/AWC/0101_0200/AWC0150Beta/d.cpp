#include<iostream>
#include<vector>
using namespace std;

//Tags: grid, 実装

int main(void){
  int n, k, q; cin >> n >> k >> q;
  vector<string> s(n);
  for(auto&x:s) cin >> x;
  while(q--){
    int r, c; cin >> r >> c; r--, c--;
    vector<string> aft(k, string(k, '.'));
    for(int i=0; i<k; i++)for(int j=0; j<k; j++){
      int pi=k-1-j, pj=i;
      int si=r+pi, sj=c+pj;
      aft[i][j]=s[si][sj];
    }
    for(int i=0; i<k; i++)for(int j=0; j<k; j++){
      s[r+i][c+j]=aft[i][j];
    }
  }
  for(auto p:s) cout << p << endl;
  return 0; 
}