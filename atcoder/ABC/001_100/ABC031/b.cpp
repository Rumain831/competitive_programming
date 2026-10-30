#include<iostream>
using namespace std;

//Tags: 条件分岐

int main(void){
  int l, h, n; cin >> l >> h >> n;
  for(int i=0; i<n; i++){
    int a; cin >> a;
    if(a>h) cout << -1 << '\n';
    else if(a>=l) cout << 0 << '\n';
    else cout << l-a << '\n';
  }
  return 0;
}