#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

struct ti{
  int start;
  int end;
};

bool cmp(ti a, ti b){
  if(a.end != b.end) return a.end < b.end;
  else return a.start < b.start;
};
int main(){
  int n;
  scanf("%d", &n);
  vector<ti> arr(n);
  for(int i=0; i<n; i++){
    scanf("%d %d", &arr[i].start, &arr[i].end);
  }

  sort(arr.begin(), arr.end(), cmp);

  int ep = -1;
  int cnt = 0;

  for(int i=0; i<n; i++){
    if(ep <= arr[i].start){
      ep = arr[i].end;
      cnt++;
    }
  }
  printf("%d", cnt);

  return 0;
}
