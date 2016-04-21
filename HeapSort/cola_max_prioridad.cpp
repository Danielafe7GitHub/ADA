#include <iostream>
using namespace std;
int Parent(int i){return i/2;}
int izq_hijo(int i){return (2*i)+1;}
int der_hijo(int i){return (2*i)+2;}

void max_heapify(int* a,int i,int tam_heap)
{
    int l=izq_hijo(i);
    int r=der_hijo(i);
    int largest;
    if(l<tam_heap && a[l]>a[i])
    {
        largest=l;
    }else{largest=i;}
    if(r<tam_heap and a[r]>a[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        int aux=a[i];
        a[i]=a[largest];
        a[largest]=aux;
        max_heapify(a,largest,tam_heap);
    }
}



int Heap_Maximun(int*A)
{
    return A[0];
}

int Heap_Extract_Max(int *A,int size)
{
    if(size<1)
        cout<<"Heap Underflow"<<endl;
    int max=A[0];
    A[0]=A[size-1];
    size=size-1;
    max_heapify(A,0,size);
    return max;
}

void Heap_Incrase_Key(int*A,int i,int key)
{
    if(key<A[i])
        cout<<"La nueve clave es menor que la actual"<<endl;
    A[i]=key;
    while(i>1 && A[Parent(i)]<A[i])
    {
        int aux=A[i];
        A[i]=A[Parent(i)];
        A[Parent(i)]=aux;
        i=Parent(i);
    }
}
void Max_Heap_Insert(int*A,int key,int size)
{
    size++;
    A[size]=-99999;
    Heap_Incrase_Key(A,size,key);
}

int main()
{
   //int a[]={10,9,8,7,6,5,4,3,2,1};
   //heap_sort(a,10);
   int a[]={15,13,9,5,12,8,7,4,0,6,2,1};
   int retorno=Heap_Extract_Max(a,12);
   cout<<"Extract is:"<<retorno<<endl;

   for(int i=0;i<11;i++)
   {
       cout<<a[i]<<", ";
   }

   return 0;

}
