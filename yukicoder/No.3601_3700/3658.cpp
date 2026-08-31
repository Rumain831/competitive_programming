#include<iostream>
using namespace std;

//Tags: 場合分け, 実装
//Level: 2

int main(void){
  string s; cin >> s;
  int n=s.size();
  int five=n+1;
  string pre, aft;
  for(int i=0; i<n; i++){
    if(s[i]>'5'){five=i; break;}
    if(s[i]<'4'){five=i+1; break;}
  }
  if(five==n+1){
    cout << s << endl; return 0;
  }
  for(int i=five; i<n; i++) aft+='5';
  int r=five-1;
  if(r<0){
    cout << aft << endl; return 0;
  }
  if(s[r]<'4'){
    int f=-1;
    for(int i=r; i>=0; i--)if(s[i]=='5'){f=i; break;}
    if(f==-1)for(int i=1; i<=r; i++) pre+='5';
    else{
      for(int i=0; i<=r; i++){
        if(i==f) pre+='4';
        else pre+=(i<f?s[i]:'5');
      }
    }
  }
  else{
    pre=s.substr(0, r+1);
  }
  cout << pre+aft << endl;
  return 0; 
}