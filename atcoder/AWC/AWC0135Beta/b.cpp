#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 有理数

struct info{
  ll p, q, id;
  info(){}
  info(ll p=0, ll q=1, ll id=0):p(p), q(q), id(id){} 
};

int main(void){
  int n; cin >> n;
  vector<info> vec;
  for(int i=0; i<n; i++){
    ll p, s; cin >> p >> s;
    vec.emplace_back(s, p, (ll)i+1);
  }
  sort(begin(vec), end(vec), [](const info& a, const info& b){
    if(a.p*b.q==a.q*b.p) return a.id<b.id;
    else return a.p*b.q>a.q*b.p;
  });
  cout << vec[0].id << endl;
  return 0; 
}