#include<iostream>
#include<vector>
using namespace std;

//Tags: 累積

pair<vector<int>, vector<int>> f(vector<int> a){
  int n=a.size();
  vector<int> l(n+2, -1), r(n+2, -1);
  for(int i=0; i<n; i++) l[i+1]=max(l[i], a[i]);
  for(int i=n-1; i>=0; i--) r[i+1]=max(r[i+2], a[i]);
  return {l, r};
}

int main(void){
  int n; cin >> n;
  vector<int> a(n), b(n);
  for(int i=0; i<n; i++) cin >> a[i] >> b[i];
  auto [la, ra]=f(a);
  auto [lb, rb]=f(b);
  int ans=2e9;
  for(int i=0; i<n; i++){
    int mxa=max(la[i], ra[i+2]); mxa++;
    int mxb=max(lb[i], rb[i+2]); mxb++;
    int da=max(0, mxa-a[i]);
    int db=max(0, mxb-b[i]);
    ans=min(ans, da+db);
  }
  cout << ans << endl;
  return 0; 
}