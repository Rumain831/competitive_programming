#include<iostream>
using namespace std;

//Tags: 条件分岐

int main(void){
  int s, t, x; cin >> s >> t >> x;
  if(s<t) cout << (s<=x&&x<t?"Yes":"No") << endl;
  else cout << (x<t||s<=x?"Yes":"No") << endl;
  return 0;
}
