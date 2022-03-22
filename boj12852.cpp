#include<stdio.h>
#include<queue>

using namespace std;

int ch=0;
int n;

void f(int a, int depth){
  if(ch==1)return;
  if(a == n){
    ch=1;
    printf("%d", depth);
    return;
  }
  if(a % 3==0){
    f(a/3, depth+1);
  }
  if(a % 2==0){
    f(a/2, depth+1);
  }
  f(a-1, depth+1);

}

int main(){


  scanf("%d", &n);
  f(n, 0);



  return 0;
}
