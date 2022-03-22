#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#define N 2100000000

using namespace std;

vector<int> adj[1000000];
bool visited[1000000];
int n;
int dp[1000000][2];

void sns(int curr){
  visited[curr] = 1;
  dp[curr][1] = 1;

  for(int next : adj[curr]){
    if(visited[next] == 0){
      sns(next);
      dp[curr][1] += min(dp[next][1], dp[next][0]);
      dp[curr][0] += dp[next][1];

    }
  }
  return;

}

int main(){

  scanf("%d",&n);

  for(int i=0; i<n-1; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }


  sns(0);
  printf("%d", min(dp[0][0], dp[0][1]));


  return 0;
}
