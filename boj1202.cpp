/*
  가장 적은 무게를 담을 수 있는 바구니에 들어갈 수 있는것 중에 가장 가치가 큰것을 고른다
  귀류
  넣지 않고 그 다음 바구니에 들어간다면 그 다음 바구니에만 들어갈 수 있는 것이 못 들어갈 수도 있음

  되게 단순한 문제다.
  이 정도는 생각해내야한다 선후야..
*/



#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

/*
struct compare{
  bool operator()(pair<int, int> a, pair<int, int> b){

    if(a.second != b.second) return a.second < b.second;
    else return a.first > b.first;
  }

};
*/




bool cmp(pair<int, int> a, pair<int, int> b){
  if(a.first != b.first) return a.first < b.first;
  return a.second > b.second;
}

//priority_queue< pair<int,int> , vector< pair<int, int> >, compare> q;
priority_queue<int> q;
int bag[300001];


int main(){
  int n, k;
  long sv=0;
  scanf("%d %d", &n, &k);
  vector< pair<int, int> > v(n);
  for(int i=0; i<n; i++){
    int f, s;
    scanf("%d %d", &v[i].first, &v[i].second);


  }
  for(int i=0; i<k; i++){
    scanf("%d", &bag[i]);
  }

  sort(v.begin(), v.end(), cmp);
  sort(bag, bag+k);

  int j=0;
  for(int i=0; i<k; i++){

    while(v[j].first <= bag[i] && j<n){
      //printf("%d\n", v[j].first);
      q.push(v[j].second);
      j++;
    }
    if(!q.empty()){
      sv+=q.top();
      q.pop();
    }
  }
  printf("%ld", sv);



  return 0;
}
