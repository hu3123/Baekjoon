#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

char a[2502];

int dp[2502];

int dat[30][2501];
int pos[30];

int check(int s, int e) {
  int i;
  for (i = s; i < (s + e) / 2 + 1; i++) {
    if (a[i] != a[e - i + s]) {
      break;
    }
  }
  if (i == (s + e) / 2 + 1)
    return 1;
  else
    return 0;
}

int main() {

  scanf("%s", a);
  int l = strlen(a);

  for (int i = 0; i < l; i++) {
    int t = a[i] - 65;

    if (pos[t]) {
      int Min = 999999999;

      for (int j = pos[t]; j > 0; j--) {
        if (check(dat[t][j], i)) {
          Min = min(Min, dp[dat[t][j] - 1]);
        }
      }
      dp[i] = Min + 1;
      dp[i] = min(dp[i], dp[i - 1] + 1);

    } else if (i) {
      dp[i] = dp[i - 1] + 1;
    } else {
      dp[i] = 1;
    }

    pos[t]++;
    dat[t][pos[t]] = i;
  }

  printf("%d", dp[l - 1]);

  return 0;
}
