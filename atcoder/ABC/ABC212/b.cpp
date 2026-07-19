#include<iostream>
#include<set>
using namespace std;

int main(void){
  string x; cin >> x;
  string t="0123456789";
  set<string> weak;
  for(int i=0; i<=9; i++){
    string a="", b="";
    for(int j=0; j<4; j++){
      a+=(char)('0'+i);
      b+=(char)('0'+(i+j)%10);
    }
    weak.insert(a);
    weak.insert(b);
  }
  if(weak.find(x)==weak.end()) cout << "Strong" << endl;
  else cout << "Weak" << endl; 
  return 0; 
}