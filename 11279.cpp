/*
baekjoon #11279 https://www.acmicpc.net/problem/11279
2022.08.18
2022.08.20
*/

#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n,x;
    int size=0;
    int heap[100010]={0};

    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        if(x){
            //삽입
            heap[++size]=x;
            //정렬
            int cur=size;
            while(cur>1){
                if(heap[cur]>heap[cur/2]){
                    int tmp=heap[cur];
                    heap[cur]=heap[cur/2];
                    heap[cur/2]=tmp;
                }
                cur/=2;
            }
        }
        else{
            //출력
            if(size){
                printf("%d\n",heap[1]);
                heap[1]=heap[size];
                heap[size--]=0;
                //정렬
                int cur=1;
                while(cur*2<=size){
                    if(heap[cur]<heap[cur*2] || heap[cur]<heap[cur*2+1]){
                        int tmp;
                        if(heap[cur*2]>heap[cur*2+1]){
                            tmp=heap[cur*2];
                            heap[cur*2]=heap[cur];
                            heap[cur]=tmp;
                            cur*=2;
                        }
                        else{
                            tmp=heap[cur*2+1];
                            heap[cur*2+1]=heap[cur];
                            heap[cur]=tmp;
                            cur=cur*2+1;
                        }
                    }
                    else break;
                }
            }
            else printf("0\n");
        }
        
    }

    return 0;
}