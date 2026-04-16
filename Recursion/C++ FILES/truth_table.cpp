
#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;


void generate(vector<int>&arr,int i,int n){
    if(i==n){
        for(int it:arr){
            //cout<<it<<" ";
            
        }
        //cout<<endl;
        return;
    }
    arr[i]=0;
    generate(arr,i+1,n);
    arr[i]=1;
    generate(arr,i+1,n);
}

int main() {
    ofstream file("Truth_table.csv");


    for(int n=1;n<20;n+=1){

        
        vector<int>temp(n);


        auto start = high_resolution_clock::now();

        for(int i=0;i<1000;i++){

         generate(temp,0,n);


        }

        auto end =high_resolution_clock::now();

        auto time=duration_cast<nanoseconds>(end-start).count()/1000;

       file<<n<<","<<time<<endl;

    }
    cout<<"CSV File Gnerated Sucessfully "<<endl;
    file.close();
    
    return 0;
}