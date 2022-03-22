#include<stdio.h>

using namespace std;

int main(){
  int n;
  scanf("%d", &n);
  if((n%4)%2==0){
    printf("CY");
  }
  else{
    printf("SK");
  }



  return 0;
}
