#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

int dp[100001];

int main(){
  int n;
  scanf("%d", &n);
  for(int i=1;i<=n; i++){
    int tmp;
    scanf("%d", &tmp);
    for(int j=i; j<=n; j++){
      if(dp[j-i] + tmp > dp[j]) dp[j] = dp[j-i] + tmp;
    }
  }
  printf("%d", dp[n]);

  return 0;
}
