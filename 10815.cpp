/*
baekjoon #10815
2022.10.23
*/
#include <cstdio>
#include <algorithm>

int main()
{
    int card[500000]={0};
    int n,m;
    
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&card[i]);
    }

    std::sort(card,card+n);

    scanf("%d",&m);

    for(int i=0;i<m;i++){
        int x;
        scanf("%d",&x);
        int front=0,rear=n,mid;
        bool isOut=false;
        while(front<=rear){
            mid=(front+rear)/2;
            if(card[mid]>x) rear=mid-1;
            else if(card[mid]<x) front=mid+1;
            else{
                printf("1 ");
                isOut=true;
                break;
            }
        }
        if(!isOut) printf("0 ");
    }

    return 0;
}