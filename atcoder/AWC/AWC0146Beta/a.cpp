#include<iostream>
#include<vector>
using namespace std;

//Tags: Simulation

int main(void){
  int n, m, q; cin >> n >> m >> q;
  vector<int> s(n), u(n), f(n);
  for(int i=0; i<n; i++){
    cin >> s[i] >> u[i] >> f[i];
  }
  while(q--){
    int d; char c; cin >> d >> c; d--;
    s[d]+=(c=='+'?1:-1);
    int nu=(c=='+'?7-f[d]:f[d]);
    int nf=(c=='+'?u[d]:7-u[d]);
    u[d]=nu, f[d]=nf;
  }
  for(int i=0; i<n; i++) cout << s[i] << ' ' << u[i] << endl; 
  return 0; 
}