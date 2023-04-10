#include <bits/stdc++.h>
using namespace std;

int getmax(int arr[],int n){
    int ans =arr[0];
    for (int i = 1; i < n ; i++)
    {
        if(arr[i]>ans)ans=arr[i];
    }
    return ans;
}
void countsort(int arr[], int n, int exp){
    int count[10]={0};
    int output[n];
    for (int i = 0; i < n; i++)
    {
        count[(arr[i]/exp)%10]++;
    }
    for (int i = 1; i < 10; i++)
    {
        count[i]+=count[i-1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i]=output[i];
    }   
}
void radixsort(int arr[],int n){
    int max = getmax(arr,n);
    for (int i = 1; max/i > 0; i*=10)
    {
        countsort(arr,n,i);
    }    
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    radixsort(arr,n);
    for (auto &&i : arr)
    {
        cout<<i<<" ";
    }
    
}
