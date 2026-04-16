#include <iostream>
#include<vector>
#include<random>
#include <cmath>
#include<chrono>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
int partition(vector<int>&nums,int low,int high){
    int s=low;
    int p=nums[low];
    for(int i=low+1;i<=high;i++){
        if(nums[i]<=p){
            s++;
        }
        
    }
    swap(nums[s],nums[low]);
    int i=low,j=high;
    while (i<s && j>s)
    {
        while (i<s && nums[i]<=p)
        {
            i++;
        }
        while (j>s && nums[j]>=p)
        {
            j--;
        }
        if(i<s && j>s){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }
    
    return s;
}
void quick_sort(vector<int>&nums,int low,int high){
    if(low>=high){
        return;
    }
    int pivot=partition(nums,low,high);
    quick_sort(nums,low,pivot-1);
    quick_sort(nums,pivot+1,high);
}
int main(){
    ofstream fileA("quick_sortA.csv");
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
        for(int k=0;k<100;k++){
            quick_sort(nums,0,i-1);

        }
        auto end=chrono::high_resolution_clock::now();
        auto durantion=chrono::duration_cast<chrono::microseconds>(end-start)/100;
        fileA<<i<<","<<durantion.count()<<endl;
        
        

    }
    fileA.close();
    cout<<"file created!"<<endl;
    //..........................worst case...........................
    ofstream fileW("quick_sortW.csv");
    
    for(int i=100;i<3000;i+=100){
        uniform_int_distribution<int> dist(0, 2*i);
        vector<int>nums;
        int j=0;
        while (j<i)
        {
            nums.push_back(dist(rng));
            j++;

        }
        sort(nums.begin(),nums.end(),greater<int>());
        auto start=chrono::high_resolution_clock::now();
        for(int k=0;k<100;k++){
            quick_sort(nums,0,i-1);

        }
        auto end=chrono::high_resolution_clock::now();
        auto durantion=chrono::duration_cast<chrono::microseconds>(end-start)/100;
        fileW<<i<<","<<durantion.count()<<endl;
        
        

    }
    cout<<"file created!"<<endl;
    fileW.close();
    // ....................best case..................
    ofstream fileB("quick_sortB.csv");
    
    for(int i=100;i<3000;i+=100){
        uniform_int_distribution<int> dist(0, 2*i);
        vector<int>nums;
        int j=0;
        while (j<i)
        {
            nums.push_back(dist(rng));
            j++;

        }
        sort(nums.begin(),nums.end());
        auto start=chrono::high_resolution_clock::now();
        for(int k=0;k<100;k++){
            quick_sort(nums,0,i-1);

        }
        auto end=chrono::high_resolution_clock::now();
        auto durantion=chrono::duration_cast<chrono::microseconds>(end-start)/100;
        fileB<<i<<","<<durantion.count()<<endl;
        
        

    }
    cout<<"file created!"<<endl;
    fileB.close();

}
    