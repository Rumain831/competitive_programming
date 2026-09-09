#include<iostream>
using namespace std;

//Tags: 四則演算
//Level: 1

int main(void){
  int n, k; cin >> n >> k;
  int r=n%k;
  for(int i=0; i<k; i++) cout << n/k+(i<r) << ' ';
  return 0; 
}