#include<iostream>
using namespace std;

int main(void){
  string s;
  for(int i=0; i<26; i++){
    int p; cin >> p; p--;
    s+=(char)('a'+p);
  }
  cout << s << endl;
  return 0; 
}