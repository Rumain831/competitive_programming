#include<iostream>
using namespace std;

//Tags: 文字列, 部分文字列
//Level: 2.5

int main(void){
  int n, q; cin >> n >> q;
  string s; cin >> s;
  while(q--){
    int T; cin >> T;
    if(T==1){
      int id; char c; cin >> id >> c; id--;
      s[id]=c;
    }
    else{
      string t; cin >> t;
      int m=t.size();
      bool ok=false;
      for(int j=0; j<n-m+1; j++){
        string p=s.substr(j, m);
        if(p==t){
          ok=true; break;
        }
      }
      cout << (ok?"Yes":"No") << '\n';
    }
  }
  return 0;
}