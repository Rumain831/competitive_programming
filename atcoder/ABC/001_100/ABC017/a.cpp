#include<iostream>
using namespace std;

//Tags: 四則演算

int main(void){
  int ans=0;
  for(int i=0; i<3; i++){
    int s, e; cin >> s >> e;
    ans+=s/10*e;
  }
  cout << ans << endl;
  return 0;
}