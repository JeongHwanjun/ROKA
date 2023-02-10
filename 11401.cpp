/*
baekjoon #11401
2022.10.02
*/
#include <cstdio>
#define P 1000000007

using namespace std;

long long int fact[4000001]={1,1};

long long int pow(long long int n, long long int m)
{
    long long int out=1;
    while(m>0){
        if(m%2){
            m--;
            out=(out*n)%P;
        }
        else{
            m/=2;
            n*=n;
            n%=P;
        }
    }
    return out;
}

int main()
{
    long long int n,k;
    for(int i=2;i<4000001;i++){
        fact[i]=(fact[i-1]*i)%P;
    }
    scanf("%lld %lld",&n,&k);

    printf("%lld",(fact[n]*pow((fact[k]*fact[n-k])%P,P-2))%P);

    return 0;
}
