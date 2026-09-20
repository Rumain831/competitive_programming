#include<iostream>
using namespace std;

//Tags: 括弧列, 条件分岐
//Level: 2.5

bool solve(){
  string s; cin >> s;
  int x=0, w=0, rw=0, r=0;
  for(auto p:s){
    if(p=='W') w++, rw++;
    else if(p=='G'){
      if(rw==0) return false;
      rw--; x++, w=0;
    }
    else{
      if(x==0) return false;
      x--, r++;
    }
  }
  return x==0&&w==0&&r;
}

int main(void){
  int t; cin >> t;
  while(t--){
    cout << (solve()?"possible":"impossible") << endl;
  }
  return 0; 
}