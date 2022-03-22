#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

long long p(int num, int po){
  long long n=1;
  for(int i=0; i<po; i++){
    n *= num;
  }
  return n;
}

int main(){
  int l, w, h;
  int n;
  scanf("%d %d %d", &l, &w, &h);
  scanf("%d", &n);
  vector< pair<int, int> > arr(n);
  for(int i=0; i<n; i++){
    scanf("%d %d", &arr[i].first, &arr[i].second);
  }

  unsigned long long bef = 0;
  long long i;
  long long cnt=0;
  for(i=n-1; i>=0; i--){
    long long num = p(2, arr[i].first);
    long long ll = l/num;
    long long ww = w/num;
    long long hh = h/num;
    long long size = ll*ww*hh;


    if(i!=n-1){
      long k=p(2, arr[i+1].first - arr[i].first);
      bef *= k*k*k;

    }
    //printf("%d %d\n", size, bef);
    size -= bef;
    if(size - arr[i].second >= 0){
      //printf("%d\n", arr[i].second);
      bef += arr[i].second;
      cnt += arr[i].second;
    }
    else {
      //printf("%d %d\n", arr[i].second, size);
      bef += size;
      cnt += size;
    }
  }

  if(l*w*h == bef) printf("%lld", cnt);
  else{
    printf("-1");
  }


  return 0;
}
