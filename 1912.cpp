/*
 * baekjoon #1912 https://www.acmicpc.net/problem/1912
 * 2023.05.20
*/
#include <cstdio>

int main()
{
    int ary[100001]={0};
    int f[100001]={0};
    int n,M=-21000000;

    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&ary[i]);
        f[i]=f[i-1]+ary[i]>ary[i] ? f[i-1]+ary[i]:ary[i];
        M=f[i]>M ? f[i]:M;
    }

    printf("%d",M);

    return 0;
}
