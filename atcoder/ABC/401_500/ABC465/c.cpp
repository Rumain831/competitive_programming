#include<iostream>
#include<vector>
using namespace std;

int main(void){
  int n; cin >> n;
  string s; cin >> s;
  int l=0, r=n-1;
  vector<int> ans(n);
  int c=0;
  for(int i=n-1; i>=0; i--){
    if(s[i]=='x'){
      if(c&1) ans[l++]=i+1;
      else ans[r--]=i+1;
    }
    else{
      if(c&1) ans[r--]=i+1;
      else ans[l++]=i+1;
      c^=1;
    }
  }
  for(auto p:ans) cout << p << ' ';
  return 0; 
}