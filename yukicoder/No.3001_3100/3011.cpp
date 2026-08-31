#include<iostream>
using namespace std;

//Tags: インタラクティブ, 二分探索
//Level: 1.5

int main(void){
  int left=1, right=1e9;
  while(right-left>1){
    int mid=(left+right)/2;
    cout << mid << endl;
    int r; cin >> r;
    if(r!=0) return 0;
    right=mid;
  }
  cout << left << endl;
  int r; cin >> r;
  return 0; 
}