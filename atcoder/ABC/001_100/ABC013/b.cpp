#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
  int a, b; cin >> a >> b;
  cout << min({abs(a-b), abs(10+a-b), abs(10+b-a)}) << endl;
  return 0;
}