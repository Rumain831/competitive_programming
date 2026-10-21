#include<iostream>
#include<vector>
using namespace std;

//Tags: 文字列
//Level: 1

int main(void){
  int n; cin >> n;
  vector a(n, vector<string>(n));
  for(auto&x:a)for(auto&y:x) cin >> y;
  vector<int> ans;
  for(int j=0; j<n; j++){
    int c=0;
    for(int i=0; i<n; i++){
      if(a[i][j]=="nyanpass") c++;
    }
    if(c==n-1) ans.push_back(j+1);
  }
  if(ans.size()!=1) cout << -1 << endl;
  else cout << ans[0] << endl;
  return 0; 
}