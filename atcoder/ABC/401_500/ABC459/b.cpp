#include<iostream>
using namespace std;

int main(void){
  int n; cin >> n;
  string t="22233344455566677778889999";
  for(int i=0; i<n; i++){
    string s; cin >> s;
    int p=s[0]-'a';
    cout << t[p];
  }
  return 0; 
}