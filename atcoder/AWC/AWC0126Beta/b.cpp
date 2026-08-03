#include<iostream>
using namespace std;
using ll = long long;

//Tags: 桁和, 考察で瞬殺

int main(void){
  string s; int k, r; cin >> s >> k >> r;
  if(k>1){
    cout << 0 << endl; return 0;
  }
  ll now=0, mod=1e9+7;
  int n=s.size();
  for(auto p:s){
    int c=p-'0';
    now=(now*10+c)%mod;
  }
  cout << (now+mod-2)%mod << endl;
  return 0; 
}