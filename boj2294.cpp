#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>


using namespace std;

long dp[100001];

int main(){
  int n;
  int tar;

  scanf("%d %d", &n, &tar);
  vector<int> arr(n);
  fill(dp, dp+tar+1, 1000001);



  for(int i=0; i<n; i++){
    scanf("%d", &arr[i]);
    dp[arr[i]]=1;
  }

  sort(arr.begin(), arr.end());
  for(int i=arr[0]+1; i<=tar; i++){
    //printf("%d ", dp[i]);
    for(int j=0; j<n; j++){
      if(i - arr[j] > 0){
        dp[i] = min(dp[i], dp[i-arr[j]]+1);


      }
      else break;
    }
    //printf("%d ", dp[i]);
  }
  if(dp[tar]!=1000001)printf("%ld", dp[tar]);
  else printf("-1");



  return 0;
}
