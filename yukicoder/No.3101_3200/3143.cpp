#include<iostream>
#include<vector>
using namespace std;

//Tags: 括弧列, 実装
//Level: 2

bool right(string s){
  int x=0;
  for(auto p:s){
    if(p=='(') x++;
    else{
      if(x==0) return false;
      x--;
    }
  }
  return x==0;
}

int main(void){
  int n, k; string s; cin >> n >> k >> s;
  if(!right(s)){
    cout << "No" << endl; return 0;
  }
  string ans;
  vector<int> ch={0};
  for(auto p:s){
    if(p=='('){
      if(ans.size()&&ans.back()==')') ans+='+';
      ans+=p;
      ch.push_back(0);
    }
    else{
      int c=ch.back();
      if(c==0){
        if(k<2){
          cout << "No" << endl; return 0;
        }
        ans+="1+1", k-=2;
      }
      else if(c==1){
        if(k<1){
          cout << "No" << endl; return 0;
        }
        ans+="+1", k--;
      }
      ans+=p;
      ch.pop_back();
      ch.back()++;
    }
  }
  while(k--) ans+="+1";
  if(ch.back()==1&&ans.back()==')'){
    cout << "No" << endl; return 0;
  }
  cout << "Yes" << endl << ans << endl;
  return 0; 
}