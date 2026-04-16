#include <iostream>
#include<vector>
#include <random>
#include <cmath>
#include<chrono>
#include<fstream>
#include<string>
using namespace std;

long long randomnum(int len) {
    long long low = pow(10, len - 1);       
    long long high = pow(10, len) - 1;     

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<long long> dist(low, high);
    return dist(gen);
}
void permutation(string &str,int i,int n){
    if(i==n){
        //cout<<str<<endl;
        return;
    }
    for(int k=i;k<n;k++){
        swap(str[i],str[k]);
        permutation(str,i+1,n);
        swap(str[i],str[k]);
    }

}

int main() {
    vector<long long>time;
    ofstream file("permutation.csv");
    for(int i=1;i<12;i++){
        long long n=randomnum(i);
        string str=to_string(n);
        auto start = chrono::high_resolution_clock::now();
        for(int i=0;i<10;i++){
            permutation(str,0,str.length());

        }
        
    
        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::microseconds>(end - start)/10;
        file<<i<<","<<duration.count()<<endl;
        
        
    }
    file.close();
    cout<<"file created!";
    return 0;
    
    
}
