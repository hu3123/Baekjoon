#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<iostream>



using namespace std;

int arr[1000001];
int ansl, ansr;
long long res;
long long f(int s, int e){
  if(s==e){
    if(res < (long long)arr[s]*arr[s]) {
      res = (long long)arr[s]*arr[s];
      ansl = ansr = s;
    }
    return (long long)arr[s]*arr[s];
  }
  //if(s+1==e)return min((long long)arr[s]*(arr[s]+arr[e]), (long long)arr[e]*(arr[s]+arr[e]));

  int mid = (s+e)/2;

  res = max(f(s, mid), f(mid+1, e));
  int l = mid, r=mid+1;
  int h = min(arr[mid+1], arr[mid]);
  long long sum = arr[mid]+arr[mid+1];
  if(sum * h > res){
    ansl =  mid;
    ansr = mid+1;
  }
  res = max(sum*h, res);

  while(1){
    if(l > s && arr[r+1] <= arr[l-1]){
      l--;
      if(l < s)break;
      if(arr[l] < h) h=arr[l];
      sum += arr[l];
      if(res < sum*h){
         res = sum*h;
         ansr = r;
         ansl = l;
       }
    }
    else{
      r++;
      if(r > e)break;
      if(arr[r] < h) h=arr[r];
      sum += arr[r];
      if(res < sum*h){
        ansr = r;
        ansl = l;
         res = sum*h;
       }
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

  printf("%lld\n", f(0, n-1));
  printf("%d %d", ansl+1, ansr+1);

  return 0;
}
