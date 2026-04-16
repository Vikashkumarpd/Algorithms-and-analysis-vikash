

#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
#include<chrono>
#include<fstream>
using namespace std;

// Ternary Search
int ternary_search(vector<int>&num,int key,int st,int end){
    if(st > end){
        return -1;
    }

    int p1 = st + (end - st)/3;
    int p2 = end - (end - st)/3;

    if(num[p1] == key) return p1;
    if(num[p2] == key) return p2;

    if(key < num[p1]){
        return ternary_search(num,key,st,p1-1);
    }
    else if(key < num[p2]){
        return ternary_search(num,key,p1+1,p2-1);
    }
    else{
        return ternary_search(num,key,p2+1,end);
    }
}

int main(){
    ofstream file("ternary_search_avg.csv");
    ofstream filew("ternary_search_worst.csv");
    ofstream fileb("ternary_search_best.csv");

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    // Average Case
    for(int n=20000; n<=2000000; n+=80000){
        vector<int> nums(n);
        uniform_int_distribution<int> dist(0,n);

        for(int i=0;i<n;i++)
            nums[i]=dist(rng);

        sort(nums.begin(),nums.end());

        int key = dist(rng);
        volatile int idx=0;

        // CPU warm-up
        for(int i=0;i<10000;i++)
            idx += ternary_search(nums,key,0,n-1);

        int workload = n/5;

        auto start = chrono::high_resolution_clock::now();

        for(int k=0;k<workload;k++)
            idx += ternary_search(nums,key,0,n-1);

        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::nanoseconds>(end-start);

        file << n << "," << duration.count() << endl;
        cout<<"Done AVG "<<n<<endl;
    }

    //Worst Case 
    for(int n=20000; n<=2000000; n+=80000){
        vector<int> nums(n);
        uniform_int_distribution<int> dist(0,n);

        for(int i=0;i<n;i++)
            nums[i]=dist(rng);

        sort(nums.begin(),nums.end());

        int key = -1; // not present
        volatile int idx=0;

        for(int i=0;i<10000;i++)
            idx += ternary_search(nums,key,0,n-1);

        int workload = n/5;

        auto start = chrono::high_resolution_clock::now();

        for(int k=0;k<workload;k++)
            idx += ternary_search(nums,key,0,n-1);

        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::nanoseconds>(end-start);

        filew << n << "," << duration.count() << endl;
        cout<<"Done WORST "<<n<<endl;
    }

    //Best Case (middle element)
    for(int n=20000; n<=2000000; n+=80000){
        vector<int> nums(n);
        uniform_int_distribution<int> dist(0,n);

        for(int i=0;i<n;i++)
            nums[i]=dist(rng);

        sort(nums.begin(),nums.end());

        int p1 = (n-1)/3;
        int key = nums[p1]; // best case
        volatile int idx=0;

        for(int i=0;i<10000;i++)
            idx += ternary_search(nums,key,0,n-1);

        int workload = n/5;

        auto start = chrono::high_resolution_clock::now();

        for(int k=0;k<workload;k++)
            idx += ternary_search(nums,key,0,n-1);

        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::nanoseconds>(end-start);

        fileb << n << "," << duration.count() << endl;
        cout<<"Done BEST "<<n<<endl;
    }

    file.close();
    filew.close();
    fileb.close();

    cout<<"All CSV files created"<<endl;
}