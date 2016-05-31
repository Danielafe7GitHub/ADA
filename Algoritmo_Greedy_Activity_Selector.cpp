#include <iostream>
#include <vector>
using namespace std;
vector<int>A,B;

vector<int>Greedy_Activity_Selector(vector<int>S,vector<int>F)
{

    int k=1;
    int m;
    A.push_back(0);
    for(m=2;m<=S.size();m++)
    {
        if(S[m]>=F[k])
        {
            A.push_back(m);
            k=m;
        }
    }
    return A;
}
void Recursive_Activity_Selector(vector<int>S,vector<int>F,int k)
{
    int m=k+1;
    while(m<=S.size() && S[m]<F[k])
    {
        m=m+1;

    }
    if(m<=S.size())
    {
        B.push_back(m);
        Recursive_Activity_Selector(S,F,m);
    }
}


int main()
{
    vector<int>star={1,3,0,5,3,5,6,8,8,2,12};
    vector<int>finish={4,5,6,7,9,9,10,11,12,14,16};
    vector<int>actividades=Greedy_Activity_Selector(star,finish);
    B.push_back(0);
    Recursive_Activity_Selector(star,finish,0);
    cout<<"Metodo Iterativo "<<endl;
    for(int i=0;i<actividades.size();i++)
        cout<<"Actividad "<<actividades[i]+1<<" , ";
    cout<<endl;
    cout<<"Metodo Recursivo "<<endl;
    for(int i=0;i<B.size();i++)
        cout<<"Actividad "<<B[i]+1<<" , ";
    return 0;
}
