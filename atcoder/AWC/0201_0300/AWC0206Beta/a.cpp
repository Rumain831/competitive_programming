#include<iostream>
using namespace std;

//Tags: 条件分岐

int main(void){
  int n; cin >> n;
  while(n--){
    int a; cin >> a;
    if(a==10) cout << 'X';
    else if(a==0) cout << '-';
    else cout << a;
  }
  return 0; 
}