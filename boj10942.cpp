#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int dp[2001][2001];

int main(){
  int n;
  scanf("%d", &n);
  vector<int> v(n+1);
  for(int i=0; i<n; i++){
    scanf("%d", &v[i+1]);
    dp[i+1][i+1]=1;
  }
  int m;
  scanf("%d", &m);
  //for(int i=1; i<=n; i++)
    //printf("%d ", v[i]);

  for(int i=0; i<m; i++){
    int s,e;
    scanf("%d %d", &s, &e);
    if(dp[s][e]==1)printf("1\n");
    else{
      int j;
      for( j=s; j<=(s+e)/2; j++){
        if(dp[j][s+e-j]==1){
          dp[s][e]=1;
          printf("1\n");
          break;
        }
        else if(v[j] != v[s+e-j]){
          printf("0\n");
          break;
        }
      }

      if(j == (s+e)/2 + 1){
        printf("1\n");
        dp[s][e]=1;
      }
    }

  }


  return 0;
}
