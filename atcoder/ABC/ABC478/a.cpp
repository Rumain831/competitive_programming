#include<iostream>
using namespace std;

//Tags: 四則演算

int main(void){
  int n, m; cin >> n >> m;
  int r=m%n;
  for(int i=1; i<=n; i++){
    cout << (i<=r?m/n+1:m/n) << endl;
  }
  return 0; 
}