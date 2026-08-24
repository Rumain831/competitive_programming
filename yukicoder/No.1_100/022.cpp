#include<iostream>
#include<vector>
using namespace std;

//Tags: 括弧列
//Level: 1.5

int main(void){
  int n, k; cin >> n >> k;
  string s; cin >> s;
  vector<int> now, ans(n);
  for(int i=0; i<n; i++){
    if(s[i]=='(') now.push_back(i);
    else{
      int k=now.back(); now.pop_back();
      ans[k]=i, ans[i]=k;
    }
  }
  cout << ans[k-1]+1 << endl;
  return 0;
}