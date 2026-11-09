#include<iostream>
#include<vector>
using namespace std;

//Tags: grid

int main(void){
  int h, w; cin >> h >> w;
  vector<string> s(h);
  for(auto&x:s) cin >> x;
  int mx=-1, ans;
  for(int j=0; j<w; j++){
    int now=0;
    for(int i=0; i<h; i++) now+=(s[i][j]=='F');
    if(mx<now){
      mx=now, ans=j+1;
    }
  }
  cout << ans << endl;
  return 0; 
}