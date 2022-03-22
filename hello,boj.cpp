#include<stdio.h>

using namespace std;

long pow(int n, int p){
  long ans=1;
  for(int i=0; i<p; i++){
    ans*=n;
  }
  return ans;
}


int main(){
  int n,d;
  scanf("%d %d", &n, &d);
  long i;

int c=0;

  long l=pow(d, d);
  long ll = pow(d,d-1);
  for(i=n+1; i<=l; i++){
    long tmp=i;
    int ch[11]={0};
    if(i < ll){
      i = ll;
      continue;
    }
    while(tmp){
      if(ch[tmp%d]==1)break;
      ch[tmp%d]=1;
      tmp/=d;
    }
    if(tmp==0){
      c=1;
      printf("%ld", i);
      break;

    }
  }
  if(i==l+1 || c==0)printf("-1");





  return 0;
}
