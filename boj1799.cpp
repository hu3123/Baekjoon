#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<cstring>

using namespace std;

//int ch[12][12];
int map[12][12];
int n;
int Max=-99;


void fill(int y, int x){
  int s = y+x;
  for(int i=0; i<=s; i++){
    map[i][s-i]++;
  }
  if(y>x){
    int d = y-x;
    for(int i=d; i<=n; i++){
      map[i][i-d]++;
    }
  }
  else{
    int d = x-y;
    for(int i=d; i<=n; i++){
      map[i-d][i]++;
    }
  }

}

void ext(int y, int x){
  int s = y+x;
  for(int i=0; i<=s; i++){
    map[i][s-i]--;
  }
  if(y>x){
    int d = y-x;
    for(int i=d; i<=n; i++){
      map[i][i-d]--;
    }
  }
  else{
    int d = x-y;
    for(int i=d; i<=s; i++){
      map[i-d][i]--;
    }
  }
}




void dfs(int y, int x, int cnt){



  fill(y, x);

  if(cnt > Max){

    Max = cnt;
  }


  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(map[i][j]==0){

        dfs(i, j, cnt+1);

      }
    }
  }
  ext(y, x);


  return;
}



int main(){
  scanf("%d", &n);
  memset(map, 1, sizeof(map));
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      int tmp;
      scanf("%d", &tmp);
      map[i][j] = abs(tmp-1);
    }
  }

  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(map[i][j] == 0){
        dfs(i, j, 1);
        map[i][j] = 1;
      }

    }
  }

  printf("%d", Max);

  return 0;
}
