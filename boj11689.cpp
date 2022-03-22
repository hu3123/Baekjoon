#include<stdio.h>
#include<algorithm>

using namespace std;

int main(){
  long long n;
  scanf("%lld", &n);
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
  printf("%lld", ans);


  return 0;
}
