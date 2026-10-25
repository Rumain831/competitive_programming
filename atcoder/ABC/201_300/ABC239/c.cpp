#include<iostream>
using namespace std;
using ll = long long;

//Tags: 幾何, 全探索

ll sq(ll a, ll b){
  return a*a+b*b;
}

int main(void){
  ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
  if(sq(x1-x2, y1-y2)>21){
    cout << "No" << endl; return 0;
  }
  ll dx[8]={1, 2, 2, 1, -1, -2, -2, -1};
  ll dy[8]={2, 1, -1, -2, -2, -1, 1, 2};
  for(int i=0; i<8; i++){
    ll nowx=x1+dx[i], nowy=y1+dy[i];
    if(sq(nowx-x2, nowy-y2)==5){
      cout << "Yes" << endl; return 0;
    }
  }
  cout << "No" << endl;
  return 0; 
}