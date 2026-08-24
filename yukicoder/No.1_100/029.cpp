#include<iostream>
using namespace std;

//Tags: 貪欲法
//Level: 1

int main(void){
  int n; cin >> n;
  int cnt[11]={};
  while(n--){
    int a, b, c; cin >> a >> b >> c;
    cnt[a]++, cnt[b]++, cnt[c]++;
  }
  int ans=0;
  for(int i=1; i<=10; i++) ans+=cnt[i]/2, cnt[0]+=cnt[i]%2;
  ans+=cnt[0]/4;
  cout << ans << endl;
  return 0; 
}