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
  long long sum=0;
  for(int i=2; i<=n; i++){
    sum += phi(i);
  }

  printf("%lld", sum);
  return 0;
}
