#include<iostream>
using namespace std;

int main(void){
  int n; cin >> n;
  int h, m, s;
  h=n/3600, n-=h*3600, m=n/60, n-=60*m, s=n;
  if(h<10) cout << 0 << h; else cout << h; cout << ':';
  if(m<10) cout << 0 << m; else cout << m; cout << ':';
  if(s<10) cout << 0 << s; else cout << s;
  cout << endl;
  return 0;
}