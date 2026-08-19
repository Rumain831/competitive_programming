#include<iostream>
#include<vector>
using namespace std;

//Tags: 文字列アルゴリズム

vector<int> z_algo(string& s){
  int n=s.size();
  vector<int> Z(n); //S[i:]とSの先頭からの最大一致長
  Z[0]=n;
  int l=0, r=0;
  for(int i=1; i<n; i++){
    if(i<r) Z[i]=min(r-i, Z[i-l]);
    while(i+Z[i]<n&&s[Z[i]]==s[i+Z[i]]) Z[i]++;
    if(i+Z[i]>r) l=i, r=i+Z[i];
  }
  return Z;
}

int main(void){
  int l, m; cin >> l >> m;
  string s, t; cin >> s >> t;
  string st=s+t, ts=t+s;
  int ans=0;
  auto vst=z_algo(st);
  for(int i=m; i<l+m; i++){
    int now=min(m, vst[i]);
    int same=l+m-i;
    if(now==same) ans=max(ans, now);
  }
  auto vts=z_algo(ts);
  for(int i=m; i<l+m; i++){
    int now=min(l, vts[i]);
    int same=l+m-i;
    if(now==same) ans=max(ans, now);
  }
  cout << ans << endl;
  return 0; 
}