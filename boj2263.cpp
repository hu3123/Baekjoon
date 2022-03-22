#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<map>
using namespace std;


int pti[100001]; //post to in array

int post[100001];
//map<int, int> tree;

vector<int> pre;

int n;
int ch[100001];
int cnt;

void f(int root, int t, int rc){
    ch[root]=1;
    //printf("%d %d %d\n", post[root], t, rc);



    int value=post[root];
    int i=pti[value]-rc;
    pre.push_back(value);
    //tree.insert({t, value});

    if(i > 1 && i <= n && !ch[i-1]){
        f(i-1, t*2, rc);

    }


    if( root > 1 && !ch[root-1]){
        f(root-1, t*2+1, rc+1);
    }

    return;

}

/*
void preorder(int root){

    pre.push_back(tree[root]);

    if(tree.find(root*2) != tree.end()){
        preorder(root*2);
    }
    if(tree.find(root*2+1) != tree.end()){
        preorder(root*2+1);
    }

}
*/

int main() {

    scanf("%d", &n);
    int tmp;
    for(int i=1; i<=n; i++){
        scanf("%d", &tmp);
        pti[tmp]=i;
    }

    for(int i=1; i<=n; i++){
        scanf("%d", &post[i]);
    }

    f(n, 1, 0);

    for(int i=0; i<n; i++){
        printf("%d ", pre[i]);
    }

    return 0;
}
