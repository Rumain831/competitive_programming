#include<iostream>
using namespace std;

//Tags: 全探索

int main(void){
  int a; cin >> a;
  int ans=-1;
  for(int i=1; i<a; i++){
    ans=max(ans, i*(a-i));
  }
  cout << ans << endl;
  return 0;
}