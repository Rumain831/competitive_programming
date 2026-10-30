#include<iostream>
#include<vector>
using namespace std;

//Tags: grid, マンハッタン距離

int main(void){
  string s; int t; cin >> s >> t;
  int x=0, y=0, un=0;
  for(auto p:s){
    if(p=='?') un++;
    else if(p=='L') x--;
    else if(p=='R') x++;
    else if(p=='U') y++;
    else y--;
  }
  int now=abs(x)+abs(y);
  if(t==1) cout << now+un << endl;
  else{
    int p=min(now, un);
    now-=p, un-=p;
    now+=un%2;
    cout << now << endl;
  }
  return 0;
}