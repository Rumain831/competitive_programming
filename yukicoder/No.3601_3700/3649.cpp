#include<iostream>
using namespace std;
using ll = long long;

//Tags: grid, 実装
//Level: 1.5

ll ans[3][3];
int main(void){
  ll n; cin >> n;
  ll r=n%3, x=n/3;
  for(int i=0; i<3; i++)for(int j=0; j<3; j++) ans[i][j]=x;
  if(x&1) for(int j=0; j<3; j++)for(int i=0; i<r; i++) ans[i][j]++;
  else  for(int i=0; i<3; i++)for(int j=0; j<r; j++) ans[i][j]++;
  for(int i=0; i<3; i++)for(int j=0; j<3; j++) cout << ans[i][j] << (j==2?'\n':' ');
  return 0; 
}