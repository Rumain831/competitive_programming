#include<iostream>
using namespace std;

//Tags: Simulation
//シミュレーションする解法
int main(void){
  int n, k, a; cin >> n >> k >> a;
  int id=a-1, last;
  while(k){
    k--;
    last=id;
    id=(id+1)%n;
  }
  cout << last+1 << endl;
  return 0;
}