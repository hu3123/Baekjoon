#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<string.h>

using namespace std;


bool cmp(int a, int b){
  return a > b;
}

int main(){
  int n, k;
  scanf("%d", &n);
  scanf("%d", &k);

  vector<int> arr(n);

  for(int i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }

  sort(arr.begin(), arr.end());

  vector<int> dist(n);



  int sum=0;

  for(int i=0;i<n-1; i++){
    dist[i] = arr[i+1] - arr[i];

  }

  sort(dist.begin(), dist.end());

  for(int i=0; i<n-k+1; i++){
    sum += dist[i];

  }
  printf("%d", sum);


  return 0;
}
