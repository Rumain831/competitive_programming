#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main(void){
  int n, k; cin >> n >> k;
  vector t(n, vector<int>(k));
  for(int i=0; i<n; i++)for(int j=0; j<k; j++) cin >> t[i][j];
  for(int i=0; i<pow(k, n); i++){
    int copy=i, now=0;
    for(int j=0; j<n; j++){
      now^=t[j][copy%k];
      copy/=k;
    }
    if(now==0){
      cout << "Found" << endl; return 0;
    }
  }
  cout << "Nothing" << endl;
  return 0;
}