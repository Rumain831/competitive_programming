#include<iostream>
#include<vector>
using namespace std;

//Tags: 愚直

int main(void){
  int m, d; string s; cin >> m >> d >> s;
  int ans=0;
  for(int i=0; i<m; i++){
    bool ok=true;
    for(int j=0; j<m; j++){
      if(s[j]=='G'&&abs(i-j)<=d){
        ok=false; break;
      }
    }
    if(ok) ans++;
  }
  cout << ans << endl;
  return 0; 
}