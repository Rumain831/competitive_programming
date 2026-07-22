#include<iostream>
using namespace std;

//Tags: 条件分岐

int main(void){
  int x; cin >> x;
  if(x>0&&x%100==0) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}