#include<iostream>
using namespace std;

int main(void){
  int n; cin >> n;
  n%=30;
  string ans="123456";
  for(int i=0; i<n; i++){
    swap(ans[i%5], ans[i%5+1]);
  }
  cout << ans << endl;
  return 0;
}