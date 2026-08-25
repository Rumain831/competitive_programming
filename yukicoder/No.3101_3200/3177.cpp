#include<iostream>
using namespace std;

//Tags: 全探索
//Level: 1

int main(void){
  for(int a=0; a<=1; a++){
    for(int b=0; b<=1; b++){
      for(int c=0; c<=1; c++){
        int ab=!(a&b);
        int bc=!(b&c);
        if(!(ab&c)!=!(a&bc)){
          printf("%d %d %d\n", a, b, c); return 0;
        }
      }
    }
  }
  return 0; 
}