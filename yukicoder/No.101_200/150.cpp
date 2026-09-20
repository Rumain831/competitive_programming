#include<iostream>
#include<vector>
using namespace std;

//Tags: 文字列, 実装, ハミング距離
//Level: 2

string g="good", p="problem";
int f(string s, string& base){
  int n=s.size(), ans=0;
  for(int i=0; i<n; i++) ans+=(s[i]!=base[i]);
  return ans;
}
void solve(){
  string s; cin >> s;
  int n=s.size();
  vector<int> ch(n, 1e9);
  for(int i=4; i+6<n; i++){
    ch[i]=f(s.substr(i, 7), p);
  }
  int ans=1e9;
  for(int i=0; i+10<n; i++)for(int j=i+4; j+6<n; j++){
    ans=min(ans, f(s.substr(i, 4), g)+ch[j]);
  }
  cout << ans << endl;
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  
  return 0; 
}