#include<iostream>
using namespace std;

//Tags: Simulation

int main(void){
  int n, a, b; cin >> n >> a >> b;
  int ans=0, dir=0;
  for(int i=0; i<n; i++){
    string s; int d; 
    cin >> s >> d;
    if(d<a) d=a;
    else if(d>b) d=b;
    if(s[0]=='W') d*=-1;
    ans+=d;
  }
  if(ans<0) cout << "West " << -ans << endl;
  else if(ans>0) cout << "East " << ans << endl;
  else cout << 0 << endl;
  return 0;
}