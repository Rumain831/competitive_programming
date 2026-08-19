#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 幾何, 3つの長方形

bool f2(ll x, ll y, ll a, ll b){
  bool ok=false;
  ll w=(a+y-1)/y;
  if(w<x) ok|=((x-w)*y>=b);
  swap(x, y);
  w=(a+y-1)/y;
  if(w<x) ok|=((x-w)*y>=b);
  return ok;
}

bool f3(ll x, ll y, ll a, ll b, ll c){
  bool ok=false;
  //w*y>=a
  ll w=(a+y-1)/y;
  if(w<x) ok|=f2(x-w, y, b, c);
  swap(x, y);
  w=(a+y-1)/y;
  if(w<x) ok|=f2(x-w, y, b, c);
  return ok;
}

int main(void){
  ll x, y, a[3]; cin >> x >> y >> a[0] >> a[1] >> a[2];
  sort(a, a+3);
  do{
    if(f3(x, y, a[0], a[1], a[2])){
      cout << "Yes" << endl; return 0;
    }
  }while(next_permutation(a, a+3));
  cout << "No" << endl;
  return 0; 
}