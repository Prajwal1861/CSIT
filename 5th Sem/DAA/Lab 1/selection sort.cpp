#include <iostream>
using namespace std;

int main()
{
    int n, iterations = 0;
    cout << "Enter number of elements: ";
    cin >> n;

    int A[n];
    cout << "Enter elements:\n";
    for(int i=0;i<n;i++)
        cin >> A[i];

    // Selection Sort
    for(int i=0;i<n-1;i++)
    {
        int minIndex = i;
        for(int j=i+1;j<n;j++)
        {
            iterations++;   // counting comparisons
            if(A[j] < A[minIndex])
                minIndex = j;
        }
        // swap
        int temp = A[i];
        A[i] = A[minIndex];
        A[minIndex] = temp;
    }

    cout << "\nSorted Array: ";
    for(int i=0;i<n;i++)
        cout << A[i] << " ";

    cout << "\nIterations: " << iterations;
    return 0;
}

