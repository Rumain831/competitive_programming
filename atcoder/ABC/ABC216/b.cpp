#include<iostream>
#include<vector>
using namespace std;

int main(void){
  int n; cin >> n;
  vector<pair<string, string>> name(n);
  for(auto&[p, q]:name) cin >> p >> q;
  for(int i=0; i<n-1; i++)for(int j=i+1; j<n; j++){
    if(name[i]==name[j]){
      cout << "Yes" << endl; return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}