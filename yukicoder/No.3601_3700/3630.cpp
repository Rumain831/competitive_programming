#include<iostream>
#include<algorithm>
using namespace std;

//Tags: 幾何
//Level: 1.5
//Keyword：三角不等式

int main(void){
  int a[3]; cin >> a[0] >> a[1] >> a[2];
  sort(a, a+3);
  cout << (a[0]+a[1]>a[2]?"Yes":"No") << endl;
  return 0;
}