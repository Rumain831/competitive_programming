#include<iostream>
using namespace std;
using ll = long long;

//Tags: 考察
//正方形の場合は90, 180, 270度回転できる
//空白を置く意味があるのは1の部分だけ
// 11122              1122
// 11122              1122
// 44122              3344
// 44333              3344   r=c=4
// 44333  r=c=5           
// 
// 11111              11111
// 11122              22222  r=2, c=5
// 22222  r=3, c=5

int main(void){
  ll r, c; cin >> r >> c;
  if(r==c){
    if(r%2==0) cout << r*c/4-1 << endl;
    else cout << r*c/4 << endl;
  }
  else cout << r*c/2+(r%2&&c%2)-1 << endl;
  return 0; 
}