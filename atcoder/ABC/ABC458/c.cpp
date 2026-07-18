#include<iostream>
using namespace std;
using ll = long long;

int main(void){
  string s; cin >> s;
  int n=s.size();
  ll ans=0;
  for(int i=0; i<n; i++){
    if(s[i]=='C'){
      int l=i, r=n-1-i;
      ll x=min(l, r);
      ans+=x+1;
    }
  }
  cout << ans << endl;
  return 0; 
}