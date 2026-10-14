#include<iostream>
#include<vector>
using namespace std;

//Tags: 順列, Simulation

int main(void){
  int n; cin >> n;
  vector<int> a(n);
  for(auto&x:a) cin >> x, x--;
  for(int i=0; i<n; i++){
    if(a[i]==i){
      cout << 1 << ' '; continue;
    }
    int ans=0, now=i;
    while(a[now]!=i) now=a[now], ans++;
    cout << ans+1 << ' ';
  }
  return 0;
}