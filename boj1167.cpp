#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#define P pair<int, int>

using namespace std;

/*
struct edge{
  int node;
  int cost;

};
*/

int k=1;
vector<P> arr[100001];
int ch[100001];

long Max = -9999;

long dfs(int a, int mine){
  //printf("\n%d ", a);
  ch[a]=1;
  priority_queue<long> pq;
  long length = arr[a].size();
  //printf("%ld ", length);
  for(int i=0; i<length; i++){

    if(ch[arr[a][i].first]==0){
      //printf("* %d %d  %d  * ", a, i, arr[a][i].first);
      pq.push(dfs(arr[a][i].first, arr[a][i].second));
    }
  }
  long tmp1, tmp2;

  ch[a]=0;


  if(Max < mine) Max=mine;

  if(pq.empty()){
    return mine;
  }


  tmp1=pq.top();
  pq.pop();
  tmp2=0;

  if(Max < tmp1 + mine){
    Max=tmp1 + mine;
  }
  if(pq.empty() && a!=k){

    return tmp1 + mine;
  }
  if(!pq.empty())
    tmp2=pq.top();


  if(Max < tmp1 + tmp2 && tmp2){
    //printf("%d %d %d %d\n", a, Max, tmp1, tmp2);
    Max = tmp1 + tmp2;
  }
  if(a==k){
    return Max;
  }

  return mine + tmp1;

}

int main() {
  int n;
  scanf("%d", &n);
  for(int i=0; i<n; i++){
      int tmp;
      scanf("%d", &tmp);
      while(1){
        k=tmp;
        int tmp1, tmp2;
        scanf("%d", &tmp1);
        if(tmp1==-1)break;
        scanf("%d", &tmp2);
        arr[tmp].push_back(make_pair(tmp1, tmp2));
      }
  }

  printf("%ld", dfs(k, 0));



  return 0;
}
