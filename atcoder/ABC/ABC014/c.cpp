#include<iostream>
#include<vector>
using namespace std;

int main(void){
  int n; cin >> n;
  vector<int> sum(1e6+2);
  for(int i=0; i<n; i++){
    int a, b; cin >> a >> b; b++;
    sum[a]++, sum[b]--;
  }
  int ans=-1;
  for(int i=1; i<1e6+2; i++) sum[i]+=sum[i-1];
  for(int i=0; i<1e6+1; i++) ans=max(ans, sum[i]);
  cout << ans << endl;
  return 0;
}