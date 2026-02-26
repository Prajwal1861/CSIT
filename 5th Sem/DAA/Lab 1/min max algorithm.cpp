#include <iostream>
using namespace std;

void min_max(int A[], int n)
{
    int minVal, maxVal;
    int comparisons = 0;

    minVal = maxVal = A[0];

    for (int i = 1; i < n; i++)
    {
        comparisons++;
        if (A[i] < minVal)
            minVal = A[i];

        comparisons++;
        if (A[i] > maxVal)
            maxVal = A[i];
    }

    cout << "\nMinimum element: " << minVal;
    cout << "\nMaximum element: " << maxVal;
    cout << "\nTotal comparisons: " << comparisons << endl;
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

    min_max(A, n);

    return 0;
}

