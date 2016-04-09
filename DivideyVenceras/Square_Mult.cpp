#include <iostream>
using namespace std;

void SQUARE_MATRIX_MULTIPLSQUARE_MATRIX_MULTIPL(int A[3][3], int B[3][3])
{
    int n = sizeof(A)-1;
    int C[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            C[i][j]=0;
            for(int k=0;k<n;k++)
            {
                C[i][j]=C[i][j]+A[i][k]*B[k][j];
            }

        }
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<C[i][j];
        }
        cout<<endl;
    }

}



int main()
{
     int A[3][3] = {{2,0,1},{3,0,0},{5,1,1}};
     int B[3][3] = {{1,0,1},{1,2,1},{1,1,0}};
     SQUARE_MATRIX_MULTIPLSQUARE_MATRIX_MULTIPL(A, B);
     return 0;
}
