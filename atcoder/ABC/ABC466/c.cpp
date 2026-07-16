#include<iostream>
using namespace std;
using ll = long long;

int main(void){
  int n; cin >> n;
  ll ans=0, r=-1;
  for(int i=1; i<=n-1; i++){
    if(i>=r) r=i+1;
    while(r<=n){
      printf("? %d %d", i, r); cout << endl;
      string s; cin >> s;
      if(s=="No") break;
      r++;
    }
    ans+=r-i-1;
  }
  cout << "! " << ans << endl;
  return 0; 
}