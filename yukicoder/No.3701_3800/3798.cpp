#include<iostream>
#include<algorithm>
using namespace std;

//Tags: 文字列, 転倒数
//Level: 3

bool db(string& s){
  int n=s.size();
  int cnt[26]={};
  for(int i=0; i<n; i++){
    if(cnt[s[i]-'a']) return true;
    cnt[s[i]-'a']++;
  }
  return false;
}

int inv(string s, string t){
  int n=s.size();
  int id[26]={};
  int c=1;
  for(int i=0; i<n; i++) id[s[i]-'a']=c++;
  int x=0;
  for(int i=0; i<n-1; i++)for(int j=i+1; j<n; j++){
    if(id[t[i]-'a']>id[t[j]-'a']) x^=1;
  }
  return x;
}

void solve(){
  string s, t; cin >> s >> t;
  string se, so, te, to;
  int n=s.size();
  for(int i=0; i<n; i+=2) se+=s[i], te+=t[i];
  for(int i=1; i<n; i+=2) so+=s[i], to+=t[i];
  {
    string s0=se, t0=te;
    string s1=so, t1=to;
    sort(begin(s0), end(s0));
    sort(begin(t0), end(t0));
    sort(begin(s1), end(s1));
    sort(begin(t1), end(t1));
    if(s0!=t0||s1!=t1){
      cout << "No" << '\n'; return;
    }
  }
  if(db(se)||db(so)||db(te)||db(to)){
    cout << "Yes" << '\n'; return;
  }
  if(inv(se, te)==inv(so, to)) cout << "Yes" << '\n';
  else cout << "No" << '\n';
}

int main(void){
  int q; cin >> q;
  while(q--) solve();
  return 0; 
}