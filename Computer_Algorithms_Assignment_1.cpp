#include<bits/stdc++.h>
using namespace std;

long long Fibonacci(int n)
{
    if(n==1)
    {
        return 1;
    }
    if(n==0)
    {
        return 0;
    }

    int sum = Fibonacci(n-1)+Fibonacci(n-2);
    

    return sum;

}

int main()
{
    
    int arr[100];
    for(int i=0;i<100;i++)
    {
        int num = rand()%100000;
        arr[i] = num;
    }

    for(int i=0;i<100;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    vector<int> prefixSum(100,0);
    prefixSum[0] = arr[0];


    for(int i=0;i<100;i++)
    {
        cout<<arr[i]<<" ";
        if(arr[i]&1)
        {
            cout<<"Odd"<<" ";
        }
        else
        {
            cout<<"Even"<<" ";
        }

        bool flag = false;
        for(int j=2;j*j<=arr[i];j++)
        {
            if(arr[i]%j==0)
            {
                cout<<"Non Prime number"<<" ";
                flag = true;
                break;
            }
        }

        if(!flag)
        {
            cout<<"Prime Number"<<" ";
        }

        if(i!=0)
        {
            prefixSum[i] = prefixSum[i-1] + arr[i];
        }

        cout<<endl;
    }

    int average = prefixSum[99]/100;
    cout<<"Prefix Sum array "<<endl;

    for(int i=0;i<100;i++)
    {
        cout<<prefixSum[i]<<" ";
    }
    cout<<endl;

    cout<<"Average = "<<average<<endl;
    

   cout<<Fibonacci(7);






}