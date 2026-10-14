#include<iostream>
#include<vector>
using namespace std;

vector<int> KMP(string s){
  int n=s.size();
  //先頭からi文字までを考えたとき、接頭辞と接尾辞が一致する最大の長さ
  //i.e. s[0:i]の先頭x文字と末尾x文字が一致するxの最大値(ないなら0)
  vector<int> ans(n);
  int j=0;
  for(int i=1; i<n; i++){
    while(j>0&&s[i]!=s[j]) j=ans[j-1];
    if(s[i]==s[j]) j++;
    ans[i]=j;
  }
  return ans;
}

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

vector<int> z_search(string& all, string& sub){
  if(sub.size()==0) return {};
  string S=sub+'$'+all;
  auto z=z_algo(S);
  vector<int> ans;
  int m=sub.size(), l=S.size();
  for(int i=m+1; i<l; i++)if(z[i]>=m) ans.push_back(i-m-1);
  return ans; 
}

vector<int> manacher(string& s){
  string t="^#";
  for(auto p:s) t+=p, t+='#';
  t+='$';
  int m=t.size();
  vector<int> p(m);
  int c=0, r=0;
  for(int i=1; i<m-1; i++){
    int l=2*c-i;
    if(i<r) p[i]=min(r-i, p[l]);
    while(t[i+p[i]+1]==t[i-p[i]-1]) p[i]++;
    if(i+p[i]>r) c=i, r=i+p[i];
  }
  int n=s.size();
  vector<int> ans(n, 1);
  for(int i=0; i<n; i++){
    int c=2*i+2, d=(p[c]+1)/2;
    ans[i]=2*d-1;
  }
  return ans;
}

