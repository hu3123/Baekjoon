#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

int n;
int map[300][300]={0};
int cnt;

void find_queen(int depth){
  if(depth==n){
    //printf("%d", n);
    cnt++;
    return;
  }


  for(int i=0; i<n; i++){

    if(map[depth][i]==0){
      for(int j=0; j<n; j++){
        map[j][i]++;
      }
      if(depth < i){
        for(int j=0; j<n-i+depth; j++){
          map[j][j+i-depth]++;
        }
      }
      else{
        for(int j=0; j<n-depth+i; j++){
          map[j+depth-i][j]++;
        }
      }
      int tmp=depth+i;
      if(depth+i < n){
        for(int j=0; j<=tmp; j++){
          map[j][tmp-j]++;
        }
      }
      else{
        for(int j=depth; j<=tmp; j++){
          map[j][tmp-j]++;
        }
      }
      find_queen(depth+1);
      for(int j=0; j<n; j++){
        map[j][i]--;
      }
      if(depth < i){
        for(int j=0; j<n-i+depth; j++){
          map[j][j+i-depth]--;
        }
      }
      else{
        for(int j=0; j<n-depth+i; j++){
          map[j+depth-i][j]--;
        }
      }
      if(depth+i < n){
        for(int j=0; j<=tmp; j++){
          map[j][tmp-j]--;
        }
      }
      else{
        for(int j=depth; j<=tmp; j++){
          map[j][tmp-j]--;
        }
      }
    }

  }
  return;
}


int main(){

  scanf("%d", &n);

  find_queen(0);

  printf("%d", cnt);


  return 0;
}
