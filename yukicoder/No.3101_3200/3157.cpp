#include<iostream>
#include<vector>
using namespace std;

//Tags: 実装
//Level: 1.5

int main(void){
  string s; cin >> s;
  int sum=0, n=s.size();
  vector<int> d(n);
  for(int i=0; i<n; i++) d[i]=s[i]-'0';
  while(1){
    int pos=-1;
    for(int i=0; i<n; i++)if(d[i]==3){
      pos=i; break;
    }
    if(pos==-1){
      int sum=0;
      for(auto&x:d) sum+=x;
      if(sum%3) break;
      for(int i=n-1; i>=0; i--){
        if(d[i]<=0) d[i+1]--, d[i]+=10;
        else{
          d[i]--; break;
        }
      }
    }
    else{
      d[pos]=2;
      for(int i=pos+1; i<n; i++) d[i]=9;
    }
  }
  int z=0;
  for(int i=0; i<n; i++)if(d[i]){
    z=i; break;
  }
  for(int i=z; i<n; i++) cout << d[i]; cout << endl;
  return 0; 
}