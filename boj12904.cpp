#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#define P pair<int, int>

using namespace std;

struct A{
  int d;
  int w;
  int ch;
};

bool cmp(A a,  A b){
  if(a.d != b.d) return a.d > b.d;
  return a.w > b.w;

}

int main(){
  int n;
  scanf("%d", &n);
  vector<A> arr(n);
  for(int i=0; i<n; i++){
    scanf("%d %d" , &arr[i].d, &arr[i].w);
  }
  sort(arr.begin(), arr.end(), cmp);

  int pos=0;
  //vector<int> ans;

  int sum=0;
  priority_queue<int> pq;
  for(int i=arr[0].d; i>0; i--){
    for(pos; arr[pos].d >= i; pos++){
      //printf("%d ", pos);
      pq.push(arr[pos].w);
    }
    //printf("%d\n", pq.empty());
    if(!pq.empty()){
      //printf("1");
      sum += pq.top();
      pq.pop();
    }

  }

  printf("%d", sum);



  return 0;
}
