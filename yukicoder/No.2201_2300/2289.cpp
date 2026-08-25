#include<iostream>
#include<vector>
using namespace std;

//Tags: 順列
//Level: 2

int main(void){
  int n; cin >> n;
  vector<int> p(n), seen(n);
  for(auto&x:p) cin >> x, x--;
  int ans=0;
  for(int i=0; i<n; i++){
    if(seen[i]) continue;
    int c=0, now=i;
    while(!seen[now]){
      seen[now]=1, c++;
      now=p[now];
    }
    ans+=c-1;
  }
  cout << ans << endl;
  return 0;
}