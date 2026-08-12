#include<iostream>
#include<algorithm>
using namespace std;

//Tags: 二分探索

int main(void){
  int a[3]; cin >> a[0] >> a[1] >> a[2];
  sort(a, a+3);
  int ans=a[0];
  a[1]-=a[0], a[2]-=a[0], a[0]=0;
  int left=0, right=1e9;
  while(right-left>1){
    int mid=(left+right)/2;
    int rem=0, need=0;
    for(int i=0; i<3; i++){
      if(a[i]<=mid) need+=mid-a[i];
      else rem+=(a[i]-mid)/2;
    }
    if(need>rem) right=mid;
    else left=mid;
  }
  cout << ans+left << endl;
  return 0; 
}