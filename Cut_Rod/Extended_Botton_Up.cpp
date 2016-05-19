#include <iostream>
#include <math.h>
#include<time.h>
#include<algorithm>
using namespace std;


pair<int*,int*> Extended_Bottom_Up_Cut_Rod(int* p,int n)
{
    pair<int*,int*> a;
    a.first=new int[n+1];
    a.second=new int[n+1];
    a.first[0]=0;
    a.second[0]=0;
    int q=-9999;
    for(int j=0;j<n+1;j++)
    {
        for(int i=0;i<=j;i++)
        {
            if(q<(p[i]+a.first[j-i]))
            {
                q=p[i]+a.first[j-i];
                a.second[j+1]=i+1;
            }
        }
        a.first[j+1]=q;
    }
    return a;
}

int main()
{

    clock_t start, finish;
    double duration;


    int p[]={1,5,8,9,10,17,17,20,24,30};
    pair<int*,int*> a;
    start=clock();
    a=Extended_Bottom_Up_Cut_Rod(p,10);
    finish=clock();
    for(int i=0;i<11;i++)
    {
        cout<<a.first[i]<<", ";
    }
    cout<<endl;

    for(int i=0;i<11;i++)
    {
        cout<<a.second[i]<<", ";
    }


    duration = (double)(finish - start )/CLOCKS_PER_SEC;
    cout << "Duracion: " << duration << endl;   //000
    return 0;
}
