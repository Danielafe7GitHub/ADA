#include <iostream>
using namespace std;
int Partition(int*A,int p,int r)
{    
    int x=A[r];
    int i=p-1;
    for(int j=p;j<r;j++)
    {                
        if(A[j]<=x)
        {
            i++;
            int aux=A[i];
            A[i]=A[j];
            A[j]=aux;
        }
    }
    int aux=A[i+1];
    A[i+1]=A[r];
    A[r]=aux;
    return i+1;

}

void QuickSort(int*A,int p,int r)
{
    if(p<r)
    {
        cout<<"p:"<<p<<endl;
        cout<<"r:"<<p<<endl;
        int q=Partition(A,p,r);
        cout<<"q:"<<q<<endl;
        QuickSort(A,p,q-1);
        QuickSort(A,q+1,r);
    }
}
int main()
{
    int A[8]={2,8,7,1,3,5,6,4};
    //Partition(A,1,7);
    QuickSort(A,0,7);
    for(int i=0;i<8;i++)
        cout<<A[i]<<"-";
    return 0;
}
