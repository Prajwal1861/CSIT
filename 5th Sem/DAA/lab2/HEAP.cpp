#include <iostream>
#include <algorithm>
using namespace std;

int iterations = 0;

void heapify(int A[], int n, int i)
{
    iterations++;
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && A[l] > A[largest])
        largest = l;

    if (r < n && A[r] > A[largest])
        largest = r;

    if (largest != i)
    {
        swap(A[i], A[largest]);
        heapify(A, n, largest);
    }
}

void heapSort(int A[], int n)
{
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(A, n, i);

    for (int i = n-1; i > 0; i--)
    {
        swap(A[0], A[i]);
        heapify(A, i, 0);
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int A[n];
    cout << "Enter elements:\n";
    for(int i=0;i<n;i++)
        cin >> A[i];

    heapSort(A, n);

    cout << "\nSorted Array: ";
    for(int i=0;i<n;i++)
        cout << A[i] << " ";

    cout << "\nIterations: " << iterations;
    return 0;
}

