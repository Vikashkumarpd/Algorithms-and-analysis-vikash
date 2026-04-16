#include<iostream>
#include<vector>
#include<chrono>
#include<fstream>
#include<cmath>
using namespace std;

int find_tip_time(double velocity)
{
    int count=0;

    while(velocity>=1){
        velocity*=0.58;
        count++;
    }
    return count;
}

int main()
{
    ofstream file("ball_problem.csv");

    for(int height=2000;height<=2000000;height += 200000)
    {
        double velocity=sqrt(2 * 9.8 * height);
        volatile int sink=0;
        int workload=height*200;   
        auto start=chrono::high_resolution_clock::now();
        for(int i=0;i<workload;i++){
            sink += find_tip_time(velocity);
        }
        auto end=chrono::high_resolution_clock::now();
        auto duration =
        chrono::duration_cast<chrono::nanoseconds>(end-start);
        file << height << "," << duration.count() / workload << endl;
        cout<<"Done "<<height<<endl;
    }

    file.close();
}