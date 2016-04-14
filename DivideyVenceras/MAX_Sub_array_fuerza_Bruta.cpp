#include <iostream>
#include <vector>
using namespace std;
void FIND_MAX_SUBARRAY(vector<int>A,int low,int high)
{
    int left = 0;
    int right = 0;
    int sum_max =A[0];
    for(int i = 1 ;i<high;i++)
    {
        cout<<"Elemento i "<<A[i]<<endl;
        if(A[i]>sum_max)
            sum_max=A[i];
        int temp=A[i];
        cout<<"Temp antes "<<temp<<endl;
        for(int j =i-1;j>=0;j--)
        {
            cout<<"Elemento j "<<A[j]<<endl;
            temp+=A[j];
            cout<<"Temp "<<temp<<endl;
            if(temp>sum_max)
                sum_max=temp;
            cout<<"Sum "<<sum_max<<endl;

            left =j;
            right =i;


        }

    }
    cout<<"Left "<<left<<" right "<<right<<" sum "<<sum_max<<endl;
    //return (left, right, sum);
}



int main()
{
   vector<int> A={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
   //vector<int> A={7,4,3};
   FIND_MAX_SUBARRAY(A,0,15);
}
