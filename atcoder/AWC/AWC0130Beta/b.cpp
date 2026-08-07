#include<iostream>
#include<vector>
using namespace std;

//Tags: 反転

int main(void){
  int n; cin >> n;
  vector<int> p(n), q(n);
  for(auto&x:p) cin >> x;
  for(auto&x:q) cin >> x;
  int l=-1, r=-1;
  for(int i=0; i<n; i++){
    if(p[i]!=q[i]){
      l=i; break;
    }
  }
  if(l==-1){
    cout << "Yes" << endl; return 0;
  }
  for(int i=n-1; i>=0; i--){
    if(p[i]!=q[i]){
      r=i; break;
    }
  }
  vector<int> rev(n);
  for(int i=0; i<l; i++) rev[i]=p[i];
  for(int i=r+1; i<n; i++) rev[i]=p[i];
  for(int i=l; i<=r; i++) rev[r+l-i]=p[i];
  cout << (rev==q?"Yes":"No") << endl;
  return 0; 
}