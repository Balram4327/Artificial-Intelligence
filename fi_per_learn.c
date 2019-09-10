#include<stdio.h>

int main()
{
    int n,i;
    float alp;

    printf("Enter the number of neurons. \n");
    scanf("%d",&n);

    printf("Enter the number of inputs. \n");
    scanf("%d",&i);

    printf("Enter the alpha value. \n");
    scanf("%f",&alp);

    float x[n][i];
    float Y[i];
    float yj[i];

    for(int j=0;j<i;j++)
        x[0][j] = 1; //bias input

    /*for(int k=0;k<i;k++)
    {
        for(int j=1;j<n;j++)
        {
            printf("Enter the %d th neural values of %d th input: ",j,k);
            scanf("%f",&x[j][k]);
        }
    } */


//Hardcoded Values
    x[1][0] = 0.25;
    x[2][0] = 0.358;
    x[1][1] = 0.25;
    x[2][1] = 0.471;
    x[1][2] = 0.5;
    x[2][2] = 0.353;
    x[1][3] = 0.5;
    x[2][3] = 0.647;
    x[1][4] = 0.75;
    x[2][4] = 0.765;
    x[1][5] = 0.75;
    x[2][5] = 0.882;
    x[1][6] = 1;
    x[2][6] = 0.705;
    x[1][7] = 1;
    x[2][7] = 1;


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
    int flag = 0;
    int count =0;

    while(flag==0)
    {
    for(int k=0;k<i;k++)
    {
        //printf("Y value: %f \n",Y[k]);
        
        for(int j=-1;j<n;j++)
        {
            if(j==-1)
            netj=0;
            
            else
            netj = netj + (x[j][k]*w[j]);

        //    printf("NetJ value: %f\n",netj);      
        }
        yj[k] = (netj > 0)? 1 : 0;
        // printf("Yj value: %f Y value: %f \n",yj[k],Y[k]);

        if(yj[k]==1&&Y[k]==0)
        {
            for(int j=0;j<n;j++)
                {
                    w[j] = w[j] - alp*x[j][k];
                }
        }

        else if(yj[k]==0&&Y[k]==1)
        {
        for(int j=0;j<n;j++)
                {
                    w[j] = w[j] + alp*x[j][k];
                }
        }
    }

    flag=-1;
    for(int p=0;p<i;p++)
    {
        if(yj[p]!=Y[p])
        flag = 0;    
    }

    count++;
    }

    printf("Number of iterations: %d \n",count);

 for(int l=0;l<n;l++)
    {
        printf("W: %f \n",w[l]);
    }

    for(int l=0;l<i;l++)
    {
        printf("yj: %f Y: %f \n", yj[l],Y[l]);
    }
}