#include<iostream>
#include<vector>
using namespace std;

//Tags: 条件分岐

int main(void){
  int n, p; cin >> n >> p;
  int ans=0;
  while(n--){
    int a; cin >> a;
    ans+=(a<p);
  }
  cout << ans << endl;
  return 0; 
}