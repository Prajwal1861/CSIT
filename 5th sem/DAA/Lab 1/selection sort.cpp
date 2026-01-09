#include <iostream>
using namespace std;

void selection_sort(int A[], int n)
{
    int passes = 0, comparisons = 0;

    for (int i = 0; i < n - 1; i++)
    {
        passes++;
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            comparisons++;
            if (A[j] < A[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            swap(A[i], A[minIndex]);
        }
    }

    cout << "\nTotal Passes (Iterations): " << passes;
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

    selection_sort(A, n);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}

