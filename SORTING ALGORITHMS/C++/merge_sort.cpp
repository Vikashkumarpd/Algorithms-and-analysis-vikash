#include <iostream>
#include<vector>
#include <random>
#include <cmath>
#include<chrono>
#include<fstream>
#include<string>
using namespace std;
void merge(vector<int>&nums,int low,int mid,int high){
    int i=low,j=mid;
    vector<int>ans;
    while (i<mid && j<high)
    {
        if(nums[i]<=nums[j]){
            ans.push_back(nums[i]);
            i++;
        }
        else{
            ans.push_back(nums[j]);
            j++;
        }
        
    }
    while (i<mid)
    {
        ans.push_back(nums[i]);
        i++;
    }
    while (j<high)
    {
        ans.push_back(nums[j]);
        j++;
    }
    int k=0;
    for(int i=low;i<high;i++){
        nums[i]=ans[k];
        k++;
    }

    
    
    
}
void merge_sort(vector<int>&nums,int low,int high){
    if(high-low<=1){
        return;
    }
    int mid=low+(high-low)/2;
    merge_sort(nums,low,mid);
    merge_sort(nums,mid,high);
    merge(nums,low,mid,high);

}
int main(){
    ofstream file("merge_sort.csv");
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    for(int i=100;i<3000;i+=100){
        uniform_int_distribution<int> dist(0, 2*i);
        vector<int>nums;
        int j=0;
        while (j<i)
        {
            nums.push_back(dist(rng));
            j++;

        }
        auto start=chrono::high_resolution_clock::now();
        for(int k=0;k<1000;k++){
            merge_sort(nums,0,nums.size());

        }
        
        auto end=chrono::high_resolution_clock::now();
        auto durantion=chrono::duration_cast<chrono::microseconds>(end-start)/1000;
        file<<i<<","<<durantion.count()<<endl;

    }
    file.close();
    cout<<"file created!"<<endl;
    return 0;
    
}
