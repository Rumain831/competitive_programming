#include<iostream>
using namespace std;

//Tags: 条件分岐

int main(void){
  int n; cin >> n;
  for(int i=1; i<=n; i++){
    if(i%3) cout << i << endl;
    else cout << "Fizz" << endl;
  }
  return 0; 
}