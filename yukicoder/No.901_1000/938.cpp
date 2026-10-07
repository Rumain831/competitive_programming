#include<iostream>
#include<vector>
#include<set>
using namespace std;

//Tags: 文字列
//Level: 2

int main(void){
  int n; cin >> n;
  vector<string> B;
  set<string> cheat;
  while(n--){
    string a, b; cin >> a >> b;
    cheat.insert(a);
    B.push_back(b);
  }
  for(auto p:B){
    if(cheat.count(p)) continue;
    cout << p << '\n';
    cheat.insert(p);
  }
  return 0; 
}