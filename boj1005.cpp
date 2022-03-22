#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int indegree[1001];
long long cost[1001];
long long spend[1001];
bool visited[1001];
int ans;
int target;
queue<int> q;

void TS(vector<int> adj[], int curr, long long sum){
  indegree[curr]--;
  sum += cost[curr];
  spend[curr] = max(sum, spend[curr]);
  if(indegree[curr]>=0)
  {
    printf("%d ", curr);
    if(indegree[curr]==0)q.push(curr);
    return;
  }
  //fvisited[curr] = 1;

  for(int next : adj[curr]){
    //if(cost[next] + sum > spend[next])
      TS(adj, next, sum);
  }
  return;
}


void solve(){
  int n, m;
  scanf("%d %d" ,&n, &m);


  vector<int> adj[1001];

  memset(indegree, 0, sizeof(indegree));
  memset(cost, 0, sizeof(cost));
  memset(spend, 0, sizeof(spend));
  memset(visited, 0, sizeof(visited));


  for(int i=0; i<n; i++){
    scanf("%lld", &cost[i]);
  }

  for(int i=0; i<m; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    adj[a].push_back(b);
    indegree[b]++;
  }
  ans = -99;

  int target;

  scanf("%d", &target);


  for(int i=0; i<n; i++){
    if(indegree[i] == 0){
      q.push(i);
    }
  }
  for(int i=0; i<n; i++){
    TS(adj, q.front(), 0);
    q.pop();
  }

  printf("%lld\n", spend[target-1]);

  return;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int i=0; i<t; i++){
    solve();
  }
  return 0;
}
