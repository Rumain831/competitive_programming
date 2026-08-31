#include<iostream>
using namespace std;

//Tags: Simulation
//Level: 1.5

int main(void){
  int n, m, p, q; cin >> n >> m >> p >> q; n--;
  int x=q*2*m+(12-q)*m, r=n%x;
  int ans=n/x*12;
  for(int i=1; i<=12; i++){
    int fall=(i<p||p+q<=i?m:2*m);
    if(r<fall){
      cout << ans+i << endl; return 0;
    }
    r-=fall;
  }
  return 0; 
}