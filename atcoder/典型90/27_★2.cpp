#include<iostream>
#include<set>
using namespace std;

//Tags: set
//解説URL: https://twitter.com/e869120/status/1387901052683386880

int main(void){
  int n; cin >> n;
  set<string> name;
  for(int i=1; i<=n; i++){
    string s; cin >> s;
    if(name.count(s)==0) cout << i << '\n';
    name.insert(s);
  }
  return 0; 
}