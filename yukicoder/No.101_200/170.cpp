#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

//Tags: 文字列, 順列全探索
//Level: 1.5
//No.171のように二項係数で求めても良い

int main(void){
  string s, t; cin >> s;
  t=s;
  set<string> ans;
  sort(begin(t), end(t));
  do{
    if(t!=s) ans.insert(t);
  }while(next_permutation(begin(t), end(t)));
  cout << ans.size() << endl;
  return 0; 
}