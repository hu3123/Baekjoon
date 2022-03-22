#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>


using namespace std;

char map[752][752];

short lh[752][752];

short rh[752][752];//lh값, rh값


int main(){
  int r, c;
  scanf("%d %d", &r, &c);
  for(int i=1; i<=r; i++){
    for(int j=1; j<=c; j++){
      scanf(" %c", &map[i][j]);
    }
    //scanf("\n");
  }

  int Max = 0;

  for(int i=1; i<=r; i++){

    for(int j=1; j<=c; j++){

      if(map[i][j] == '1'){
        lh[i][j] = lh[i-1][j-1] + 1;
        rh[i][j] = rh[i-1][j+1] + 1;

        int t = min(lh[i][j], rh[i][j]);

        for(int k=t; k>Max; k--){
          if(lh[i-k+1][j+k-1] >= k && rh[i-k+1][j-k+1] >= k){
            //printf("%d %d %d\n", i, j, t);
            Max = k;
            break;
          }
        }

      }
    }
  }

  printf("%d", Max);


  return 0;
}
