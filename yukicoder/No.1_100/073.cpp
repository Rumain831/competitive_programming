#include<iostream>
using namespace std;
using ll = long long;

//Tags: 数え上げ, 文字列

int main(void){
  ll cnt[26];
  for(int i=0; i<26; i++) cin >> cnt[i];
  ll ans=1;
  string s="hewrd";
  for(int i=0; i<s.size(); i++) ans*=cnt[s[i]-'a'];
  ll nl=cnt['l'-'a'], no=cnt['o'-'a'];
  ans*=(no/2)*(no-no/2);
  ll mx=0;
  for(int i=2; i<nl; i++){
    mx=max(mx, i*(i-1)/2*(nl-i));
  }
  ans*=mx;
  cout << ans << endl;
  return 0; 
}