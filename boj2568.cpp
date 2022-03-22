#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<map>
#include<stack>

using namespace std;

vector<int> ans;
int *res = (int*)malloc(sizeof(int)*1000000);
int i;
map<int, int> mp12;
map<int, int> mp21;

void binary_search(int tar) {
    int lo;
    vector<int>::iterator itr = lower_bound(ans.begin(), ans.end(), tar);
    int pos = itr - ans.begin();
    //printf("%d\n", pos);
    if (pos == ans.size()) {
        ans.push_back(tar);
        res[i] = ans.size();
    }
    else {
        ans[pos] = tar;
        res[i] = pos + 1;
    }
    return;
}



int main() {
    int n;

    scanf("%d", &n);

    vector< int > in(n);

    for(i=0; i<n; i++){
      int tmp;
      scanf("%d %d", &in[i], &tmp);
      mp12[in[i]] = tmp;
      mp21[tmp] = in[i];
    }

    sort(in.begin(), in.end());

    int *arr = (int*)malloc(sizeof(int)*500000);

    //B의 위치를 arr로 만들기
    for (i = 0; i < n; i++) {
        arr[i] = mp12[in[i]];
    }

    for (i = 0; i < n; i++) {
        if (ans.size()) {
            binary_search(arr[i]);
        }
        else {
            ans.push_back(arr[i]);
            res[i] = 1;
        }
    }


    //printf("%ld\n", ans.size());

    int k = ans.size();

    stack<int> s;

    int m = k;

    /*
    for(int i=0; i<n; i++){
      printf("%d ", res[i]);
    }

    */

    for (int i = n - 1; i >= 0; i--) {
        if (res[i] == k) {
          //printf("%d ", mp21[arr[i]]);
            k--;
        }
        else{
          s.push(mp21[arr[i]]);
        }
    }

    printf("%ld\n", s.size());
    /* 전깃줄1565문제에선 사용x
    while(!s. empty()){
      printf("%d\n", s.top());
      s.pop();
    }
    */

    return 0;
}
