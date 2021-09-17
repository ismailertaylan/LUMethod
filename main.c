#include <stdio.h>
#include <stdlib.h>
#define SIZE 3
int main()
{
    //Our Equation:
    //2x1+2x2+2x3=12
    //4x1+7x2+7x3=24
    //6x1+18x2+22x3=12
    float A[SIZE][SIZE]= {0},L[SIZE][SIZE]= {0}, U[SIZE][SIZE];
    float C[SIZE]= {0}, X[SIZE]= {0},Y[SIZE]= {0};
    int i,j,k,n=SIZE;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("Please enter [%d][%d] element of matrix: ", (i+1),(j+1));
            scanf("%f",&A[i][j]);
        }
    }
    printf("\nPlease enter the constant terms of equations: \n");
    for(i=0; i<n; i++)
    {
        printf("C[%d]:",i);
        scanf("%f",&C[i]);
    }
    for(j=0; j<n; j++)
    {
        for(i=0; i<n; i++)
        {
            if(i<=j)
            {
                U[i][j]=A[i][j];
                for(k=0; k<=i-1; k++)
                    U[i][j]-=L[i][k]*U[k][j];
                if(i==j)
                    L[i][j]=1;
                else
                    L[i][j]=0;
            }
            else
            {
                L[i][j]=A[i][j];
                for(k=0; k<=j-1; k++)
                    L[i][j]-=(L[i][k]*U[k][j]);
                L[i][j]/=U[j][j];
                U[i][j]=0;
            }
        }
    }
    printf("[L]: \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%9.3f",L[i][j]);
        printf("\n");
    }
    printf("\n\n[U]: \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%9.3f",U[i][j]);
        printf("\n");
    }
    for(i=0; i<n; i++)
    {
        Y[i]=C[i];
        for(j=0; j<i; j++)
        {
            Y[i]-=L[i][j]*Y[j];
        }
    }
    printf("\n\n[Y]: \n");
    for(i=0; i<n; i++)
    {
        printf("%9.3f",Y[i]);
    }
    for(i=n-1; i>=0; i--)
    {
        X[i]= Y[i];
        for(j=i+1; j<n; j++)
        {
            X[i]-=U[i][j]*X[j];
        }
        X[i]/=U[i][i];
    }
    printf("\n\nThe solution [X] is: \n");
    for(i=0; i<n; i++)
    {
        printf("%9.3f",X[i]);
    }
    return 0;
}
