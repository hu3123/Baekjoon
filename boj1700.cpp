#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
  int n, m;
  scanf("%d %d", &m, &n);

  vector<int> vec[101];
  vector<int> arr(n);
  vector<int> ans(m);


  for(int i=0; i<n; i++){
    scanf("%d", &arr[i]);
    vec[arr[i]].push_back(i);
  }

  int cnt=0;
  int anscnt=0;

  for(int i=0; i<n; i++){
    if(cnt < m){
      int j;
      for(j=0; j<cnt; j++){
        if(ans[j] == arr[i]){
          break;
        }
      }
      if(j==cnt)
        ans[cnt++] = arr[i];
    }
    else{
      int j;
      for(j=0; j<m; j++){
        if(ans[j] == arr[i]){
          break;
        }
      }
      if(j!=m) continue;


      int Max=-99;
      int maxpos;
      for(j=0; j<cnt; j++){
        int l=vec[ans[j]].size();
        int k;

        for(k=0; k<l; k++){
          if(vec[ans[j]][k] > i){
            if(vec[ans[j]][k] > Max){
              Max = vec[ans[j]][k];
              maxpos=j;
            }
            break;
          }
        }

        if(k == l){
          maxpos = j;
          break;

        }

      }
      //printf("%d", i);
      anscnt++;
      ans[maxpos] = arr[i];

    }
    int j;
    for(j=0; j<cnt; j++){
      //printf("%d ", ans[j]);
    }
    //printf("\n");
  }

  printf("%d", anscnt);


  return 0;
}
