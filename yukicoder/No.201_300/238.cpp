#include<iostream>
#include<algorithm>
using namespace std;

//Tags: 回文
//Level: 3

int main(void){
  string s; cin >> s;
  int n=s.size(), l=0, r=n-1;
  string pre, aft;
  while(l<=r){
    if(l==r){
      pre+=s[l], aft+=s[l];
      break;
    }
    if(s[l]==s[r]){
      pre+=s[l], aft+=s[r];
      l++, r--;
    }
    else{
      string now=s.substr(l, r-l+1);
      {
        string tar=now+s[l], t=tar;
        reverse(begin(t), end(t));
        if(tar==t){
          pre+=tar; break;
        }
      }
      {
        string tar=s[r]+now, t=tar;
        reverse(begin(t), end(t));
        if(tar==t){
          pre+=tar; break;
        }
      }
      cout << "NA" << endl; return 0;
    }
  }
  if(pre.size()+aft.size()==n) pre+='a';
  reverse(begin(aft), end(aft));
  pre+=aft;
  string u=pre;
  reverse(begin(u), end(u));
  cout << (pre==u?pre:"NA") << endl;
  return 0; 
}