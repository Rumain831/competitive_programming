#include<iostream>
#include<vector>
using namespace std;

//Tags: 貪欲法
//Level: 1.5

int main(void){
  int n; cin >> n;
  vector<int> a(n), b(n);
  for(auto&x:a) cin >> x;
  for(auto&x:b) cin >> x;
  int ans=0, now=0;
  for(int i=0; i<n; i++){
    if(a[i]==b[i]) now=0;
    else{
      if(now==0) ans++, now=1; 
    }
  }
  cout << ans << endl;
  return 0; 
}