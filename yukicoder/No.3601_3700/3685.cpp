#include<iostream>
using namespace std;

//Tags: 文字列, 論理
//Level: 2

void WA(string r, int k){
  int nw=0, nq=0, n=r.size();
  for(int i=0; i<k; i++) r[i]='A';
  int iq;
  for(int i=k; i<n; i++){
    if(r[i]=='?') nq++, iq=i;
    if(r[i]=='W') nw++;
  }
  if(nw){
    cout << r << '\n'; return;
  }
  if(nq==1) r[iq]='W';
  cout << r << '\n';
  return;
}

void Not(string r, int k){
  int na=0, nw=0, nq=0, n=r.size(), iq;
  for(int i=0; i<k; i++){
    if(r[i]=='A') na++;
    if(r[i]=='W') nw++;
    if(r[i]=='?') nq++, iq=i;
  }
  if(na==k){
    cout << string(n, 'A') << '\n'; return;
  }
  if(nw||nq>=2){
    cout << r << '\n'; return;
  }
  for(int i=k; i<n; i++)if(r[i]=='W') r[iq]='W';
  cout << r << '\n'; return;
}

void solve(){
  string r, s; int k; cin >> r >> s >> k;
  if(s[0]=='N') Not(r, k);
  else WA(r, k);
  return;
}

int main(void){
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0; 
}