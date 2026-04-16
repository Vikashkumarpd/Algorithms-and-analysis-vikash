#include<iostream>
#include<chrono>
#include<random>
#include<vector>
#include<fstream>
using namespace std;
int linear_search(vector<int>&v,int key){
    for(int i=0;i<v.size();i++){
        if(v[i]==key){
            return i;
        }
    }
    return -1;
}
int main(){
    ofstream fileW("linerW.csv");
    ofstream fileA("linerA.csv");
    ofstream fileB("linerB.csv");
    srand(time(0));
    // Average case
    
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    for(int i=10000;i<=50000;i+=1500){
        uniform_int_distribution<int> dist(0, 3*i);
        vector<int>nums;
        int j=0;
        while (j<i)
        {
            nums.push_back(dist(rng));
            j++;

        }
        
        
        vector<int>keys(10000);
        for(int j = 0; j < 10000; j++){
            uniform_int_distribution<int> dist(0, 3*i);
            keys[j]=dist(rng);
            
        }
        auto start = chrono::high_resolution_clock::now();
        for(int j=0;j<10000;j++){
           
           linear_search(nums,keys[j]);
        }

        
        auto end = chrono::high_resolution_clock::now();
        auto duration =chrono::duration_cast<chrono::microseconds>(end - start)/10000;
        fileA<<i<<","<<duration.count()<<endl;
        
    }
    fileA.close();
    cout<<"fileA created!"<<endl;
    //Worst case size and time

    for(int i=10000;i<=50000;i+=1500){
        uniform_int_distribution<int> dist(0, 3*i);
        vector<int>nums;
        int j=0;
        while (j<i)
        {
            nums.push_back(dist(rng));
            j++;

        }
        int key=-1;
        auto start = chrono::high_resolution_clock::now();
        for(int j=0;j<10000;j++){
            int idx=linear_search(nums,key);

        }
        
        auto end = chrono::high_resolution_clock::now();
        auto duration =chrono::duration_cast<chrono::microseconds>(end - start)/10000;
        fileW<<i<<","<<duration.count()<<endl;
        
    }
    fileW.close();
    cout<<"filew created"<<endl;

    //Best case size and time

    for(int i=10000;i<=50000;i+=1500){
        uniform_int_distribution<int> dist(0, 3*i);
        vector<int>nums;
        int j=0;
        while (j<i)
        {
            nums.push_back(dist(rng));
            j++;

        }
        int key=nums[0];
        auto start = chrono::high_resolution_clock::now();
        int idx=linear_search(nums,key);
        auto end = chrono::high_resolution_clock::now();
        auto duration =chrono::duration_cast<chrono::nanoseconds>(end - start);
        fileB<<i<<","<<duration.count()<<endl;
    }
    fileB.close();
    cout<<"fileB created!"<<endl;
    return 0;
}