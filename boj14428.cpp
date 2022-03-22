#include<stdio.h>
#include<vector>
#include<algorithm>

#define M 2100000000

using namespace std;

pair<long, long> tree[1<<21];
long arr[100001];


//make segment pair tree
pair<long, long> init(int s, int e, int node){
  if(s == e){
    tree[node].first = arr[s];
    tree[node].second = s;
    return tree[node];
  }
  int mid = (s+e)/2;
  pair<long, long> a = init(s, mid, 2*node);
  pair<long, long> b = init(mid+1, e, 2*node+1);

  if(a.first < b.first){
    tree[node] = a;
    return a;
  }
  else if(a.first > b.first){
    tree[node] = b;
    return b;
  }
  else if(a.second<b.second){
    tree[node] = a;
    return a;
  }
  else{
    tree[node] = b;
    return b;
  }

}


//Min
pair<long, long> Min(int s, int e, int node, int l, int r){
  if(s > r || e < l){
    return make_pair(M, M);
  }
  if(l <= s && e <= r){
    return tree[node];
  }
  int mid = (s+e)/2;

  pair<long, long> a = Min(s, mid, 2*node, l, r);
  pair<long, long> b = Min(mid+1, e, 2*node+1, l, r);

  if(a.first < b.first){
    return a;
  }
  else if(a.first > b.first){
    return b;
  }
  else if(a.second<b.second){
    return a;
  }
  else{
    return b;
  }
}


//updating
pair<long, long> update(int s, int e, int node, int index, int dif){
  if (s > index || e < index)
    return tree[node];
  //tree[node] += dif;
  if (s == e){
    arr[s] = dif;
    tree[node].first = dif;
    return tree[node];
  }
  int mid = (s + e) / 2;

  pair<long, long> a = update(s, mid, 2*node, index, dif);
  pair<long, long> b = update(mid+1, e, 2*node+1, index, dif);

  if(a.first < b.first){
    tree[node] = a;
    return a;
  }
  else if(a.first > b.first){
    tree[node] = b;
    return b;
  }
  else if(a.second<b.second){
    tree[node] = a;
    return a;
  }
  else{
    tree[node] = b;
    return b;
  }
}


int main(){
  int n;
  int m;
  scanf("%d", &n);

  for(int i=1; i<=n; i++){
    scanf("%ld", &arr[i]);
  }

  init(1, n, 1);

  scanf("%d", &m);

  for(int i=0; i<m; i++){
    int a, b;
    long c;
    scanf("%d %d %ld", &a, &b, &c);
    if(a==1){
      update(1, n, 1, b, c);
    }
    if(a==2){
      printf("%d\n", Min(1, n, 1, b, c).second);
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
