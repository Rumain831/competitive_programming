#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//貪欲法を考えたくなる見た目。考えたら本当に貪欲法でいけそうなことが判明。
//後ろから足していき、Aが出てきたときに末尾が、
//**CBAだったらCBAを取る。そうでなく*BAとなっていたらBAを取る。そうでないならAを取る。でOK。
void solve(){
  string s; cin >> s;
  reverse(begin(s), end(s));
  string t, x="ABC";
  for(auto p:s){
    t+=p;
    if(p=='A'){
      int mx=3, l=t.size();
      for(int j=0; j<3; j++){
        int id=l-1-j;
        if(id<0){
          mx=j; break;
        }
        if(t[id]!=x[j]){
          mx=j; break;
        }
      }
      while(mx--) t.pop_back();
    }
  }
  cout << t.size() << '\n';
}

int main(void){
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0; 
}
