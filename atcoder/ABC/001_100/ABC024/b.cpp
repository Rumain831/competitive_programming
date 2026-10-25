#include<iostream>
#include<vector>
using namespace std;

//Tags: Simulation

int main(void){
  int n, t; cin >> n >> t;
  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  int l=-1, r=-1, ans=0;
  for(int i=0; i<n; i++){
    int now=a[i];
    if(r<a[i]) ans+=r-l, l=a[i], r=a[i]+t;
    else r=a[i]+t;
  }
  ans+=r-l;
  cout << ans << endl;
  return 0;
}