#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

int arr[100001];
int treemax[500002];
int treemin[500002];

int initmax(int s, int e, int node){
  if(s==e) return treemax[node] = arr[s];
  int mid = (s + e) / 2;
  return treemax[node] = max(initmax(s, mid, 2*node), initmax(mid+1, e, 2*node+1));
}
int initmin(int s, int e, int node){
  if(s==e) return treemin[node] = arr[s];
  int mid = (s + e) / 2;
  return treemin[node] = min(initmin(s, mid, 2*node), initmin(mid+1, e, 2*node+1));
}

int find_max(int s, int e, int node, int l, int r){
  if(s > r || e < l) return 0;

  if(s >= l && e <= r) return treemax[node];
  int mid = (s + e) / 2;

  return max(find_max(s, mid, 2*node, l, r), find_max(mid+1,  e, 2*node+1, l, r));
}
int find_min(int s, int e, int node, int l, int r){
  if(s > r || e < l) return 2000000000;

  if(s >= l && e <= r) return treemin[node];
  int mid = (s + e) / 2;

  return min(find_min(s, mid, 2*node, l, r), find_min(mid+1,  e, 2*node+1, l, r));
}

int main(){
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }
  initmax(0, n-1, 1);
  initmin(0, n-1, 1);
  for(int i=0; i<m; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", find_max(0, n-1, 1, a-1, b-1) - find_min(0, n-1, 1, a-1, b-1));
  }





  return 0;
}
