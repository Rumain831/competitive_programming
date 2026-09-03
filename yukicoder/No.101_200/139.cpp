#include<iostream>
using namespace std;

//Tags: Simulation, 実装
//Level: 2

int f(int nt, int w, int T){
  int k=nt/T, r=nt%T;
  if(k&1) nt+=T-r;
  else if(T-r<w) nt+=T*2-r;
  return nt+w;
}

int main(void){
  int n, l; cin >> n >> l;
  int ans=0, pre=0;
  for(int i=0; i<n; i++){
    int x, w, t; cin >> x >> w >> t;
    ans+=x-pre;
    ans=f(ans, w, t);
    pre=x+w;
  }
  ans+=l-pre;
  cout << ans << endl;
  return 0; 
}