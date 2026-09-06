#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: 順列, 実装

int main(void){
  int n; cin >> n;
  vector<int> p(n);
  for(auto&x:p) cin >> x;
  for(int i=0; i<n; i+=10){
    vector<int> ok, now;
    for(int j=i; j<min(n, i+10); j++){
      ok.push_back(j+1);
      now.push_back(p[j]);
    }
    sort(begin(now), end(now));
    if(ok!=now){
      cout << "No" << endl; return 0;
    }
  }
  cout << "Yes" << endl;
  return 0; 
}