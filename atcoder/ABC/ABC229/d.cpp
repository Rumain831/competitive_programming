#include<iostream>
using namespace std;

//Tags: 尺取り法

int main(void){
  string s; int k; cin >> s >> k;
  int idl=0, idr=0;
  int n=s.size(), ans=-1, now=0;
  while(idl<n){
    if(idr<idl) idr=idl, now=0;
    while(idr<n){
      if(s[idr]=='X') idr++;
      else{
        if(now==k) break;
        else now++, idr++;
      }
    }
    ans=max(ans, idr-idl);
    if(s[idl]=='.') now--;
    idl++;
  }
  cout << ans << endl;
  return 0; 
}