#include<iostream>
#include<vector>
using namespace std;

//Tags: 条件分岐

int main(void){
  int n; cin >> n;
  vector<int> h(n);
  for(auto&x:h) cin >> x;
  for(int i=0; i<n-1; i++){
    if(h[i]>=h[i+1]){
      cout << h[i] << endl; return 0;
    }
  }
  cout << h[n-1] << endl;
  return 0;
}