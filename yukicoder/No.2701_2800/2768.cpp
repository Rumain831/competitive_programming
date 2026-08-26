#include<iostream>
using namespace std;

//Tags: 文字列, インタラクティブ
//Level: 2

int main(void){
  int n; cin >> n;
  string ans(n, 'a');
  for(int i=0; i<n; i++){
    bool ok=false;
    cout << "? " << ans << endl;
    int mx, c=0; cin >> mx; 
    for(char x='b'; x<'z'; x++){
      ans[i]=x;
      cout << "? " << ans << endl;
      int now; cin >> now;
      if(mx>now){ans[i]='a'; ok=true; break;}
      if(mx<now){ans[i]=x; ok=true; break;}
    }
    if(!ok) ans[i]='z';
  }
  cout << "! " << ans << endl;
  return 0;
}