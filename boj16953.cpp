#include<stdio.h>

using namespace std;

int ch=0;

void find(int now, int tar, int cnt){
  if(now < tar){
    return;
  }
  if(now == tar){
    printf("%d", cnt);
    ch=1;
    return;
  }
  if(now%10==1){
    find(now/10, tar, cnt+1);
  }
  if(now%2==0){
    find(now/2, tar, cnt+1);
  }


}

int main(){
  int start, end;

  scanf("%d %d", &start, &end);

  find(end, start, 1);

  if(ch==0){
    printf("-1");
  }



  return 0;
}
