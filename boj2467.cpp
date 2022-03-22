#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

int main(){
  int n;
  scanf("%d", &n);
  long arr[1000001];
  for(int i=0; i<n; i++){
    scanf("%ld", &arr[i]);
  }
  sort(arr, arr + n);

  int ptr1=0, ptr2=n-1;
  long Min = 21400000000;
  int anspos1, anspos2;

  while(ptr1 < ptr2){
    long tmp = arr[ptr2] + arr[ptr1];
    long t = abs(tmp);
    if(t <= Min){
      //printf("%d ", ptr2);
      anspos1 = ptr1;
      anspos2 = ptr2;
      Min = t;
    }
    //printf("%d %d \n", t, tmp);
    if(Min == 0)break;
    if(tmp < 0)ptr1++;
    else ptr2--;
  }

  printf("%ld %ld", arr[anspos1], arr[anspos2]);


  return 0;
}
