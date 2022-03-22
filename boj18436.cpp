#include<stdio.h>
#include<vector>
#include<algorithm>

#define M 2100000000

using namespace std;

int tree[1<<21];
int arr[100001];

int init(int s, int e, int node){
  if(s == e){
    return tree[node] = arr[s];
  }
  int mid = (s+e)/2;
  return tree[node] = init(s, mid, 2*node) + init(mid+1, e, 2*node+1);
}

int sum(int s, int e, int node, int l, int r){
  if(s > r || e < l){
    return 0;
  }
  if(l <= s && e <= r){
    return tree[node];
  }
  int mid = (s+e)/2;
  return sum(s, mid, 2*node, l, r) + sum(mid+1, e, 2*node+1, l, r);
}

void update(int s, int e, int node, int index, int dif){
  if (s > index || e < index)
    return;
  tree[node] += dif;
  if (s == e)
    return;
  int mid = (s + e) / 2;
  update(s, mid, 2*node, index, dif);
  update(mid+1, e, 2*node + 1, index, dif);
}

int main(){
  int n;
  int m;
  scanf("%d", &n);

  for(int i=1; i<=n; i++){
    long tmp;
    scanf("%ld", &tmp);
    arr[i] = tmp%2;
  }

  init(1, n, 1);

  scanf("%d", &m);

  for(int i=0; i<m; i++){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(a==1){
      if((c % 2)!= (arr[b] % 2)){
        if(c%2==1){
          arr[b] = 1;
          update(1, n, 1, b, 1);
        }
        else{
          arr[b] = 0;
          update(1, n, 1, b, -1);
        }
      }

    }
    if(a==2){

      printf("%d\n", (c-b)+1 - sum(1, n, 1, b, c));
    }
    if(a==3){
      printf("%d\n", sum(1, n, 1, b, c));
    }
    /*
    for(int j=1; j<=n; j++){
      printf("%d ", arr[j]);
    }
    printf("\n");
    */

  }

  return 0;
}
