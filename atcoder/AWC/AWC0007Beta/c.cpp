#include<iostream>
using namespace std;

int main(void){
  int n, k; cin >> n >> k;
  int mx=-1, ans;
  for(int i=0; i<n; i++){
    int a; cin >> a;
    if(mx<a){
      mx=a; ans=i+1;
    }
  }
  cout << ans << endl;
  return 0;
}