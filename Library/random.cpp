#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <random>
#include <chrono>

struct RandomTest{
  using ull = unsigned long long;
  mt19937_64 rng;
  RandomTest(ull seed=chrono::steady_clock::now().time_since_epoch().count()):rng(seed){}
  
  //[l, r]の整数
  ll LL(ll l, ll r){
    uniform_int_distribution<ll> dist(l, r);
    return dist(rng);
  }

  //[0, n-1]の整数
  int idx(int n){return LL(0, n-1);}

  //長さnの整数列　[lo, hi]
  vector<ll> vecll(int n, ll lo, ll hi){
    vector<ll> a(n);
    for(auto&x:a) x=LL(lo, hi);
    return a;
  }

  //長さnの順列 (st始まり)
  vector<int> perm(int n, int st){
    vector<int> p(n);
    iota(p.begin(), p.end(), st);
    shuffle(p.begin(), p.end(), rng);
    return p;
  }

  //charsから選んだ長さnの文字列
  string str_from(int n, const string& chars){
    string s;
    int m=chars.size();
    for(int i=0; i<n; i++) s.push_back(chars[idx(m)]);
    return s;
  }

  string lower(int n){return str_from(n, "abcdefghijklmnopqrstuvwxyz");}
  string upper(int n){return str_from(n, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");}
  string binary(int n){return str_from(n, "01");}
};

// グローバル乱数器
mt19937 rng((unsigned)chrono::steady_clock::now().time_since_epoch().count());

// [L, R] の乱数
int randint(int L, int R) {
  uniform_int_distribution<int> dist(L, R);
  return dist(rng);
}

// [0, 1) の実数乱数
double randdouble() {
  uniform_real_distribution<double> dist(0.0, 1.0);
  return dist(rng);
}

int main() {
  // 使用例
  int x = randint(1, 10);    // 1〜10
  double y = randdouble();   // 0〜1

  vector<int> a = {1, 2, 3, 4, 5};
  shuffle(a.begin(), a.end(), rng); // シャッフル
  
  RandomTest R(123456);
  int N = (int)R.LL(1, 10);
  auto a = R.vecll(N, -5, 5);
  string s = R.lower(20);
  // ...
}
