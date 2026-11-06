#include<iostream>
using namespace std;

//Tags: 二分探索, インタラクティブ
//Level: 2

int f(int x){
  cout << "? " << x << endl;
  string s; cin >> s;
  return s[0]=='s';
}

int main(void){
  int left=0, right=1000;
  while(right-left>1){
    int mid1=(left+right)/2, mid2=mid1+1;
    int r1=f(mid1), r2=f(mid2);
    if(r1&&r2) left=mid2;
    else if(r1) left=mid1;
    else if(r2) left=mid2;
    else right=mid1;
  }
  cout << "! " << left << endl;
  return 0; 
}