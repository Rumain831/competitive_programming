#include<iostream>
using namespace std;

//Tags: 条件を満たすものの個数

int main(void){
  int n, m; cin >> n >> m;
  int mx=-1;
  for(int i=0; i<n; i++){
    int d; cin >> d;
    mx=max(d, mx);
  }
  int ans=0;
  for(int i=0; i<m; i++){
    string s; int h; cin >> s >> h;
    ans+=(h>mx);
  }
  cout << ans << endl;
  return 0; 
}