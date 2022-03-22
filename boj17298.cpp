#include<stdio.h>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

int main(){

  int n;
  scanf("%d", &n);

  stack<int> in;
  stack<int> big;
  vector<int> ans;


  for(int i=0; i<n; i++){
    int tmp;
    scanf("%d", &tmp);
    in.push(tmp);
  }


  for(int i=0; i<n; i++){
    int tmp=in.top();
    while(!big.empty()){
      if(big.top() > tmp){
        ans.push_back(big.top());
        big.push(tmp);
        break;
      }
      else{
        big.pop();
      }
    }
    if(big.empty()){
      ans.push_back(-1);
      big.push(tmp);
    }
    in.pop();
  }
  int length = ans.size();

  for(int i=length-1; i>=0; i--){
    printf("%d ", ans[i]);
  }

  return 0;
}
