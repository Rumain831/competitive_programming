#include<iostream>
#include<vector>
using namespace std;

//Tags: 全探索
//Level: 1

int main(void){
  int n; cin >> n;
  vector<bool> ok(n, true);
  for(int i=0; i<n; i++){
    int a[4];
    for(int j=0; j<4; j++) cin >> a[j];
    string r; cin >> r;
    if(r=="NO"){
      for(int j=0; j<4; j++) ok[a[j]]=false;
    }
    else{
      for(int j=0; j<10; j++){
        bool er=true;
        for(int k=0; k<4; k++){
          if(j==a[k]) er=false;
        }
        if(er) ok[j]=false;
      }
    }
  }
  for(int i=0; i<10; i++) if(ok[i]) cout << i << endl;
  return 0;
}