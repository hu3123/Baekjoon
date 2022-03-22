#include<stdio.h>
#include<vector>

using namespace std;
int dp[10001];
int main(){
  int n;
  int tar;
  scanf("%d %d", &n, &tar);
  vector<int> arr(n);
  for(int i=0; i<n; i++){
    scanf("%d", &arr[i]);
    //dp[arr[i]]=1;
  }
  /*
    arr[0]만 사용한것과
    arr[1]도 사용한 것 등을 구별시켜야함

  */
  dp[0]=1;
  for(int i=0; i<n; i++){
    for(int j=1; j<=tar; j++){
      if(j-arr[i] >= 0){
        dp[j] += dp[j-arr[i]];
      }
    }
  }
  printf("%d", dp[tar]);





  return 0;
}
