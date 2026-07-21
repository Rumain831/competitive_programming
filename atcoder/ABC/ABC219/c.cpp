#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using P = pair<string, string>;

int main(void){
  string x; int n; cin >> x >> n;
  vector<P> s(n);
  vector<int> ord(26);
  for(int i=0; i<26; i++) ord[x[i]-'a']=i;
  for(auto&[p, q]:s){
    cin >> q;
    for(auto y:q){
      p+=(char)('a'+ord[y-'a']);
    }
  }
  sort(s.begin(), s.end());
  for(auto&[p, q]:s) cout << q << endl;
  return 0; 
}