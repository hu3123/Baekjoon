#include<stdio.h>
#include<algorithm>
#include<math.h>

using namespace std;

long long phi(long long n){


  long long ans=n;
  long long p=2;
  while(p*p <= n){
    if(n%p == 0){
      ans /= p;
      ans *= p-1;
    }
    while(n % p == 0){
      n /= p;
    }
    p++;
  }
  if(n!=1){
    ans /= n;
    ans *= n-1;
  }
  //printf("%lld\n", ans);

  return ans;
}

int main(){
  int n;
  scanf("%d", &n);
  int i;

  for(i=sqrt(n)+1; i>0; i--){
    //printf("%d", i * phi(i));
    if(n%i==0){
      if(phi(n/i) == i){
        printf("%d", n/i);
        break;
      }
    }
  }

  if(i <= 0){
    printf("-1");
  }

  return 0;
}
