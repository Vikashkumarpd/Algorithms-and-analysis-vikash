#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

void insertionsort(vector<int>& a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && a[j] < a[j - 1])
        {
            swap(a[j], a[j - 1]);
            j--;
        }
    }
}

int main()
{
    ofstream file1("insertion_best_case.csv");
    ofstream file2("insertion_worst_case.csv");
    ofstream file3("insertion_avg_case.csv");

    file1 << "n,time\n";
    file2 << "n,time\n";
    file3 << "n,time\n";

    srand(time(0));

    for (int n = 1000; n <= 10000; n += 1000)
    {
        int repeat = 50;

        // ---------------- BEST CASE ----------------
        vector<int> a(n);

        for (int i = 0; i < n; i++)
            a[i] = i;

        auto start1 = high_resolution_clock::now();

        for (int r = 0; r < repeat; r++)
        {
            vector<int> temp = a;
            insertionsort(temp, n);
        }

        auto end1 = high_resolution_clock::now();

        long long bestTime =
            duration_cast<nanoseconds>(end1 - start1).count() / repeat;

        file1 << n << "," << bestTime << "\n";

        // ---------------- WORST CASE ----------------
        vector<int> a2(n);

        for (int i = 0; i < n; i++)
            a2[i] = n - i;

        auto start2 = high_resolution_clock::now();

        for (int r = 0; r < repeat; r++)
        {
            vector<int> temp = a2;
            insertionsort(temp, n);
        }

        auto end2 = high_resolution_clock::now();

        long long worstTime =
            duration_cast<microseconds>(end2 - start2).count() / repeat;

        file2 << n << "," << worstTime << "\n";

        // ---------------- AVERAGE CASE ----------------
        vector<int> a3(n);

        for (int i = 0; i < n; i++)
            a3[i] = rand() % 100000;

        auto start3 = high_resolution_clock::now();

        for (int r = 0; r < repeat; r++)
        {
            vector<int> temp = a3;
            insertionsort(temp, n);
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