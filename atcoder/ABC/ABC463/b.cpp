#include<iostream>
using namespace std;

int main(void){
  int n; char x; cin >> n >> x;
  int tar=x-'A';
  for(int i=0; i<n; i++){
    string s; cin >> s;
    if(s[tar]=='o'){
      cout << "Yes" << endl; return 0;
    }
  }
  cout << "No" << endl;
  return 0; 
}