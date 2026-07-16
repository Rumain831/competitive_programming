#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
  int n; cin >> n;
  map<string, int> cnt;
  for(int i=0; i<n; i++){
    string s; cin >> s;
    if(cnt.find(s)==cnt.end()){
      cout << "OK" << endl;
      cnt[s]++;
    }
    else{
      cout << s << cnt[s] << endl;
      cnt[s]++;
    }
  }
  return 0;
}
