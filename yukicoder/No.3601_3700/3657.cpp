#include<iostream>
#include<vector>
using namespace std;

//Tags: grid
//Level: 1.5

int main(void){
  int n, m; cin >> n >> m;
  vector<string> s(n);
  vector<int> cnt(m), imos(n+1);
  for(int i=0; i<n; i++){
    cin >> s[i];
    for(int j=0; j<m; j++)if(s[i][j]=='#') cnt[j]++;
  }
  for(int i=0; i<m; i++)if(cnt[i]){
    imos[0]++, imos[cnt[i]]--;
  }
  for(int i=0; i<n; i++) imos[i+1]+=imos[i];
  for(int i=0; i<n; i++){
    cout << string(imos[i], '#')+string(m-imos[i], '.') << endl;
  }
  return 0; 
}