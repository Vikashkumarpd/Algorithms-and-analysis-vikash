#include <bits/stdc++.h>
#include<chrono>
using namespace std::chrono;
using namespace std;

int sum(int n){

    if(n==1)return 1;
    return n+sum(n-1);
   

}

int main() {
    ofstream file("sum_rec.csv");

    for(int n=1000;n<=20000;n+=1000){

        
        auto start=high_resolution_clock::now();

        for(int i=0;i<1000;i++){

            sum(n);
        }
        

        auto end=high_resolution_clock::now();
        auto time=duration_cast<microseconds>(end-start).count()/1000;

        file<<n<<","<<time<<"\n";
    }

    cout<<"CSV file generated suessfully "<<endl;

    file.close();
    

    

    return 0;
    
}