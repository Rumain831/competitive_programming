#include<iostream>
using namespace std;

//Tags: 文字列

int main(void){
  int n; cin >> n;
  string ans;
  while(n--){
    int a, b; cin >> a >> b;
    ans+=((a+b)%2?'x':'o');
  }
  cout << ans << endl;
  return 0; 
}