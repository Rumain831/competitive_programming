#include<iostream>
using namespace std;

int main(void){
  int n, m; cin >> n >> m;
  int ans=0;
  while(m!=0){
    int x=n%m;
    m=x; ans++;
  }
  cout << ans << endl;
  return 0; 
}