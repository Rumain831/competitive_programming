#include<iostream>
#include<vector>
using namespace std;

int main(void){
  int n, m; cin >> n >> m;
  vector<int> cnt(m);
  int ans=n;
  for(int i=0; i<n; i++){
    int a; cin >> a; a--;
    cnt[a]++;
  } 
  for(int i=0; i<m; i++){
    int b; cin >> b;
    ans-=min(cnt[i], b);
  }
  cout << ans << endl;
  return 0; 
}