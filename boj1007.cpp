#include<iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int ch[22];
int n;
pair<int, int> s;
double ans;
int cnt;
double Min = 9999999999;

double cal(vector< pair<int, int> >vec){
  s.first = s.second = 0;
  for(int i=0; i<n; i++){
    if(ch[i]){
      s.first += vec[i].first;
      s.second += vec[i].second;
    }
    else{
      s.first -= vec[i].first;
      s.second -= vec[i].second;
    }
  }
  ans = sqrt((double)s.first*s.first + (double)s.second*s.second);
  return ans;

}

double dfs(int index, int a, vector< pair<int, int> > vec) {
  if(index >= n)return Min;
  if (a == n/2){

    return cal(vec);
  }


  for (int i = index; i < n; i++) {
    ch[i]=1;

    Min = min(Min, dfs(i+1, a+1, vec));

    //printf("%lf\n", Min);
    ch[i]=0;
  }

  return Min;
}

void solve() {
  Min = 9999999999;

  scanf("%d", &n);
  vector< pair<int, int> > vec(n);
  memset(ch, 0, sizeof(int)*22);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &vec[i].first, &vec[i].second);
  }

  printf("%0.12lf\n", dfs(0, 0, vec));

}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
