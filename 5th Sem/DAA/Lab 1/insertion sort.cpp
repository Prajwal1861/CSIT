#include <iostream>
using namespace std;

void insertion_sort(int A[], int n)
{
    int passes = 0, comparisons = 0, shifts = 0;

    for (int i = 1; i < n; i++)
    {
        passes++;
        int key = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > key)
        {
            comparisons++;
            A[j + 1] = A[j];
            shifts++;
            j--;
        }

        if (j >= 0)
            comparisons++;

        A[j + 1] = key;
    }

    cout << "\nTotal Passes (Iterations): " << passes;
    cout << "\nTotal Comparisons: " << comparisons;
    cout << "\nTotal Shifts: " << shifts << endl;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int A[n];

    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    insertion_sort(A, n);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}

