#include<iostream>
#include<vector>
using namespace std;

//Tags: grid

int main(void){
  int n; cin >> n;
  vector<string> s(n), ans(n);
  for(int i=0; i<n; i++) cin >> s[i], ans[i]=s[i];
  for(int i=0; i<n; i++)for(int j=0; j<n; j++){
    ans[i][j]=s[n-1-j][i];
  }
  for(auto p:ans) cout << p << endl;
  return 0;
}
