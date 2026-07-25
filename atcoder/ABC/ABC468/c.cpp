#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: 順列全探索

int main(void){
  int n; cin >> n;
  vector<int> p(n), q(n), r(n);
  for(auto&x:p) cin >> x;
  for(auto&x:q) cin >> x;
  for(int i=0; i<n; i++) r[i]=i+1;
  int ans=0;
  do{
    if(p<r&&r<q) ans++;
  }while(next_permutation(begin(r), end(r)));
  cout << ans << endl;
  return 0; 
}