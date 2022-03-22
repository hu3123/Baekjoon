#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>


using namespace std;

int main(){
  int n;

  scanf("%d", &n);
  vector<int> arr(n);
  for(int i=0; i<n; i++){
    scanf("%d", &arr[i]);

  }
  int tar;
  scanf("%d", &tar);

  for(int i=0; i<n; i++){
    int max=arr[i];
    int maxlo;
    int ch=0;
    for(int j=i+1; j-i<=tar && j<n; j++){
      if(max < arr[j]){
        max=arr[j];
        maxlo=j;
        ch=1;
      }
    }
    if(ch){
      tar-=maxlo-i;
      for(int j=maxlo-1; j>=i; j--){
        swap(arr[j], arr[j+1]);
      }
      if(tar==0)break;
    }
  }
  for(int i=0; i<n; i++){
    printf("%d ", arr[i]);
  }



  return 0;
}
