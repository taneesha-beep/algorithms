#include <iostream>
#include <stdlib.h>
using namespace std;
#define size 40

class graph
{
    int cities;
    int cost[size][size];

public:
    graph()
    {
        cout << "Enter no. of cities: ";
        cin >> cities;
        for (int i = 0; i < cities; i++)
        {
            for (int j = 0; j < cities; j++)
            {
                cost[i][j] = 999;
                cost[j][i] = 999;
            }
        }
    }
    void accept();
    void display();
    int prims(int v);
};

void graph::accept()
{
    char ch;
    int n, k = 0;
    for (int i = 0; i < cities; i++)
    {
        for (int j = 0; j < cities; j++)
        {
            cout << "\nAre the cities " << i << " and " << j << " connected? (y/n): ";
            cin >> ch;
            if (ch == 'y')
            {
                cout << "\nEnter cost of " << i << "-" << j << " path: ";
                cin >> n;
                cost[i][j] = n;
                cost[j][i] = n;
            }
        }
    }
}

void graph::display()
{
    cout << endl;
    for (int i = 0; i < cities; i++)
    {
        for (int j = 0; j < cities; j++)
        {
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }
}

int graph::prims(int start)
{
    int nearest[size];
    int r = 0, j = 0;
    int t[size][3];
    int mincost = 0;
    nearest[start] = -1;
    for (int i = 0; i < cities; i++)
    {
        if (i != start)
        {
            nearest[i] = start;
        }
    }
    for (int i = 1; i < cities; i++)
    {
        int min = 9999;
        for (int k = 0; k < cities; k++)
        {
            if (nearest[k] != -1 && cost[k][nearest[k]] < min)
            {
                j = k;
                min = cost[k][nearest[k]];
            }
        }
        t[r][0] = nearest[j];
        t[r][1] = j;
        t[r][2] = min;
        r++;
        mincost += min;
        nearest[j] = -1;
        for (int k = 0; k < cities; k++)
        {
            if (nearest[k] != -1 && cost[k][nearest[k]] > cost[k][j])
            {
                nearest[k] = j;
            }
        }
    }
    return mincost;
}

int main()
{
    int v;
    graph g;
    g.accept();
    g.display();
    cout << "\nEnter starting vertex: ";
    cin >> v;
    int a = g.prims(v);
    cout << "Mincost: " << a;
}
