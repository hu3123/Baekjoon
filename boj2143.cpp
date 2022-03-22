// 1번 배열 2번 배열 구간합 배열 비교하면서 ans값 맞춰가기
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stdlib.h>


using namespace std;

int cnt=0;

int main(){
  int n;
  scanf("%d", &n);

  int a, b;

  scanf("%d", &a);
  vector<long> psum1(a);
  vector<long> arr1;
  scanf("%ld", &psum1[0]);
  arr1.push_back(psum1[0]);
  for(int i=1; i<a; i++){
    long tmp;
    scanf("%ld", &tmp);
    psum1[i] = psum1[i-1] + tmp;
    arr1.push_back(psum1[i]);
  }

  for(int i=0; i<a; i++){
    for(int j=i+1; j<a; j++){
      arr1.push_back(psum1[j]-psum1[i]);
    }
  }


  scanf("%d", &b);
  vector<long> psum2(b);
  vector<long> arr2;
  scanf("%ld", &psum2[0]);
  arr2.push_back(psum2[0]);


  for(int i=1; i<b; i++){
    long tmp;
    scanf("%ld", &tmp);
    psum2[i] = psum2[i-1] + tmp;
    arr2.push_back(psum2[i]);
  }
  for(int i=0; i<b; i++){
    for(int j=i+1; j<b; j++){
      arr2.push_back(psum2[j]-psum2[i]);
    }
  }

  sort(arr1.begin(), arr1.end());
  sort(arr2.begin(), arr2.end());

  long l=arr1.size();

  //printf("\n");

  long sum=0;

  for(long i=0; i<l; i++){
    sum += upper_bound(arr2.begin(), arr2.end(), n-arr1[i]) - lower_bound(arr2.begin(), arr2.end(), n-arr1[i]);
    //printf("%ld %d\n", arr1[i], sum);
  }

  printf("%ld", sum);




  return 0;
}
