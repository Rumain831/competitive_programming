#include<iostream>
#include<vector>
#include<set>
using namespace std;

//Tags: bit全探索

int main(void){
  string s; cin >> s;
  set<string> all;
  int n=s.size();
  for(int i=0; i<(1<<n); i++){
    string now="";
    int l=0, r=n-1;
    for(int j=0; j<n; j++){
      if(i>>j&1) now+=s[l++];
      else now+=s[r--];
    }
    all.insert(now);
  }
  cout << all.size() << endl;
  return 0; 
}