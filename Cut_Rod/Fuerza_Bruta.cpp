#include <iostream>
#include <math.h>
#include<time.h>
#include<algorithm>
using namespace std;

int Cut_Rod(int *p, int n)
{
    if(n==0)
        return 0;
    int q=-3;
    for(int i=0;i<n;i++)
    {
        q=fmax(q,p[i]+Cut_Rod(p,n-(i+1)));



    }

    return q;
}


int main()
{
    clock_t start, finish;
    double duration;
    int precicios[10]={1,5,8,9,10,17,17,20,24,30};
    start = clock();
    int Ingreso=Cut_Rod(precicios,10);
    finish= clock();
    cout<<"Ingreso: "<<Ingreso<<endl;
    duration = (double)(finish - start )/CLOCKS_PER_SEC;
    cout << "Duracion: " << duration << endl;   //1.459

    return 0;
}
