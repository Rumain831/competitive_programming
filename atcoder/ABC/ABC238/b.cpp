#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: Simulation

int main(void){
  int n; cin >> n;
  vector<int> a(n+1);
  a[0]=0;
  int maxi=-1;
  for(int i=0; i<n; i++){
    cin >> a[i+1];
    a[i+1]+=a[i];
    a[i+1]%=360;
  }
  sort(a.begin(), a.end());
  for(int i=0; i<n; i++){
    maxi=max(maxi, a[i+1]-a[i]);
  }
  maxi=max(maxi, 360-a[n]);
  cout << maxi << endl;
  return 0;
}