#include<iostream>
#include<vector>
using namespace std;

//Tags: 条件分岐, 数列

int main(void){
  int n, m; cin >> n >> m;
  vector<int> ans(m, -1);
  for(int i=0; i<n; i++){
    vector<int> s(m);
    for(auto&x:s) cin >> x;
    for(int j=0; j<m; j++){
      if(ans[j]==-1) ans[j]=s[j];
      else if(s[j]==-1) continue;
      else if(ans[j]!=s[j]){
        cout << "No" << endl; return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0; 
}