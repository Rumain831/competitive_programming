#include<iostream>
#include<vector>
#include<set>
using namespace std;

//Tags: 文字列

int main(void){
  int n, m; cin >> n >> m;
  set<string> sta;
  vector<string> name(n);
  for(int i=0; i<n; i++){
    string s; cin >> s;
    name[i]=s;
  }
  for(int i=0; i<m; i++){
    string t; cin >> t;
    sta.insert(t);
  }
  for(int i=0; i<n; i++){
    if(sta.count(name[i])) cout << "Yes" << '\n';
    else cout << "No" << '\n';
  }
  return 0;
}