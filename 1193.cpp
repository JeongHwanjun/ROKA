/*
baekjoon #1193 https://www.acmicpc.net/problem/1193
2022.10.16
*/
#include <cstdio>

int main()
{
    int x,n=1,linestart=1;

    scanf("%d",&x);

    while(linestart+n<x){
        linestart+=n;
        n++;
    }

    int upper,under;
    if(n&1){
        upper=n-(x-linestart);
        under=1+(x-linestart);
    }
    else{
        upper=1+(x-linestart);
        under=n-(x-linestart);
    }
    
    printf("%d/%d",upper,under);

    return 0;
}