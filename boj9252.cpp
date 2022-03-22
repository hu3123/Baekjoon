#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stack>


using namespace std;


int dp[1001][1001];

char a[1001], b[1001];
int l1, l2;


//
void solve(){
  int v;
  for(int i=0; i<l2; i++){

    for(int j=0; j<l1; j++){
      if(b[i] == a[j]){
        dp[i+1][j+1]=dp[i][j]+1;

      }
      else if(dp[i][j+1] < dp[i+1][j]){
        dp[i+1][j+1] = dp[i+1][j];
      }
      else dp[i+1][j+1] = dp[i][j+1];
    }


  }

  return;
}

int main(){

  scanf("%s", a);
  scanf("%s", b);


  l1 = strlen(a);
  l2 = strlen(b);
  solve();

  printf("%d\n", dp[l2][l1]);

  int s = dp[l2][l1];

  int cnt=l2;

  stack<char> st;

  for(int i=l1; i>=0; i--){
    if(dp[cnt][i] < s){
      st.push(a[i]);
      s--;
      while(cnt>=0 && dp[cnt][i]==dp[cnt-1][i]){
        cnt--;
      }
    }

    if(cnt<=0)break;
  }

  while(!st.empty()){
    printf("%c", st.top());
    st.pop();
  }

  return 0;
}
