#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>

#define n 10

using namespace std;

priority_queue< pair<int, int> > q;



char a[12][12];

int find

int main(){
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      scanf("%c ", &a[i][j]);
    }
  }

  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      find(i, j);
    }
  }




  return 0;
}
