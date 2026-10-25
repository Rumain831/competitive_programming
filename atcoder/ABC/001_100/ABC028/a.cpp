#include<iostream>
using namespace std;

//Tags: 条件分岐

int main(void){
  int n; cin >> n;
  if(n<=59) cout << "Bad" << endl;
  else if(n<=89) cout << "Good" << endl;
  else if(n<=99) cout << "Great" << endl;
  else cout << "Perfect" << endl;
  return 0; 
}