#include <iostream>
#include <stdlib.h>
using namespace std;

class MobileUser
{

private:
    int MobileNo;
    string Name;
    long int BillAmount;

public:
    MobileUser()
    {
        MobileNo = 0;
        Name = "-";
        BillAmount = 0;
    }

    friend class Records;
};

class Records
{

    MobileUser M[10];
    int n;

public:
    Records(int n1)
    {
        n = n1;
    }

    void accept()
    {
        cout << "Enter Name, Mobile Number and Bill Amount for users: " << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> M[i].Name >> M[i].MobileNo >> M[i].BillAmount;
        }
    }

    void display()
    {
        cout << "Details of users are as follows: " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "Name: " << M[i].Name << endl
                 << "Mobile Number: " << M[i].MobileNo << endl
                 << "Bill Amount: " << M[i].BillAmount << endl;
        }
    }

    // void Adjust (int M[], int n, int i) {
    // do {
    // int j;
    // j = 2*i+1;

    // if( (j + 1 <= n) && (M[j+1] > M[j]) ) {
    // j = j+1;
    // }

    // else if (M[i] >= M[j]){
    // break;
    // }

    // else {
    // int temp = M[i];
    // M[i] = M[j];
    // M[j] = temp;
    // }

    //}while (2*i+1 <= n);
    //}

    // void HeapSort (){

    // for (int i = (n/2)-1; i > 0; i++){
    // Adjust (M[], n-1, i);
    // }

    // while (n > 0){
    // int temp = M[0];
    // M[0] = M[n-1];
    // M[n-1] = temp;
    // n--;
    // Adjust (M[], n-1, 0);
    // }
    // }
};

int main()
{

    int n, x;
    char choice;
    Records r(n);

    do
    {
        cout << "1. accept\n2. display\n3. heap sort\n";
        cin >> x;

        switch (x)
        {
        case 1:
            cout << "enter number of users: ";
            cin >> n;
            r.accept();
            break;

        case 2:
            r.display();
            break;

        case 3:
            // r.HeapSort();
            r.display();
            break;

        default:
            cout << "invalid input, please try agan.\n";
            break;
        }

        cout << "do you want to enter more user details? (y/n): ";
        cin >> choice;

    } while (choice = 'y');
    return 0;
}
