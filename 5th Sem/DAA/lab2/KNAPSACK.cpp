#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int value, weight;
};

bool cmp(Item a, Item b)
{
    return (double)a.value/a.weight > (double)b.value/b.weight;
}

int main()
{
    int n, W, iterations = 0;
    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter capacity: ";
    cin >> W;

    Item A[n];
    cout << "Enter value and weight:\n";
    for(int i=0;i<n;i++)
        cin >> A[i].value >> A[i].weight;

    sort(A, A+n, cmp);

    double profit = 0.0;

    for(int i=0;i<n;i++)
    {
        iterations++;
        if(A[i].weight <= W)
        {
            W -= A[i].weight;
            profit += A[i].value;
        }
        else
        {
            profit += A[i].value * ((double)W / A[i].weight);
            break;
        }
    }

    cout << "Maximum Profit: " << profit;
    cout << "\nIterations: " << iterations;
    return 0;
}

