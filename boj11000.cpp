#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

struct ti{
  int start;
  int end;
};

bool cmp(ti a, ti b){
  if(a.start != b.start) return a.start < b.start;
  else return a.end < b.end;
};

struct cmpq{
  bool operator()(int a, int b){
    return a > b;
  }

};

priority_queue<int, vector<int>, cmpq> ep;



int main(){
  int n;
  scanf("%d", &n);
  vector<ti> arr(n);
  for(int i=0; i<n; i++){
    scanf("%d %d", &arr[i].start, &arr[i].end);
  }

  sort(arr.begin(), arr.end(), cmp);


  int cnt = 1;
  ep.push(arr[0].end);

  for(int i=1; i<n; i++){
    if(ep.top() <= arr[i].start){
      ep.pop();
      ep.push(arr[i].end);
    }
    else{
      cnt++;
      ep.push(arr[i].end);
    }
  }
  printf("%d", cnt);

  return 0;
}
