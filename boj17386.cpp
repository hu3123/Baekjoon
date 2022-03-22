#include<stdio.h>
#include<math.h>
#include<iostream>

using namespace std;



int ccw(pair<long long,long long> a, pair<long long, long long> b, pair<long long, long long> c){
  long long op = (long long)(a.first * b.second + b.first * c.second + c.first * a.second);

  op -= (long long)(a.second * b.first + b.second * c.first + c.second * a.first);

  if(op > 0) return 1;
  if(op == 0) return 0;
  else return -1;
}

int main(){

  pair<long long, long long> l1[2];
  pair<long long, long long> l2[2];

  scanf("%lld %lld %lld %lld", &l1[0].first, &l1[0].second, &l1[1].first, &l1[1].second);
  scanf("%lld %lld %lld %lld", &l2[0].first, &l2[0].second, &l2[1].first, &l2[1].second);

  int c1 = ccw(l1[0], l1[1], l2[0]);
  int c2 = ccw(l1[0], l1[1], l2[1]);
  int c3, c4;
  if(c1*c2 <0){
    c3 = ccw(l2[0], l2[1], l1[0]);
    c4 = ccw(l2[0], l2[1], l1[1]);
    if(c3*c4 < 0){
      printf("1");
      return 0;
    }
  }
  //printf("%d %d %d %d\n", c1, c2, c3, c4);
  printf("0");

  return 0;
}
