#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

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
  string s, t; cin >> s >> t;
  int n=s.size(), m=t.size();
  string now=t;
  int d=(m+n-1)/n; d+=1;
  while(d--){
    now+=s;
  }
  auto p=z_algo(now);
  int ans=0;
  for(int i=0; i<n; i++){
    if(p[m+i]>=m) ans++;
  }
  cout << ans << endl;
  return 0; 
}