#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 文字列, 場合分け

int main(void){
  ll n, k; cin >> n >> k;
  while(n--){
    string s; cin >> s;
    int l=s.size(), sum=0;
    for(auto p:s) sum+=p-'a'+1;
    auto f=[&](ll d){
      d%=26;
      for(auto&p:s){
        ll now=p-'a'; now=(now+d)%26;
        p=(char)('a'+now);
      }
    };
    if(sum&1){
      if(k&1) reverse(begin(s), end(s));
    }
    else{
      if(l%2==0) f(k);
      else{
        f(1);
        ll r=k-1;
        if(r&1) reverse(begin(s), end(s));
      }
    }
    cout << s << '\n';
  }
  return 0; 
}