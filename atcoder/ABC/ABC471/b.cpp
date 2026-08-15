#include<iostream>
#include<vector>
#include<map>
using namespace std;

//Tags: 文字列

int main(void){
  int n; cin >> n;
  map<string, int> cnt;
  int ans=0;
  for(int i=0; i<n; i++){
    string s; cin >> s;
    for(auto&p:s) p=(char)toupper(p);
    cnt[s]++;
    ans=max(ans, cnt[s]);
  }
  cout << ans << endl;
  return 0; 
}