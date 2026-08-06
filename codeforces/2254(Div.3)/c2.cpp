#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
using vc = vector<int>;

//Tags: 01列, 貪欲法
//https://codeforces.com/contest/2254/problem/C1
//奇数番目の要素同士、偶数番目の要素同士を自由に入れ替えられる
//奇数番目と偶数番目の要素は入れ替えられない
//Aの奇数番目にある1, Bの奇数番目にある1の添字をそれぞれ前から取り出し、順番にマッチさせる
//偶数番目にある1についても同様

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
  if(o1.size()!=o2.size()||e1.size()!=e2.size()){
    cout << -1 << '\n'; return;
  }
  ll ans=0, m1=o1.size(), m2=e1.size();
  for(int i=0; i<m1; i++) ans+=abs(o1[i]-o2[i]);
  for(int i=0; i<m2; i++) ans+=abs(e1[i]-e2[i]);
  cout << ans/2 << endl;
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}