#include<bits/stdc++.h>
using namespace std;
void splitFunction(int arr[], int l, int r);
void mergeFunction(int* arr, int l, int mid, int r);
int main(){
    int arr[]={6, 5, 5, 6, 12, 10, 9, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    splitFunction(arr, 0, n-1);

    cout<<"after sort"<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
        cout<<endl;



    return 0;
}

void splitFunction(int arr[], int l, int r){

    int mid = l+(r-l)/2;

    if(l<r){
        //left

    splitFunction(arr, l, mid);
    //right
    splitFunction(arr, mid+1, r);

    mergeFunction(arr, l, mid, r);
    }

}
void mergeFunction(int* arr, int l, int mid, int r){
    int i=l;
    int j=mid+1;

    int temp[r-l+1];
    int k=0;
    while(i<=mid && j<=r)
            if(arr[i]<arr[j])
                temp[k++]=arr[i++];
            else temp[k++]=arr[j++];

    while(i<=mid)
        temp[k++]=arr[i++];

    while(j<=r)
        temp[k++]=arr[j++];

        k=0;
    for(int i=l;i<=r;i++)
        arr[i]=temp[k++];

}
