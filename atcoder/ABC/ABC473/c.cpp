#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: 条件を満たすものの個数

int main(void){
  int n, k; cin >> n >> k;
  vector<int> cl(k);
  for(int i=0; i<n; i++){
    int x; cin >> x; x--;
    cl[x]++;
  }
  sort(begin(cl), end(cl));
  int mx=*max_element(begin(cl), end(cl));
  int ans=0;
  for(int i=0; i<k; i++) ans+=(cl[i]>=mx-1);
  cout << ans << endl;
  return 0; 
}