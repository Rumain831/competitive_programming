#include<iostream>
#include<vector>
using namespace std;

//Tags: functional graph
//Level: 1.5

int main(void){
  int n; cin >> n;
  vector<int> p(n+1), rev(n+1), ok(n+1);
  for(int i=1; i<=n; i++) cin >> p[i], rev[p[i]]++;
  for(int i=1; i<=n; i++)if(rev[i]==0) ok[p[p[i]]]++;
  int ans=0;
  for(int i=1; i<=n; i++) ans+=(ok[i]>0);
  cout << ans << endl;
  return 0; 
}