/*

*/

#include<stdio.h>
#include<algorithm>
#include<cstring>

using namespace std;

int arr[100001];

int find(int curr){
  if(arr[curr]<0) return curr;
  return arr[curr] = find(arr[curr]);
}

int main(){
  int g;
  int cnt=0;
  scanf("%d", &g);
  int p;
  scanf("%d", &p);
  memset(arr, -1, sizeof(arr));
  int i;
  for(i=0; i<p; i++){
    int a;
    scanf("%d", &a);
    int tmp = find(a);
    if(tmp == 0){
      break;
    }
    arr[tmp] = tmp-1;

  }

  printf("%d", i);




  return 0;
}
