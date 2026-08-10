#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: Simulation

int main(void){
  int n; cin >> n;
  vector<int> h(n);
  for(auto&x:h) cin >> x;
  reverse(begin(h), end(h));
  int ans=0, id=0;
  while(id<n){
    int now=h[id]; id++;
    while(id<n){
      if(now<=h[id]) break;
      id++;
    }
    ans++;
  }
  cout << ans << endl;
  return 0; 
}