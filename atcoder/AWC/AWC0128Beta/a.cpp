#include<iostream>
#include<vector>
using namespace std;

//Tags: 整数

int main(void){
  int n, k; cin >> n >> k;
  int ans=0;
  while(n--){
    int a; cin >> a;
    if(abs(a)%k==0) ans++;
  }
  cout << ans << endl;
  return 0; 
}