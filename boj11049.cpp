/*
분할정복 이용
일정부분씩 어떻게 나누어도 각 부분의 결과들이 다시 행렬곱셈 가능

선형 탐색 불가

순서가 선형으로 탐색이 불가는한 구조임


*/
//dp에는 일차원 선형구조만 있는게 아니다 명심하자 메모이제이션도 dp이다. 명심하자.

#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;




int mat[501][501][2]; //1:r 2:c;
long long dat[501][501];

int main(){
  int n;
  scanf("%d", &n);

  for(int i=0; i<n; i++){
    scanf("%d %d", &mat[i][i][0], &mat[i][i][1]);
  }


  for(int i=1; i<n; i++){
    for(int j=0; j<n-i; j++){
      long long min = (long long)2<<31;

      //mat[j][j+i]를 정하는 과정
      for(int k=0; k<i; k++){

        long long tmp = mat[j][j+k][0]*mat[j][j+k][1]*mat[j+1+k][j+i][1] + dat[j][j+k] + dat[j+1+k][j+i];

        if(min > tmp){
          min = tmp;
          mat[j][j+i][0] = mat[j][j][0];
          mat[j][j+i][1] = mat[j+i][j+i][1];
        }
      }
      //printf("%d %d\n", j, j+i);

      dat[j][j+i] = min;
    }
  }


  /*
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      printf("%3d/%3d/%3lld \t", mat[i][j][0], mat[i][j][1], dat[i][j]);
    }
    printf("\n");
  }
  */

  printf("%lld", dat[0][n-1]);


  return 0;
}
