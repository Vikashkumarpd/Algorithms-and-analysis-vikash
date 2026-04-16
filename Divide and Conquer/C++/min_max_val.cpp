#include<bits/stdc++.h>
using namespace std;
void fun(vector<int>&arr,int st,int end,int &max,int &min){
    if(st>end){
        return;
    }
    int mid=(st+end)/2;
    if(arr[mid]<min){
        min=arr[mid];
    }
    if(arr[mid]>max){
        max=arr[mid];
    }
    fun(arr,st,mid-1,max,min);
    fun(arr,mid+1,end,max,min);
}
int main(){
    vector<int>arr={4,67,4,7,4,3,8,9,5};
    int max=INT16_MIN,min=INT16_MAX;
    fun(arr,0,arr.size()-1,max,min);
    cout<<"maximum element and minimum element in given array is: "<<max<<" and "<<min<<endl;
}