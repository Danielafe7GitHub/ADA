#include <iostream>
#include <vector>
using namespace std;


int main()
{

    int tam;
    cout<<"Ingrese La cant de Nodos de su Grafo: ";cin>>tam;
    vector < vector <int> >A(tam);
    bool ap;
    for(int i=0;i<tam;i++)
    {
        for(int j=0;j<tam;j++)
        {
            cout<<"Nodo "<<i+1<<" Apunta---> a "<<j+1<<"?(1=S / 0=N): ";
            cin>>ap;
            if(ap)
            {
                A[i].push_back(1);
            }
            else
            {
                A[i].push_back(0);
            }
        }
        cout<<"Evaluando Siguiente Nodo \n"<<endl;
    }

    for(int i=0;i<tam;i++)
    {
        for(int j=0;j<tam;j++)
        {
            //cout<<A[i][j]<<" ";
            if(A[i][j]==1)
            {
                cout<<"Nodo "<<i+1<<" ------>  "<<j+1;
            }
            else
            {
                cout<<"Nodo "<<i+1<<" --///->  "<<j+1;
            }

        }
        cout<<endl;
    }


    return 0;
}
