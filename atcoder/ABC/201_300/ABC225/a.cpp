#include<iostream>
#include<set>
using namespace std;

//Tags: 数え上げ, 文字列

int main(void){
  string s; cin >> s;
  set<char> st;
  for(auto p:s) st.insert(p);
  int ans[4]={0, 1, 3, 6};
  cout << ans[st.size()] << endl;
  return 0;
}