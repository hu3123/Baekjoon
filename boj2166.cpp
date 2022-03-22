#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<iostream>
#include<vector>

using namespace std;

vector< pair<long, long> > dot;

long long crosscon(int fd, int sd){
  long long ans = dot[0].first * dot[fd].second + dot[fd].first * dot[sd].second + dot[sd].first * dot[0].second;
  ans -= dot[0].second * dot[fd].first + dot[fd].second * dot[sd].first + dot[sd].second * dot[0].first;
  return ans;

}

int main(){
  int n;
  long long sum=0;
  scanf("%d",&n);
  for(int i=0; i<n; i++){
    long  tmp1, tmp2;
    scanf("%ld %ld", &tmp1, &tmp2);
    dot.push_back( make_pair(tmp1, tmp2) );
  }
  for(int i=1; i<n-1; i++){
    sum += crosscon(i, i+1);
  }
  double ans = (double)(abs(sum)) / 2;
  printf("%0.1lf", ans);


  return 0;
}
