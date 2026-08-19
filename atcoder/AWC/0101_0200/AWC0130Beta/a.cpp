#include<iostream>
using namespace std;

//Tags: Simulation

int main(void){
  int n, m; cin >> n >> m;
  string s; cin >> s;
  int t=0, a=0;
  for(int i=0; i<n; i++){
    if(s[i]=='T') t++;
    else a++;
  }
  for(int i=1; i<=m; i++){
    int r; cin >> r; r--;
    if(s[r]=='T') t--, a++, s[r]='A';
    else a--, t++, s[r]='T';
    if(t==0||a==0){
      cout << i << endl; return 0;
    }
  }
  cout << -1 << endl;
  return 0; 
}