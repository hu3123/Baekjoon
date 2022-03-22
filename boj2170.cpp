#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

int main(){
  int n;
  scanf("%d", &n);
  vector<int> arr(2*n);
  vector<int> arr1(n);
  vector<int> arr2(n);
  int cnt=0;
  int Max=-9;
  for(int i=0; i<n; i++){
    scanf("%d %d", &arr1[i], &arr2[i]);
    arr[cnt++]=arr1[i];
    arr[cnt++]=arr2[i];
    if(Max < max(arr1[i], arr2[i])){
      Max=max(arr1[i], arr2[i]);
    }
  }


  n=2*n;
  sort(arr.begin(), arr.end());
  sort(arr1.begin(), arr1.end());
  sort(arr2.begin(), arr2.end());


  int height=0;
  int cnt1=0, cnt2=0;
  int length_sum=0;
  int start;


  for(int i=0; i<n; i++){
    if(arr1[cnt1]==arr[i]){
      height++;
      cnt1++;
      if(height==1){
        start=arr[i];
      }
      continue;
    }
    if(arr2[cnt2]==arr[i]){
      cnt2++;
      height--;
      if(height==0){
        length_sum+=arr[i]-start;
      }
      continue;
    }

  }

  printf("%d", length_sum);




  return 0;
}
