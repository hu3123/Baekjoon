#include<stdio.h>
#include<algorithm>

using namespace std;

void solve(long long n){


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
  printf("%lld\n", ans);

  return;
}

int main(){
  while(1){
    long long tmp;
    scanf("%lld", &tmp);
    if(tmp == 0)break;
    solve(tmp);
  }

  return 0;
}
