#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int mid, int r)
{
    vector<int>a;
    int left = l;
    int right = mid + 1;
    while(left<=mid && right<=r){
        if(arr[left]<=arr[right]){
            a.push_back(arr[left]);
            left++;
        }
        else{
            a.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        a.push_back(arr[left]);
        left++;
    }
    while(right<=r){
        a.push_back(arr[right]);
        right++;
    }
    for(int i = l; i<=r;i++){
        arr[i]=a[i-l];
    }
}
void mergeSort(int arr[], int l, int r)
{    
    if(r>l){
        int m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
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
    for (auto &&i : arr)
    {
        cout<<i<<" ";
    }
    
}
