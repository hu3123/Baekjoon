#include<cstdio>
#include<queue>

using namespace std;

deque< pair<long long, long long> >dqmax;
deque< pair<long long, long long> >dqmin;

int main(){
  long long n, m;
  scanf("%lld %lld",&n, &m);
  long long l=-1;
  long long max = 0;
  int c=0;

  for(int i=0; i<m; i++){
    c=1;
    long long curr;
    scanf("%lld", &curr);
    if(!dqmax.empty()){

      while(!dqmax.empty() && dqmax.back().first <= curr){
        dqmax.pop_back();
      }
    }

    if(!dqmin.empty()){

      while(!dqmin.empty() && dqmin.back().first >= curr){
        dqmin.pop_back();
      }
    }
    dqmax.push_back( make_pair(curr, i) );
    dqmin.push_back( make_pair(curr, i) );

    while(!dqmin.empty() && dqmax.front().first - dqmin.front().first > n){
      if(dqmax.front().second > dqmin.front().second){
        //if(l < dqmin.front().second){
           l = dqmin.front().second;
         //}
         dqmin.pop_front();
      }
      else{
       //if(l < dqmax.front().second){
          l = dqmax.front().second;
        //}
        dqmax.pop_front();
      }
    }

    if(max < i - l) max = i - l;


    //printf("%lld %lld\n",i,  max);
  }

printf("%lld", max);





  return 0;
}
