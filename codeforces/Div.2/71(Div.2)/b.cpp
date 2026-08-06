#include<iostream>
#include<vector>
using namespace std;

//Tags: Simulation
//https://codeforces.com/contest/71/problem/B

int main(void){
  int n, k, t; cin >> n >> k >> t;
  t*=n*k;
  vector<int> ans(n);
  for(int i=0; i<n; i++){
    int mx=100*k;
    if(t>=mx){
      ans[i]=k; t-=mx;
    }
    else{
      ans[i]=t/100; break;
    }
  }
  for(auto p:ans) cout << p << ' '; cout << endl;
  return 0; 
}