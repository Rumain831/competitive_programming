#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 文字列, 実装
//Level: 2
//)が来るたびに、(連続とは限らない)部分列として*^^が取れるような*の位置として、その)に一番近いものを取る。
//その*より左にある(の数を足していけば良い(右向き用)。
//Sを反転して(括弧の向きもきちんと反転して)同じことをすれば左向きも求まる。

ll f(string s){
  ll ans=0;
  vector<int> eye, left, ch;
  int n=s.size();
  int pose=-1, ci=-1, li=-1, posc=-1;
  for(int i=0; i<n; i++){
    if(s[i]=='*') ch.push_back(i);
    else if(s[i]=='(') left.push_back(i);
    else if(s[i]=='^'){
      eye.push_back(i);
      int x=eye.size();
      if(x>=2) pose=eye[x-2];  
    }
    else{
      int m=ch.size();
      while(ci+1<m&&ch[ci+1]<pose) ci++, posc=ch[ci];
      m=left.size();
      while(li+1<m&&left[li+1]<posc) li++;
      if(li>=0) ans+=li+1;
    }
  }
  return ans;
}

int main(void){
  string s; cin >> s;
  for(int i=0; i<2; i++){
    reverse(begin(s), end(s));
    for(auto&x:s){
      if(x==')') x='(';
      else if(x=='(') x=')';
    }
    cout << f(s) << " \n"[i];
  }
  return 0; 
}