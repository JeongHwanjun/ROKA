/*
 * baekjoon #11444
 * 2023.01.22
*/
#include <cstdio>
#define P 1000000007

void product();
void mass_production(long long int y);

long long int matrix[2][2]={1,1,1,0};
long long int n;

int main()
{
    scanf("%lld",&n);

    mass_production(n);

    printf("%d",matrix[0][1]);

    return 0;
}

void product()
{
    long long int sol_matrix[2][2]={0};

    long long int sum=0;

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            sum=0;
            for(int k=0;k<2;k++){
                sum+=(matrix[i][k]*matrix[k][j])%P;
            }
            sol_matrix[i][j]=sum%P;
        }
    }

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            matrix[i][j]=sol_matrix[i][j];
        }
    }
}

void mass_production(long long int y)
{
    if(y==1){
        //아무것도 안함.
    }
    else if(!(y%2)){ //반갈후 제곱
        mass_production(y/2);
        product();
    }
    else if(y%2){
        long long int tmp_matrix[2][2], sol_matrix[2][2]={0};
        for(int i=0;i<2;i++){ //현재 matrix를 임시로 보관
            for(int j=0;j<2;j++){
                tmp_matrix[i][j]=matrix[i][j];
            }
        }
        mass_production((y-1)/2); //짝수로 만들어 반갈 후 제곱
        product();

        //저장해놨던 임시 matrix를 곱해 홀수일때 결과 도출
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                long long int sum=0;
                for(int k=0;k<2;k++){
                    sum+=(matrix[i][k]*tmp_matrix[k][j])%P;
                }
                sol_matrix[i][j]=sum%P;
            }
        }

        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                matrix[i][j]=sol_matrix[i][j];
            }
        }
    }
}
