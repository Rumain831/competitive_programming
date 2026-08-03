#include<iostream>
using namespace std;

//Tags: Simulation
//尺取り法的なシミュレーションによる解法

int main(void){
  int n; cin >> n;
  string s; cin >> s;
  int cnt=0, r=-1, rem=0;
  for(int i=0; i<n; i++){
    if(s[i]=='o') cnt++;
    if(r<i) r=i+1, rem=cnt;
    while(r<n&&rem){
      rem--;
      if(s[r]=='o') rem++;
      r++;
    }
    cout << r << '\n';
    rem++;
  }
  return 0; 
}