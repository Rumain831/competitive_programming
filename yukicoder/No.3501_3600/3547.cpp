#include<iostream>
using namespace std;

//Tags: 貪欲法, bit演算
//Level: 1.5

int main(void){
  int n, m; cin >> n >> m;
  int ans=0;
  for(int i=0; i<30; i++){
    int tar=(m>>i&1), y=(n>>i&1);
    bool ok=false;
    for(int j=0; j<2; j++){
      int now=(i%2?j|y:j&y);
      if(now==tar){
        ok=true; ans+=(1<<i)*j;
        break;
      }
    }
    if(!ok){
      cout << -1 << endl; return 0;
    }
  }
  cout << ans << endl;
  return 0; 
}