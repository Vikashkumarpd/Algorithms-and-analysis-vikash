#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

void toh(int n,string src,string aux,string dest){

    if(n==1){
        //cout<<"Move disk 1 from "<<src<<" to "<<dest<<endl;

        return;
    }
    else{

        toh(n-1,src,dest,aux);
        //cout<<"Move disk "<<n<<"from"<<src<<"to "<<dest<<endl;
        toh(n-1,aux,src,dest);
    }


}

int main() {

   ofstream file("toh.csv");


   for(int n=1;n<=20;n++){

       auto start = high_resolution_clock::now();
       for(int i=0;i<10;i++){
          toh(n, "A", "B", "C");

       }
       auto end = high_resolution_clock::now();

       long long time=duration_cast<microseconds>(end - start).count()/10;
        file << n << "," << time << "\n";

   }
   
    file.close();
    cout << "\n file generated!\n";
    
    return 0;
}