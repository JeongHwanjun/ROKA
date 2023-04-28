/*
baekjoon #11659 https://www.acmicpc.net/problem/11659
2023.04.28
*/

#include <cstdio>
#include <cstdlib>

int main()
{
    int *ary;
    int n,m,front,rear;
    int tmp;

    scanf("%d %d",&n,&m);

    ary=(int*)malloc(sizeof(int)*(n+1));
    ary[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&tmp);
        ary[i]=ary[i-1]+tmp;
    }

    for(int i=0;i<m;i++){
        scanf("%d %d",&front,&rear);
        printf("%d\n",ary[rear]-ary[front-1]);
    }

    free(ary);

    return 0;
}