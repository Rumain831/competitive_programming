#include<iostream>
using namespace std;

//Tags: 括弧列
//https://codeforces.com/contest/2227/problem/B

//全体を並び替えて正しい括弧列にできるならYes、そうでないならNo
void solve(){
  int n; cin >> n;
  string s; cin >> s;
  int p=0, q=0;
  for(int i=0; i<n; i++){
    if(s[i]=='(') p++;
    else q++;
  }
  cout << (p==q?"Yes":"No") << endl;
};

int main(void){
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0; 
}
