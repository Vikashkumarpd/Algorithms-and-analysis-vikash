#include<iostream>
#include<vector>
#include<fstream>
#include<chrono>
#include<algorithm>
#include<random>
using namespace std;

int binary_search_rec(const vector<int>& nums,int key,int low,int high){
    if(low>high) return -1;
    int mid=low+(high-low)/2;
    if(nums[mid]==key) return mid;
    else if(nums[mid]>key)
        return binary_search_rec(nums,key,low,mid-1);
    else
        return binary_search_rec(nums,key,mid+1,high);
}

int main(){
    ofstream file("binary_search.csv");
    ofstream filew("binary_searchworst.csv");
    ofstream fileb("binary_searchbest.csv");


    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    for(int n=20000;n<=2000000;n+=80000){
        vector<int> nums(n);
        uniform_int_distribution<int> dist(0,n);

     for(int i=0;i<n;i++)
            nums[i]=dist(rng);

        sort(nums.begin(),nums.end());

        int key = dist(rng);
        volatile int idx=0;
        //cpu warm up 
        for(int i=0;i<10000;i++)
            idx+=binary_search_rec(nums,key,0,n-1);

        int workload=n/5;

        auto start=chrono::high_resolution_clock::now();

        for(int k=0;k<workload;k++)
            idx+=binary_search_rec(nums,key,0,n-1);

        auto end=chrono::high_resolution_clock::now();

        auto duration=chrono::duration_cast<chrono::nanoseconds>(end-start);

        file<<n<<","<<duration.count()<<endl;
        cout<<"Done "<<n<<endl;
    }

    file.close();
    cout<<"CSV created"<<endl;
    // worst case
    for(int n=20000;n<=2000000;n+=80000){
        vector<int> nums(n);
        uniform_int_distribution<int> dist(0,n);

     for(int i=0;i<n;i++)
            nums[i]=dist(rng);

        sort(nums.begin(),nums.end());

        int key=-1;
        volatile int idx=0;
        //cpu warm up 
        for(int i=0;i<10000;i++)
            idx+=binary_search_rec(nums,key,0,n-1);

        int workload=n/5;

        auto start=chrono::high_resolution_clock::now();

        for(int k=0;k<workload;k++)
            idx+=binary_search_rec(nums,key,0,n-1);

        auto end=chrono::high_resolution_clock::now();

        auto duration=chrono::duration_cast<chrono::nanoseconds>(end-start);

        filew<<n<<","<<duration.count()<<endl;
        cout<<"Done "<<n<<endl;
    }

    file.close();
    cout<<"CSV created"<<endl;
    
    // best case
    for(int n=20000;n<=2000000;n+=80000){
        vector<int> nums(n);
        uniform_int_distribution<int> dist(0,n);

     for(int i=0;i<n;i++)
            nums[i]=dist(rng);

        sort(nums.begin(),nums.end());

        int key=nums[n/2];
        volatile int idx=0;
        //cpu warm up 
        for(int i=0;i<10000;i++)
            idx+=binary_search_rec(nums,key,0,n-1);

        int workload=n/5;

        auto start=chrono::high_resolution_clock::now();

        for(int k=0;k<workload;k++)
            idx+=binary_search_rec(nums,key,0,n-1);

        auto end=chrono::high_resolution_clock::now();

        auto duration=chrono::duration_cast<chrono::nanoseconds>(end-start);

        fileb<<n<<","<<duration.count()<<endl;
        cout<<"Done "<<n<<endl;
    }

    file.close();
    cout<<"CSV created"<<endl;
}