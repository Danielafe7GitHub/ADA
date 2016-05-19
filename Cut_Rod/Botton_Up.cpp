#include <iostream>
#include <math.h>
#include<time.h>
#include<algorithm>
using namespace std;

int Botton_Up_Cut_Rod(int *p, int n)
{
    int q;
    int r[n+1];
    r[0]=0;
    for(int j=0;j<n;j++)
    {
        q=-9999;
        for(int i=0;i<=j;i++)
        {
            q=fmax(q,p[i]+r[j-i]);
        }
        r[j+1]=q;
    }
    return r[n];
}







int main()
{
    clock_t start, finish;
    float duration;
    int precicios[10]={1,5,8,9,10,17,17,20,24,30};
    start = clock();
    int Ingreso=Botton_Up_Cut_Rod(precicios,10);
    finish= clock();
    cout<<"Ingreso: "<<Ingreso<<endl;
    duration = (double)(finish - start )/CLK_TCK;
    cout << "Duracion: " << duration << endl;   //1.459

    return 0;
}
