#include <bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
int main(){
    int n;
    cin>>n;
    int arr[n];
    f(i,0,n)cin>>arr[i];
    f(i,0,n-1){
        f(j,0,n-i-1){
            if(arr[j+1]<arr[j])swap(arr[j],arr[j+1]);
        }
    }
    f(i,0,n)cout<<arr[i]<<" ";
}
