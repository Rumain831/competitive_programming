#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: 辞書順, 貪欲法

int main(void){
  int n, l; cin >> n >> l;
  vector<string> s(n);
  for(int i=0; i<n; i++) cin >> s[i];
  sort(begin(s), end(s));
  for(int i=0; i<n; i++) cout << s[i];
  return 0;
}