#include<iostream>
#include<vector>
using namespace std;

//Tags: 整数
//1をn回出力するのが手っ取り早い

int main(void){
  int n; cin >> n;
  vector<int> ans;
  int i=0;
  while(n>0){
    if(n%2) ans.push_back(1<<i);
    i++; n/=2;
  }
  cout << ans.size() << endl;
  for(auto p:ans) cout << p << endl; 
  return 0;
}