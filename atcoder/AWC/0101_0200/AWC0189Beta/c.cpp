#include<iostream>
using namespace std;
using ll = long long;

//Tags: 整数

ll gcd(ll a, ll b){
  if(b==0) return a;
  return gcd(b, a%b);
}

int main(void){
  int n; cin >> n;
  char s; cin >> s; n--;
  int bunsi=0, bumbo=n;
  while(n--){
    char x; cin >> x;
    bunsi+=(s!=x);
  }
  int g=gcd(bunsi, bumbo);
  printf("%d/%d\n", bunsi, bumbo);
  return 0; 
}