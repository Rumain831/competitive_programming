#include<iostream>
#include<vector>
using namespace std;
using vc = vector<int>;

//Tags: 01列
//https://codeforces.com/contest/2254/problem/C1
//奇数番目の要素同士、偶数番目の要素同士を自由に入れ替えられる
//奇数番目と偶数番目の要素は入れ替えられない
//ゆえに、奇数番目の1の数=偶数番目の1の数 が可能であることの必要十分条件(0の数を比較してもok)

pair<vc, vc> f(string& s){
  vector<int> io, ie;
  for(int i=0; i<s.size(); i++){
    int now=s[i]-'0';
    if(now==0) continue;
    if(i%2) io.push_back(i);
    else ie.push_back(i);
  }
  return make_pair(io, ie);
}

void solve(){
  int n; cin >> n;
  string s, t; cin >> s >> t;
  auto [o1, e1]=f(s);
  auto [o2, e2]=f(t);
  if(o1.size()==o2.size()&&e1.size()==e2.size()) cout << "YES" << '\n';
  else cout << "NO" << '\n';
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}