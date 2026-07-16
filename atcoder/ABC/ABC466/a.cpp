#include<iostream>
using namespace std;

int main(void){
  int n; cin >> n;
  while(n--){
    int x; cin >> x;
    if(x>=0){
      cout << "No" << endl; return 0;
    }
  }
  cout << "Yes" << endl;
  return 0; 
}
