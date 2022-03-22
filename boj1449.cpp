#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
  int n, length;

  scanf("%d %d", &n, &length);

  int rl = length - 1;
  int st;

  vector<int> vec(n);


  for(int i=0; i<n; i++){
    scanf("%d", &vec[i]);
  }

  sort(vec.begin(), vec.end());

  int cnt=0;

  st=0;
  for(int i=1; i<n; i++){
    if(vec[i] - vec[st] > rl){
      //printf("UP");
      st = i;
      cnt++;
    }
    if(i==n-1){
      //printf("DOWN");
      cnt++;
    }
  }

  if(n==1) cnt++;

  printf("%d", cnt);



  return 0;
}
