#include<iostream>
#include<vector>
using namespace std;

//Tags: Simulation, 逆順
//O(N)の解法
//i=Nのときの答えはN-K+1であることから出発し、適宜調整する

int main(void){
  int n, k; cin >> n >> k;
  vector<int> p(n);
  for(int i=0; i<n; i++) cin >> p[i], p[i]--;
  vector<int> ans(n), used(n);
  int now=n-k;
  for(int i=n-1; i>=k-1; i--){
    ans[i]=now; used[p[i]]=1;
    if(now<=p[i]){
      now--;
      while(now>=0&&used[now]) now--;
    }
  }
  for(int i=k-1; i<n; i++) cout << ans[i]+1 << endl;
  return 0;
}