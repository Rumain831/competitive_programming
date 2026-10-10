#include<iostream>
#include<vector>
using namespace std;

//Tags: Simulation, 文字列

int main(void){
  int n, q; cin >> n >> q;
  vector<string> follow(n, string(n, 'N'));
  for(int i=0; i<q; i++){
    int x; cin >> x;
    if(x==1){
      int a, b; cin >> a >> b; a--, b--;
      follow[a][b]='Y';
    }
    else if(x==2){
      int a; cin >> a; a--;
      for(int j=0; j<n; j++){
        if(a!=j&&follow[j][a]=='Y') follow[a][j]='Y';
      }
    }
    else{
      int a; cin >> a; a--;
      vector<int> yotei;
      for(int j=0; j<n; j++){
        if(a==j) continue;
        if(follow[a][j]=='Y'){
          for(int k=0; k<n; k++){
            if(k!=a&&follow[j][k]=='Y') yotei.push_back(k);
          }
        }
      }
      for(auto p:yotei) follow[a][p]='Y';
    }
  }
  for(int i=0; i<n; i++) cout << follow[i] << endl;
  return 0;
}