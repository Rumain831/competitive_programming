#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 01文字列, 最適化

ll f(string s, string t){
  int n=s.size();
  vector<int> ps, pt;
  for(int i=0; i<n; i++){
    if(s[i]=='0') ps.push_back(i);
    if(t[i]=='0') pt.push_back(i);
  }
  int m=ps.size();
  ll ans=0;
  for(int i=0; i<m; i++){
    ans+=abs(ps[i]-pt[i]);
  }
  return ans;
}

int main(void){
  int n; cin >> n;
  string s[3]; cin >> s[0] >> s[1] >> s[2];
  string ans=string(2*n, '0');
  vector<vector<int>> ps(3);
  for(int i=0; i<2*n; i++){
    for(int j=0; j<3; j++){
      if(s[j][i]=='1') ps[j].push_back(i);
    }
  }
  for(int i=0; i<n; i++){
    int mid=ps[0][i]+ps[1][i]+ps[2][i];
    mid-=min({ps[0][i], ps[1][i], ps[2][i]});
    mid-=max({ps[0][i], ps[1][i], ps[2][i]});
    ans[mid]='1';
  }
  ll d=0;
  for(int i=0; i<3; i++) d+=f(s[i], ans);
  cout << d << endl << ans << endl;
  return 0; 
}