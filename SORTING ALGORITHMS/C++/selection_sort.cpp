#include <bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;

void selectionsort(vector<int>&a,int n){

    int idx;
    int j;
    
    for(int i=0;i<n;i++){

        idx=i;

        for(j=i+1;j<n;j++){

            if(a[j]<a[idx]){
               
                idx=j;
            }
        }

        swap(a[idx],a[i]);
    }
}

int main() {

    ofstream file1("selection_best_case.csv");
    ofstream file2("selection_worst_case.csv");
    ofstream file3("selection_avg_case.csv");

    file1 << "n,time\n";
    file2 << "n,time\n";
    file3 << "n,time\n";

    srand(time(0));

    for (int n = 1000; n <= 10000; n += 1000)
    {
       
        vector<int> a(n);

        for (int i = 0; i < n; i++)
            a[i] = i;

        int repeat = 50;

        auto start1 = high_resolution_clock::now();

        for(int r=0; r<repeat; r++)
        {
            vector<int> temp =a; 
            selectionsort(temp, n);
        }

        auto end1 = high_resolution_clock::now();

        long long bestTime =
        duration_cast<microseconds>(end1 - start1).count() / repeat;

        file1 << n << "," << bestTime << "\n";

        
        vector<int> a2(n);

        for (int i = 0; i < n; i++)
            a2[i] = n - i;

        auto start2 = high_resolution_clock::now();

        for(int r=0; r<repeat; r++)
        {
            vector<int> temp =a2; 
            selectionsort(temp, n);
        }

        auto end2 = high_resolution_clock::now();

        long long worstTime =
        duration_cast<microseconds>(end2 - start2).count() / repeat;

        file2 << n << "," << worstTime << "\n";

        
        vector<int> a3(n);

        for (int i = 0; i < n; i++)
            a3[i] = rand()%100000;

        auto start3 = high_resolution_clock::now();

        for(int r=0; r<repeat; r++)
        {
            vector<int> temp =a3; 
            selectionsort(temp, n);
        }

        auto end3 = high_resolution_clock::now();

        long long avgTime =
        duration_cast<microseconds>(end3 - start3).count() / repeat;

        file3 << n << "," << avgTime << "\n";

        cout << "Done for n = " << n << endl;
    }

    file1.close();
    file2.close();
    file3.close();

    cout << "\nCSV files generated successfully!\n";

    return 0;
}