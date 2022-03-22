
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;


bool cmp(pair<int, int> a, pair<int, int> b){
  return a.first < b.first;
  return a.second < b.second;
}

priority_queue<int> q;

int main(){
  int n;
  long sv=0;
  scanf("%d", &n);
  vector< pair<int,int> > v(n);
  for(int i=0; i<n; i++){
    scanf("%d %d", &v[i].first, &v[i].second);
  }
  int j=n-1;

  sort(v.begin(), v.end(), cmp);

  for(int i=v[n-1].first; i>0; i--){
    while(j >= 0 && v[j].first >= i){
      q.push(v[j].second);
      j--;
    }
    if(!q.empty()){
      //printf("%d\n", q.top());
      sv += q.top();
      q.pop();
    }
  }
  printf("%ld", sv);


  return 0;
}
