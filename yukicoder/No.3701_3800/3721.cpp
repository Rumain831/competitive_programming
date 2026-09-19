#include<iostream>
using namespace std;

//Tags: grid, 構築
//Level: 1.5

int main(void){
  int n, k; cin >> n >> k;
  if(k==0){
    cout << -1 << endl; return 0;
  }
  int st=n*n-k;
  for(int i=0; i<n; i++)for(int j=0; j<n; j++){
    int now=(st+n*i+j)%(n*n)+1;
    cout << now << (j==n-1?'\n':' ');
  }
  return 0; 
}