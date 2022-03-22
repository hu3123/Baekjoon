#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<iostream>



using namespace std;

int arr[100001];
long long psum[100001];


long long f(int s, int e){
  if(s==e)return (long long)arr[s];
  if(s+1==e)return min((long long)arr[s]*2, (long long)arr[e]*2);

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
      sum ++;
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





int main(){
  int n;
  scanf("%d", &n);

  for(int i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }

  printf("%lld", f(0, n-1));

  return 0;
}
