#include<iostream>
#include<vector>
using namespace std;

//Tags: grid

int main(void){
  int n, m; cin >> n >> m;
  vector b(n, vector<int>(m));
  for(auto&p:b)for(auto&q:p) cin >> q;
  int sti=b[0][0]/7+1, stj=(b[0][0]-1)%7;
  if(stj+m-1>=7){
    cout << "No" << endl; return 0;
  }
  vector should(n, vector<int>(m));
  for(int i=0; i<n; i++)for(int j=0; j<m; j++){
    should[i][j]=b[0][0]+7*i+j;
  }
  cout << (should==b?"Yes":"No") << endl;
  return 0;  
}