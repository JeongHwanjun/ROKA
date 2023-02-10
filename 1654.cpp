/*
baekjoon #1654
2022.12.23
*/
#include <cstdio>
#include <climits>

int main()
{
    int k,n;
    long long int front=1,rear=-1,mid;
    long long int line[10001]={};
    long long int counter=0;
    long long int sol=INT_MIN;

    scanf("%d %d",&k,&n);

    for(int i=0;i<k;i++){
        //k개의 랜선 길이 입력
        scanf("%lld",&line[i]);
        rear=line[i]>rear ? line[i]:rear;
    }

    counter=0;
    while(rear>=front){
        mid=(front+rear)/2;
        for(int i=0;i<k;i++){
            counter+=line[i]/mid;
        }

        if(counter>=n){
            front=mid+1;
            sol=mid>sol ? mid:sol;
        }
        else rear=mid-1;
        counter=0;
    }

    printf("%lld\n",sol);

    return 0;
}