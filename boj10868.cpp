#include<stdio.h>
#include<vector>
#include<algorithm>

#define M 2100000000

using namespace std;

long tree[1<<21];
long arr[100001];

int init(int s, int e, int node){
  if(s == e){
    return tree[node] = arr[s];
  }
  int mid = (s+e)/2;
  return tree[node] = min(init(s, mid, 2*node), init(mid+1, e, 2*node+1));
}

int Min(int s, int e, int node, int l, int r){
  if(s > r || e < l){
    return M;
  }
  if(l <= s && e <= r){
    //printf("%d %d %d\n", s, e, tree[node]);
    return tree[node];
  }
  int mid = (s+e)/2;
  return min(Min(s, mid, 2*node, l, r), Min(mid+1, e, 2*node+1, l, r));
}

int update(int s, int e, int node, int index, int dif){
  if (s > index || e < index)
    return tree[node];
  //tree[node] += dif;
  if (s == e){
    arr[s] = dif;
    tree[node] = dif;
    return tree[node];
  }
  int mid = (s + e) / 2;
  return tree[node] = min(update(s, mid, 2 * node, index, dif), update(mid + 1, e, 2 * node + 1, index, dif));
}

int main(){
  int n;
  int m;
  scanf("%d", &n);
  scanf("%d", &m);

  for(int i=1; i<=n; i++){
    scanf("%ld", &arr[i]);
  }

  init(1, n, 1);



  for(int i=0; i<m; i++){
    int b;
    long c;
    scanf("%d %ld", &b, &c);
    printf("%d\n", Min(1, n, 1, b, c));


  }

  return 0;
}
