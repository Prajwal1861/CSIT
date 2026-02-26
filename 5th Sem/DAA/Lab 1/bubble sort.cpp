#include <iostream>
using namespace std;

void bubble_sort(int A[], int n)
{
    int pass = 0, comparisons = 0;

    for (int i = 0; i < n - 1; i++)
    {
        pass++;
        for (int j = 0; j < n - 1 - i; j++)
        {
            comparisons++;
            if (A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
            }
        }
    }

    cout << "\nTotal Passes (Iterations): " << pass;
    cout << "\nTotal Comparisons: " << comparisons << endl;
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

    bubble_sort(A, n);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}

