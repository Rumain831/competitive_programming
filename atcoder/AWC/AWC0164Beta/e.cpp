#include<iostream>
#include<vector>
#include<algorithm>
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

int gcd(int a, int b){
  if(b==0) return a;
  return gcd(b, a%b);
}

void solve(){
  string s; cin >> s;
  auto Z=z_algo(s);
  vector<int> l;
  int n=s.size();
  for(int i=1; i<n; i++){
    int len=n-i;
    if(Z[i]==len) l.push_back(len);
  }
  reverse(begin(l), end(l));
  int p=l.size();
  if(p<=1) cout << (p==0?0:l[0]) << '\n';
  else{
    int g=l[1]-l[0];
    for(int i=1; i<p; i++){
      int d=l[i]-l[i-1];
      g=gcd(g, d);
    }
    cout << g << '\n';
  }
}

int main(void){
  int q; cin >> q;
  while(q--) solve();
  return 0; 
}