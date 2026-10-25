#include<iostream>
#include<vector>
using namespace std;

//Tags: 条件分岐

int main(void){
  int n; cin >> n;
  vector<int> a(n);
  int sum=0;
  for(int i=0; i<n; i++) cin >> a[i], sum+=a[i];
  if(sum%n){
    cout << -1 << endl; return 0;
  }
  int ave=sum/n, now=0, cnt=0, ans=0;
  for(int i=0; i<n; i++){
    now+=a[i], cnt++;
    if(now==cnt*ave) now=0, cnt=0;
    else ans++;
  }
  cout << ans << endl;
  return 0; 
}