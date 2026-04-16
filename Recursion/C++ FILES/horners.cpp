#include <iostream>
#include <vector>
#include<chrono>
#include<random>
#include<fstream>
using namespace std;

long long hornerRec(const vector<long long>& a, int i, long long x) {
    
    if (i == a.size() - 1)
        return a[i];

    return a[i] + x * hornerRec(a, i + 1, x);
}

int main() {
    srand(time(0));
    ofstream file("horner.csv");
    for(int i=50;i<=1000;i+=50){
        vector<long long>v;
        
        while (v.size()<i)
        {
            long long n=rand()%(i-0+1);
            v.push_back(n);
        }
        auto start = chrono::high_resolution_clock::now();
        for(int i=0;i<100000;i++){
            long long val=hornerRec(v, 0, 2);

        }
         
        auto end = chrono::high_resolution_clock::now();
        auto duration =chrono::duration_cast<chrono::nanoseconds>(end - start)/100000;
        file<<i<<","<<duration.count()<<endl;

        
    }
    file.close();
    cout<<"file created!"<<endl;
    return 0;

     
}
