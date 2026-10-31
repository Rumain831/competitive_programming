#include<iostream>
#include<vector>
using namespace std;

//Tags: grid

int main(void){
  vector<string> s(5);
  for(auto&x:s) cin >> x;
  int ans=1e9;
  for(int i=0; i<5; i++){
    int now=0;
    for(int j=0; j<5; j++) now+=(s[i][j]=='o');
    ans=min(ans, 5-now);
  }
  for(int j=0; j<5; j++){
    int now=0;
    for(int i=0; i<5; i++) now+=(s[i][j]=='o');
    ans=min(ans, 5-now);
  }
  {
    int now=0;
    for(int i=0; i<5; i++) now+=(s[i][i]=='o');
    ans=min(ans, 5-now);
  }
  {
    int now=0;
    for(int i=0; i<5; i++) now+=(s[i][4-i]=='o');
    ans=min(ans, 5-now);
  }
  cout << ans << endl;
  return 0; 
}