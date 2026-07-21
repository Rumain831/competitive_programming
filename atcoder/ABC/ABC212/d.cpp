#include<iostream>
#include<queue>
using namespace std;
using ll = long long;

//Tags: Simulation, 累積和

int main(void){
  int q; cin >> q;
  ll plus=0;
  priority_queue<ll, vector<ll>, greater<ll>> pri;
  for(int i=0; i<q; i++){
    int type; cin >> type;
    if(type==1){
      ll x; cin >> x; x-=plus;
      pri.push(x);
    }
    else if(type==2){
      ll x; cin >> x; plus+=x;
    }
    else{
      auto now=pri.top(); pri.pop();
      cout << now+plus << '\n';
    }
  }
  return 0;
}