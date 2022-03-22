#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<iostream>
#include<cstring>


using namespace std;

long long arr[100001];
long long psum[100001];


long long f(int s, int e){
  if(s==e)return (long long)arr[s];

  int mid = (s+e)/2;

  long long res = max(f(s, mid), f(mid+1, e));
  int l = mid, r=mid+1;
  int h = min(arr[mid+1], arr[mid]);
  long long sum = 2;
  res = max(sum*h, res);

  while(1){
    if(arr[r+1] > arr[l-1]){
      r++;
      if(r > e)break;
      if(arr[r] < h) h=arr[r];
      sum++;
      if(res < sum*h) res = sum*h;
    }
    else{
      l--;
      if(l < s)break;
      if(arr[l] < h) h=arr[l];
      sum ++;
      if(res < sum*h) res = sum*h;
    }


  }
  return res;

}





int solve(int n){
  memset(arr, 0, sizeof(arr));
  memset(psum, 0, sizeof(psum));
  for(int i=0; i<n; i++){
    scanf("%lld", &arr[i]);
  }

  printf("%lld\n", f(0, n-1));

  return 0;
}

int main(){
  int n;
  while(1){
    scanf("%d", &n);
    if(n==0)break;
    solve(n);
  }



  return 0;
}
