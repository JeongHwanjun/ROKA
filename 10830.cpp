/*
baekjoon 10830
2022.12.16
2022.12.27
*/
#include <cstdio>
#define P 1000

void product();
void mass_production(long long int y);

int matrix[6][6];
int n;
long long int b;

int main()
{
    scanf("%d %lld",&n,&b);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&matrix[i][j]);
        }
    }

    mass_production(b);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",matrix[i][j]%P);
        }
        printf("\n");
    }
}

void product()
{
    int sol_matrix[6][6]={0};
    
    int sum=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sum=0;
            for(int k=0;k<n;k++){
                sum+=(matrix[i][k]*matrix[k][j])%P;
            }
            sol_matrix[i][j]=sum%P;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
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
        int tmp_matrix[6][6], sol_matrix[6][6]={0};
        for(int i=0;i<n;i++){ //현재 matrix를 임시로 보관
            for(int j=0;j<n;j++){
                tmp_matrix[i][j]=matrix[i][j];
            }
        }
        mass_production((y-1)/2); //짝수로 만들어 반갈 후 제곱
        product();

        //저장해놨던 임시 matrix를 곱해 홀수일때 결과 도출
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int sum=0;
                for(int k=0;k<n;k++){
                    sum+=(matrix[i][k]*tmp_matrix[k][j])%P;
                }
                sol_matrix[i][j]=sum%P;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]=sol_matrix[i][j];
            }
        }
    }
}