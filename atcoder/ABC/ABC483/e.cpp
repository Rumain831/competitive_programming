#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
using ll = long long;

//Tags: 文字列, ハミング距離

int main(void){
  int n, m; cin >> n >> m;
  vector<string> s(n);
  for(auto&x:s) cin >> x;
  ll zero=0, one=0, two=0;
  {
    unordered_map<string, ll> cnt;
    for(int i=0; i<n; i++) zero+=cnt[s[i]], cnt[s[i]]++;
  }
  {
    unordered_map<string, ll> cnt;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        char pre=s[i][j];
        s[i][j]='?';
        one+=cnt[s[i]];
        cnt[s[i]]++;
        s[i][j]=pre;
      }
    } 
    one-=(m)*zero;
  }
  {
    unordered_map<string, ll> cnt;
    for(int i=0; i<n; i++){
      for(int j=0; j<m-1; j++)for(int k=j+1; k<m; k++){
        char pre1=s[i][j], pre2=s[i][k];
        s[i][j]=s[i][k]='?';
        two+=cnt[s[i]];
        cnt[s[i]]++;
        s[i][j]=pre1, s[i][k]=pre2;
      }
    } 
    two-=m*(m-1)/2*zero+(m-1)*one;
  }
  cout << zero+one+two << endl;
  return 0; 
}