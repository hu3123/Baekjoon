#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

/*
  연산자 정리
  + == 0
  - == 1
  * == 2
  / == 3
*/


int n;
int num[13];
int nowarr[12];
int cal[4];

int Max=-999999999;
int Min= 999999999;

void calculator(int depth){
  //printf("depth == %d\n", depth);
  if(depth == n-1){
    int arr[13];
    copy(num, num+n, arr);
    for(int i=1; i<n; i++){
      if(nowarr[i-1]==0){
        arr[i] += arr[i-1];
      }
      if(nowarr[i-1]==1){
        arr[i] = arr[i-1] - arr[i];
      }
      if(nowarr[i-1]==2){
        arr[i] *= arr[i-1];
      }
      if(nowarr[i-1]==3){
        arr[i] = arr[i-1]/arr[i];
      }
    }
    if(Max < arr[n-1]){
      Max=arr[n-1];
    }
    if(Min > arr[n-1]){
      Min = arr[n-1];
    }


  }
  else{
    //printf("!\n");
    for(int i=0; i<4; i++){
      if(cal[i]){
        cal[i]--;
        nowarr[depth]=i;
        calculator(depth+1);
        cal[i]++;
      }
    }

  }

}

int main(){

  scanf("%d", &n);

  for(int i=0; i<n; i++){
    scanf("%d", &num[i]);
  }
  for(int i=0; i<4; i++){
    scanf("%d", &cal[i]);

  }

  calculator(0);

  printf("%d\n%d", Max, Min);



  return 0;
}
