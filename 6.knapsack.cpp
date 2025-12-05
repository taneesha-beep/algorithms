#include <iostream>
using namespace std;

class knap
{
    int B[20][20];
    int T[2][20];
    int n, W;

public:
    void accept(int p[], int w[], int numItems, int maxWeight)
    {
        n = numItems;
        W = maxWeight;

        for (int i = 0; i < n; i++)
        {
            T[0][i] = p[i];
            T[1][i] = w[i];
        }
    }

    void knapsack()
    {
        for (int w = 0; w <= W; w++)
        {
            B[0][w] = 0;
        }
        for (int i = 0; i <= n; i++)
        {
            B[i][0] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int w = 0; w <= W; w++)
            {
                if (T[1][i - 1] <= w)
                {
                    B[i][w] = max(T[0][i - 1] + B[i - 1][w - T[1][i - 1]], B[i - 1][w]);
                }
                else
                {
                    B[i][w] = B[i - 1][w];
                }
            }
        }
    }

    void backtrack()
    {
        int w = W;
        cout << "items included in solution: " << endl;
        for (int i = n; i > 0; i--)
        {
            if (B[i][w] != B[i - 1][w])
            {
                cout << "item " << i << ": " << "value = " << T[0][i - 1] << ", weight = " << T[1][i - 1] << endl;
                w -= T[1][i - 1];
            }
        }
    }

    void display()
    {
        cout << "max profit: " << B[n][W] << endl;
    }
};

int main()
{
    knap k;
    int n, W;
    cout << "no. of items: ";
    cin >> n;
    int p[n], w[n];

    cout << "values of items: ";
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    cout << "weights of items: ";
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    cout << "max weight: ";
    cin >> W;

    k.accept(p, w, n, W);
    k.knapsack();
    k.display();
    k.backtrack();

    return 0;
}
