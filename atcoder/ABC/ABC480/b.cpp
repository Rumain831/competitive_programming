#include<iostream>
#include<vector>
using namespace std;

//Tags: 文字列, 愚直

int change(string& s, string& t){
  int n=s.size(), m=t.size();
  if(n!=m) return 10;
  int ans=0;
  for(int i=0; i<n; i++) ans+=(s[i]!=t[i]);
  return ans;
}

int main(void){
  int n, m; cin >> n >> m;
  vector<string> s(n);
  for(auto&x:s) cin >> x;
  vector<int> vote(n);
  while(m--){
    string t; cin >> t;
    bool match=false;
    vector<int> one;
    for(int i=0; i<n; i++){
      if(s[i]==t){vote[i]++; match=true; break;}
      if(change(s[i], t)==1) one.push_back(i);
    }
    if(!match&&one.size()==1) vote[one[0]]++; 
  }
  for(auto p:vote) cout << p << '\n';
  return 0; 
}