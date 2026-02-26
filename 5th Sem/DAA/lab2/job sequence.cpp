#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    int id, deadline, profit;
};

bool cmp(Job a, Job b)
{
    return a.profit > b.profit;
}

int main()
{
    int n, iterations = 0;
    cout << "Enter number of jobs: ";
    cin >> n;

    Job A[n];
    cout << "Enter id deadline profit:\n";
    for(int i=0;i<n;i++)
        cin >> A[i].id >> A[i].deadline >> A[i].profit;

    sort(A, A+n, cmp);

    int slot[n];
    fill(slot, slot+n, -1);

    int totalProfit = 0;

    for(int i=0;i<n;i++)
    {
        for(int j=min(n, A[i].deadline)-1; j>=0; j--)
        {
            iterations++;
            if(slot[j] == -1)
            {
                slot[j] = A[i].id;
                totalProfit += A[i].profit;
                break;
            }
        }
    }

    cout << "Total Profit: " << totalProfit;
    cout << "\nIterations: " << iterations;
    return 0;
}

