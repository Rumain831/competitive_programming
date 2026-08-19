#include<iostream>
#include<set>
using namespace std;

int main(void){
  int n; cin >> n;
  set<int> price;
  for(int i=0; i<n; i++){
    int a; cin >> a; price.insert(a);
  }
  auto p=price.end(); advance(p, -2);
  cout << *p << endl;
  return 0;
}