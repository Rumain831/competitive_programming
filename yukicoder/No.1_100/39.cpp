#include<iostream>
#include<vector>
using namespace std;
using P = pair<int, int>;

//Tags: 辞書順

int main(void){
  string s; cin >> s;
  int n=s.size();
  vector<P> mx(n);
  mx[n-1]=P(s[n-1]-'0', n-1);
  for(int i=n-2; i>=0; i--){
    mx[i]=max(mx[i+1], P(s[i]-'0', i));
  }
  for(int i=0; i<n; i++){
    if(mx[i].first>s[i]-'0'){
      swap(s[mx[i].second], s[i]);
      break;
    }
  }
  cout << s << endl;
  return 0; 
}