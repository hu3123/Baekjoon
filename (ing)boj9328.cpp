#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<stack>
#include<vector>

using namespace std;

char matrix[101][101];
long long bit;

stack<int> s;
bool visited[101][101];
bool m[101][101][26];
bool kd[26][26];



void bfs(int y, int x, int h, int w){

  visited[y][x] = 1;
  if(matrix[y][x] >=97){
    m[y][x]
  }
  else if(matrix[y][x] != '.'){
    s.push(matrix[y][x]-65);
  }



  if(0 <= y+1 && y+1 < h && 0 <= x && x < w && matrix[y+1][x] != '*'){
    bfs(y+1, x, h, w);
  }
  if(0 <= y-1 && y-1 < h && 0 <= x && x < w && matrix[y-1][x] != '*'){
    bfs(y-1, x, h, w);
  }
  if(0 <= y && y < h && 0 <= x+1 && x+1 < w && matrix[y][x+1] != '*'){
    bfs(y, x+1, h, w);
  }
  if(0 <= y && y < h && 0 <= x-1 && x-1 < w && matrix[y][x-1] != '*'){
    bfs(y, x-1, h, w);
  }


  visited[y][x] = 0;

}


int main(){
  int n;
  scanf("%d", &n);

  for(int i=0; i<n; i++){
    int h, w;
    scanf("%d %d", &h, &w)
    for(int j=0; j<h; j++){
      for(int k=0; k<w; k++){
        scanf(" %c", matrix[j][k]);
      }
    }
    char a[101];
    scanf("%s", a);
    if(a[0] == '0'){
      for(int j=0; j<strlen(a); j++){
        bit = bit | (1<<(a[j]-65));
      }
    }
    for(int j=0; j<h; j++){
      if(matrix[j][0] != '*'){
        bfs(j, 0, h , w);
      }
      if(matrix[j][w-1] != '*'){
        bfs(j, w-1, h , w);

      }
    }
    for(int j=0; j<w; j++){
      if(matrix[0][j] != '*'){
        bfs(0, j, h , w);

      }
      if(matrix[h-1][j] != '*'){
        bfs(h-1, j, h , w);

      }
    }
    memset(matrix, 0, sizeof(matrix));
  }


  return 0;
}
