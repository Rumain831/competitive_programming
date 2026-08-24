#include<iostream>
using namespace std;

//Tags: 愚直
//Level: 1.5

int main(void){
  int n; cin >> n;
  string s, t; cin >> s >> t;
  int p=s.size(), q=t.size();
  for(int i=0; i<n; i++){
    int a; cin >> a;
    for(int j=0; j*q<=a; j++){
      int rem=a-j*q;
      if(rem%p==0){
        int S=rem/p, T=j;
        while(S--) cout << s << ' ';
        while(T--) cout << t << ' ';
        cout << endl;
        break;
      }
    }
  }
  return 0; 
}