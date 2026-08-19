#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 全探索

int main(void){
  string s; cin >> s;
  int d=s.size(), mx=(1<<d);
  ll ans=-1;
  for(int i=1; i<mx-1; i++){
    string num[2];
    ll n[2];
    for(int j=0; j<d; j++) num[i>>j&1]+=s[j];
    sort(rbegin(num[0]), rend(num[0]));
    sort(rbegin(num[1]), rend(num[1]));
    n[0]=stoll(num[0]);
    n[1]=stoll(num[1]);
    ans=max(ans, n[0]*n[1]);
  }
  cout << ans << endl;
  return 0; 
}