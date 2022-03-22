#include <algorithm>
#include <iostream>
#include <stdio.h>

using namespace std;

long long tree[1 << 21];
long long arr[1000001];

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

void update(int s, int e, int node, int il, int ir, long long dif) {
  if (s > ir || e < il)
    return;
  tree[node] += dif;
  if (s == e)
    return;
  int mid = (s + e) / 2;
  update(s, mid, 2 * node, il, ir, dif);
  update(mid + 1, e, 2 * node + 1, il, ir, dif);
}

int main() {
  int n, m, k;

  scanf("%d %d %d", &n, &m, &k);

  init(1, n, 1);

  for (int i = 0; i < m + k; i++) {
    int a;
    scanf("%d", &a);

    if (a == 1) {
      int b, c;
      long long d;
      scanf("%d %d %lld", &b, &c, &d);

      arr[b] += c;
      update(1, n, 1, b, c, d);
    } else {
      int b, c;
      scanf("%d %d", &b, &c);
      printf("%lld\n", sum(1, n, 1, b, c));
    }
  }

  return 0;
}
