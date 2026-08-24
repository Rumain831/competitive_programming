#include<iostream>
using namespace std;

//Tags: 最頻値
//Level: 1.5

int cnt[7];
int main(void){
  int n; cin >> n;
  while(n--){
    int l; cin >> l;
    cnt[l]++;
  }
  int mx=-1, ans;
  for(int i=1; i<7; i++){
    if(mx<=cnt[i]){
      mx=cnt[i], ans=i;
    }
  }
  cout << ans << endl;
  return 0; 
}