#include<iostream>
using namespace std;

//Tags: 四則演算
//Level: 1

int main(void){
  int n; cin >> n;
  int x, y; cin >> x >> y;
  int ans=y-x; n--;
  while(n--){
    cin >> x >> y;
    if(ans!=y-x){
      cout << -1 << endl; return 0;
    }
  }
  cout << (ans>0?ans:-1) << endl;
  return 0; 
}