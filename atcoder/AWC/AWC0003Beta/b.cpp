#include<iostream>
#include<vector>
using namespace std;

int main(void){
  int n; cin >> n;
  vector<char> l(n), r(n);
  int ans=0;
  for(int i=0; i<n; i++) cin >> l[i] >> r[i];
  for(int i=0; i<n-1; i++)if(r[i]==l[i+1]) ans++;
  cout << ans << endl;
  return 0;
}