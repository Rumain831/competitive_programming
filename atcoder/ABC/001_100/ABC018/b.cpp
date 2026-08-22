#include<iostream>
#include<algorithm>
using namespace std;

//Tags: 文字列, 実装

int main(void){
  string s; cin >> s;
  int n; cin >> n;
  int m=s.size();
  for(int i=0; i<n; i++){
    int l, r; cin >> l >> r; l--;
    reverse(s.begin()+l, s.begin()+r);
  }
  cout << s << endl;
  return 0;
}