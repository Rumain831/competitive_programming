#include<iostream>
using namespace std;
using ll = long long;

//Tags: 三分探索, インタラクティブ
//Level: 2.5
//二分探索でも解ける模様

ll query(ll x, ll y){
  cout << 1 << ' ' << x << ' ' << y << endl;
  ll ans; cin >> ans;
  return ans;
}

ll fy(){
  ll left=-1e9, right=1e9, nx=-1e9;
  while(right-left>4){
    ll ml=(2*left+right)/3;
    ll mr=(left+2*right)/3;
    ll sl=query(nx, ml);
    ll sr=query(nx, mr);
    if(sl<=sr) right=mr;
    else left=ml;
  }
  ll sy=query(nx, left), ny=left;
  for(ll y=left+1; y<=right; y++){
    ll ns=query(nx, y);
    if(sy>ns) sy=ns, ny=y;
  }
  return ny;
}

ll fx(ll y){
  ll left=-1e9, right=1e9;
  while(right-left>4){
    ll ml=(2*left+right)/3;
    ll mr=(left+2*right)/3;
    ll sl=query(ml, y);
    ll sr=query(mr, y);
    if(sl<=sr) right=mr;
    else left=ml;
  }
  ll sx=query(left, y), nx=left;
  for(ll x=left+1; x<=right; x++){
    ll ns=query(x, y);
    if(sx>ns) sx=ns, nx=x;
  }
  return nx;
}

int main(void){
  int n; cin >> n;
  ll ny=fy(), nx=fx(ny);
  cout << 2 << ' ' << nx << ' ' << ny << endl; 
  return 0; 
}