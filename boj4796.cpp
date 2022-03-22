#include<stdio.h>
#include<algorithm>

using namespace std;

int main(){
  int l, p, v;
  int cnt=0;
  while(1){
    cnt++;
    scanf("%d %d %d", &l, &p, &v);
    if(l==0)break;
    int g = v / p;
    int ans = g * l;
    g = v % p;
    if(g > l){
      ans += l;
    }
    else{
      ans += g;
    }
    printf("Case %d: %d\n", cnt, ans);

  }

  return 0;
}
