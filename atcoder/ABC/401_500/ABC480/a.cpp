#include<iostream>
using namespace std;

//Tags: grid

int main(void){
  string s[2]; cin >> s[0] >> s[1];
  int ai, aj, di, dj;
  for(int i=0; i<2; i++)for(int j=0; j<2; j++)if(s[i][j]=='A'){ai=i, aj=j;}
  for(int i=0; i<2; i++)for(int j=0; j<2; j++)if(s[i][j]=='D'){di=i, dj=j;}
  cout << (abs(ai-di)+abs(aj-dj)==1?"Yes":"No") << endl;
  return 0; 
}