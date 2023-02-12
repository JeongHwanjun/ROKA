/*
baekjoon #1002 https://www.acmicpc.net/problem/1002
2020.11.06
*/
#include <cstdio>

using namespace std;

int sqr(int a);

int main()
{
    int AB,rA,rB;
    int xA,yA,xB,yB;
    int rP,rN;
    int T;
    scanf("%d",&T);

    while(T--){
        scanf("%d %d %d %d %d %d",&xA,&yA,&rA,&xB,&yB,&rB);

        //모든 계산은 편의상 제곱으로 한다.
        AB=sqr(xA-xB)+sqr(yA-yB);
        rP=sqr(rA+rB);
        rN=sqr(rA-rB);

        if(xA==xB && yA==yB){ //원의 중심이 같을 경우
            if(rA==rB) printf("-1");
            else printf("0");
        }
        else if(AB>rP) printf("0");
        else if(AB<rN) printf("0");
        else if(AB==rP) printf("1");
        else if(AB==rN) printf("1");
        else/* if(AB<rA+rB)*/ printf("2");

        printf("\n");
    }

    return 0;
}

int sqr(int a) {return a*a;}