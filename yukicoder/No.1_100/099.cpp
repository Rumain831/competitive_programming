#include<iostream>
using namespace std;

//Tags: パリティ
//Level: 1.5

int main(void){
  int n; cin >> n;
  int even=0, odd=0;
  while(n--){
    int x; cin >> x;
    if(abs(x)&1) odd++;
    else even++;
  }
  cout << abs(odd-even) << endl;
  return 0; 
}