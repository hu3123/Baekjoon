#include <algorithm>
#include <iostream>
#include <stdio.h>

using namespace std;

long long tree[1 << 22];
long long arr[1000005];

long long init(int s, int e, int node) {
  if (s == e) {
    scanf("%lld", &arr[s]);
    return tree[node] = arr[s];
  }
  int mid = (s + e) / 2;
  return tree[node] = init(s, mid, 2 * node) + init(mid + 1, e, 2 * node + 1);
}

long long sum(int s, int e, int node, int l, int r) {
  if (s > r || e < l)
    return 0;
  if (l <= s && e <= r)
    return tree[node];
  int mid = (s + e) / 2;
  return sum(s, mid, 2 * node, l, r) + sum(mid + 1, e, 2 * node + 1, l, r);
}

long long update(int s, int e, int node, int index, long long dif) {
  if (s > index || e < index)
    return tree[node];
  if (s == e){
    return tree[node] = dif;
  }
  int mid = (s + e) / 2;
  return tree[node] = update(s, mid, 2 * node, index, dif) + update(mid + 1, e, 2 * node + 1, index, dif);
}

int main() {
  int n, m;

  scanf("%d %d", &n, &m);
  init(0, n-1, 1);
  for (int i = 0; i < m; i++) {
    int x, y;
    int a;
    long long b;
    scanf("%d %d %d %lld", &x, &y, &a, &b);

    printf("%lld\n", sum(0, n-1, 1, min(x-1, y-1), max(x-1, y-1)));


    update(0, n-1, 1, a-1, b);


  }

  return 0;
}
