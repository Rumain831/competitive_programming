#include<iostream>
#include<set>
using namespace std;

//Tags: 標準形

int main(void){
  int n; cin >> n;
  set<int> cnt;
  for(int i=0; i<n; i++){
    int a; cin >> a;
    while(a%2==0) a/=2;
    cnt.insert(a);
  }
  cout << cnt.size() << endl;
  return 0;
}