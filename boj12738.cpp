#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>

using namespace std;

vector<int> ans;

void binary_search(int tar) {
    int lo;
    vector<int>::iterator itr = lower_bound(ans.begin(), ans.end(), tar);
    int pos = itr - ans.begin();
    //printf("%d\n", pos);
    if (pos == ans.size()) {
        ans.push_back(tar);
    }
    else {
        ans[pos] = tar;
    }
    return;
}



int main() {
    int n;

    scanf("%d", &n);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (ans.size()) {
            binary_search(arr[i]);
        }
        else {
            ans.push_back(arr[i]);
        }
    }

    printf("%d", ans.size());

    return 0;
}
