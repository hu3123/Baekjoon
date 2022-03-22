#include<stdio.h>

using namespace std;

int main(){
  long long a, b;
  scanf("%lld %lld", &a, &b);
  long long cnt=0;
  for(long long i=2; i<=b*2; i*=2){
    cnt += ((b-(i-(i/2)-1))/i)*(i/2);
    if((b-(i-(i/2)-1))%i > i/2)cnt += i/2;
    else cnt += (b-(i-(i/2)-1))%i;
    //printf("%lld %lld\n", ((b-(i-(i/2)-1))/i), cnt);
  }
  a=a-1;
  for(long long i=2; i<=a*2; i*=2){
    cnt -= ((a-(i-(i/2)-1))/i)*(i/2);
    if((a-(i-(i/2)-1))%i > i/2)cnt -= i/2;
    else cnt -= (a-(i-(i/2)-1))%i;
    //printf("%lld\n", cnt);
  }
  printf("%lld", cnt);



  return 0;
}
