#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> Find_Max_Crossing_Subarray(vector<int>A,int low,int mid, int high)
{
    vector<int>retorno;
    int left_sum = -100000;
    int sum = 0;
    int max_left,right_sum,max_right;
    for (int i = mid; i >= low; i--)
    {
        sum = sum + A[i];
        if (sum > left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }
    right_sum = -100000;
    sum = 0;

    for (int j = mid +1; j <= high; j++)
    {
        sum = sum + A[j];
        if (sum > right_sum)
        {
            right_sum = sum;
            max_right = j;
        }
    }
    retorno.push_back(max_left);
    retorno.push_back(max_right);
    retorno.push_back(left_sum + right_sum);
    return retorno;
}

vector<int>FIND_MAXIMUM_SUBARRAY(vector<int>A, int low, int high)
{
    vector<int>retorno, B, C, D;

    if (high == low)
    {
        retorno.push_back(low);
        retorno.push_back(high);
        retorno.push_back(A[low]);

        return retorno;
    }
    else
    {
        int mid = floor((low + high) / 2);
        B = FIND_MAXIMUM_SUBARRAY(A, low, mid);
        C = FIND_MAXIMUM_SUBARRAY(A, mid+1, high);
        D = Find_Max_Crossing_Subarray(A, low, mid, high);

        if ((B[2] >= C[2]) && (B[2] >= D[2]) )
        {

            return B;
        }
        else if ((C[2] >= B[2]) && (C[2] >= D[2]))
        {

            return C;
        }
        else
        {

            return D;
        }


    }

}



int main()
{
    /*vector<int>Max_Sub;
    Max_Sub = { 1, -3, 2, 1, -1 };
    vector<int> B= FIND_MAXIMUM_SUBARRAY(Max_Sub,0,5);*/
    vector<int> A={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    vector<int> B= FIND_MAXIMUM_SUBARRAY(A,0,15);
    cout<<"inicio: "<<B[0]<<"  fin: "<<B[1]<<"  suma:"<<B[2];

    getchar();
    return 0;
}
