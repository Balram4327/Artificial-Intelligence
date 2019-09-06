#include<stdio.h>

int main()
{
    int n,i;
    int yj;
    float alp;

    printf("Enter the number of neurons. \n");
    scanf("%d",&n);

    printf("Enter the number of inputs. \n");
    scanf("%d",&i);

    printf("Enter the alpha value. \n");
    scanf("%f",&alp);

    float x[n][i];
    float Y[i];

    for(int j=0;j<i;j++)
        x[0][j] = 1; //bias input

    for(int k=0;k<i;k++)
    {
        for(int j=1;j<n;j++)
        {
            printf("Enter the %d th neural values of %d th input: ",j,k);
            scanf("%f",&x[j][k]);
        }
    }

    for(int j=0;j<i;j++)
    {
        printf("Enter the %d th expected output: ",j);
        scanf("%f",&Y[j]);
    }

    float w[n];

    for(int j=0;j<n;j++)
    {
        printf("Enter the %d th weight value: ",j);
        scanf("%f",&w[j]);
    }

    float netj;

    for(int k=0;k<i;k++)
    {
        //printf("Y value: %f \n",Y[k]);
        netj = 0;
        for(int j=0;j<n;j++)
        {
            netj = netj + x[j][k]*w[i];

            printf("NetJ value: %f %d %d \n",netj,k,j);
                
        }
        yj = (netj > 0)? 1 : 0;
        printf("Yj value: %f Y value: %f \n",yj,Y[k]);
    }

    for(int k=0;k<i;k++)
    {
        for(int j=0;j<n;j++)
        {
            if(yj==1&&Y[k]==0)
            w[j] = w[j] - alp*x[j][k];
            else if(yj==0&&Y[k]==1)
            w[j] = w[j] + alp*x[j][k];
        }
    }
}