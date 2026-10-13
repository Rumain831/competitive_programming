#include<iostream>
#include<vector>
using namespace std;

//Tags: grid, 文字列

int main(void){
  int n; cin >> n;
  vector<string> s(n);
  for(auto&x:s) cin >> x;
  vector<string> ans=s;
  for(int i=n-2; i>=0; i--)for(int j=0; j<2*n-1; j++)if(s[i][j]=='#'){
    if(s[i+1][j-1]=='X'||s[i+1][j]=='X'||s[i+1][j+1]=='X') s[i][j]='X';
  }
  for(int i=0; i<n; i++) cout << s[i] << endl;
  return 0;
}