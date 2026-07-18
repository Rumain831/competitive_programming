#include<iostream>
using namespace std;

int main(void){
  int n, x; cin >> n >> x;
  int ans=0;
  for(int i=0; i<n; i++){
    int a; cin >> a;
    if((x>>i)&1) ans+=a;
  }
  cout << ans << endl;
  return 0;
}