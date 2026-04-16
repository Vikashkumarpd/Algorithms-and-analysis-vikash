#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

long long power(long long x,int pow){

    if(pow==0){
        return 1;
    }

    return x * power(x,pow-1);
}

int main() {

    ofstream file("power_rec.csv");

    for(int n=100;n<=1000;n+=50){

        auto start = high_resolution_clock::now();

        for(int i=0;i<10000;i++){

            power(2,n);
        }

        auto end = high_resolution_clock::now();

        long long time =
        duration_cast<nanoseconds>(end-start).count()/10000;

        file << n << "," << time << "\n";
    }

    file.close();

    cout << "CSV file generated successfully!" << endl;

    return 0;
}