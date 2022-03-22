#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

void solve(){
  int n;
  int Max=-9;

  scanf("%d", &n);
  vector<int> arr1(n);
  vector<int> arr2(n);

  for(int i=0; i<n; i++){
    scanf("%d", &arr1[i]);
  }
  for(int i=0; i<n; i++){
    scanf("%d", &arr2[i]);
  }

  Max = max(arr1[0], arr2[0]);
  if(n==1){
    printf("%d", Max);
    return;
  }

  arr1[1] += arr2[0];
  arr2[1] += arr1[0];

  Max = max(arr1[1], arr2[1]);

  for(int i=2; i<n; i++){
    arr1[i] += max(arr2[i-1], arr2[i-2]);
    arr2[i] += max(arr1[i-1], arr1[i-2]);
    int tmp = max(arr1[i], arr2[i]);

    Max = max(tmp, Max);

  }
  printf("%d", Max);

  return;
}

int main(){
  int n;
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    solve();
    printf("\n");
  }
  return 0;
}
