#include<iostream>
using namespace std;

//Tags: 素因数分解
//Level: 2

int cnt[2000001];
int main(void){
  int n, k; cin >> n >> k;
  for(int i=2; i<=n; i++){
    if(cnt[i]) continue;
    int now=i;
    while(now<=n){
      cnt[now]++;
      now+=i;
    }
  }
  int ans=0;
  for(int i=2; i<=n; i++) ans+=(cnt[i]>=k);
  cout << ans << endl;
  return 0; 
}