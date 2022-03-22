#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>

using namespace std;




int solve(int n) {


    vector<int> arr(n);
    vector<int> ans;
    int *res = (int*)malloc(sizeof(int)*1000000);
    int i;

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        if (ans.size()) {
          int lo;
          int tar = arr[i];
          vector<int>::iterator itr = lower_bound(ans.begin(), ans.end(), tar);
          int pos = itr - ans.begin();
          //printf("%d\n", pos);
          if (pos == ans.size()) {
              ans.push_back(tar);
          }
          else {
              ans[pos] = tar;
          }

        }
        else {
            ans.push_back(arr[i]);
            res[i] = 1;
        }
    }

    printf("%ld\n", ans.size());

    return 0;
}


int main(){
  int n;
  while(scanf("%d", &n) != EOF){
    solve(n);
  }
}
