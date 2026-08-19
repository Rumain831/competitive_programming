#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 整数, n進数, 2進数

int main(void){
  ll n; cin >> n;
  vector<int> d;
  string ans="A";
  while(n){
    d.push_back(n&1);
    n/=2;
  }
  reverse(d.begin(), d.end());
  int m=d.size();
  for(int i=1; i<m; i++){
    ans+=(d[i]?"BA":"B");
  }
  cout << ans << endl;
  return 0; 
}