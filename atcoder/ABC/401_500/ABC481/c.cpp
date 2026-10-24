#include<iostream>
#include<map>
using namespace std;

//Tags: Simulation

int main(void){
  int q; cin >> q;
  int ans=1;
  map<string, int> id;
  while(q--){
    string s; cin >> s;
    if(id.count(s)) cout << id[s] << '\n';
    else{
      cout << ans << '\n';
      id[s]=ans++;
    }
  }
  return 0; 
}