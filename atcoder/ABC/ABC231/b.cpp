#include<iostream>
#include<map>
using namespace std;

//Tags: map

int main(void){
  int n; cin >> n;
  map<string, int> cnt;
  for(int i=0; i<n; i++){
    string s; cin >> s; cnt[s]++;
  }
  string ans;
  int maxi=0;
  for(auto p:cnt){
    if(maxi<p.second) ans=p.first, maxi=p.second;
  }
  cout << ans << endl;
  return 0;
}