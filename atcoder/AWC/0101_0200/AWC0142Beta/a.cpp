#include<iostream>
using namespace std;

//Tags: 実装
//注：テストケーズにピリオドが含まれないものがあった

int main(void){
  int n; cin >> n;
  int ans=0;
  for(int i=0; i<n; i++){
    double s; cin >> s;
    int t=s*10;
    cout << t << endl;
    if(t>370) ans+=t-370;
  }
  cout << ans << endl;
  return 0; 
}