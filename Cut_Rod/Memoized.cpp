#include <iostream>
#include <math.h>
#include<time.h>
#include<algorithm>
using namespace std;

int Memoized_Cud_Rod_Aux(int *p,int n ,int *r)
{
    int q;
    if(r[n]>=0)
        return r[n];
    if(n==0)
        q=0;
    else
    {
        q=-999;
        for(int i=0;i<n;i++)
            q=fmax(q,p[i]+Memoized_Cud_Rod_Aux(p,n-(i+1),r));
    }
    r[n]=q;
    return q;


}
int Memoized_Cud_Rod(int*p,int n)
{
    int r[n+1];
    for(int i=0;i<=n;i++)
    {
        r[i]=-9999;
    }
    return Memoized_Cud_Rod_Aux(p,n,r);
}

int main()
{
    clock_t start, finish;
    float duration;
    int precicios[10]={1,5,8,9,10,17,17,20,24,30};
    start = clock();
    int Ingreso=Memoized_Cud_Rod(precicios,10);
    finish= clock();
    cout<<"Ingreso: "<<Ingreso<<endl;
    duration = (double)(finish - start )/CLK_TCK;
    cout << "Duracion: " << duration << endl;   //00


    return 0;
}
