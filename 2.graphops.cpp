#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class friends
{
    int id;
    char name[10];
    friends *next;
    friend class graph;
    friend class Stack;
    friend class Queue;
};

class graph
{
    friends *head[10];
    int visited[10];
    int n;
    friend class Stack;
    friend class Queue;

public:
    graph()
    {
        cout << "Enter no. of vertices: ";
        cin >> n;
        cout << "Enter vertices: ";
        for (int i = 0; i < n; i++)
        {
            head[i] = new friends;
            head[i]->id = i;
            cin >> head[i]->name;
            head[i]->next = NULL;
        }
    }
    void create();
    void display();
    void dfs_r(int n);
    void dfs_r();
    void dfs_nr(int n);
    void bfs(int n);
};

class Stack
{
private:
    int top;
    int stackk[20];

public:
    Stack()
    {
        top = -1;
    }
    int isFull();
    int isEmpty();
    void push(int id);
    int pop();
};

class Queue
{
private:
    int rear, front;
    int q[20];

public:
    Queue()
    {
        rear = front = -1;
    }
    int isempty();
    int isfull();
    void insert(int id);
    int delet();
};

int Queue::isempty()
{
    return (rear == front);
}
int Queue::isfull()
{
    return (rear == 19);
}
void Queue::insert(int elem)
{
    if (isfull())
        cout << "\nQueue is full\n";
    q[++rear] = elem;
}
int Queue::delet()
{
    if (isempty())
        return -1;
    int elem = q[++front];
    return elem;
}

int Stack::isFull()
{
    return (top == 19);
}
int Stack::isEmpty()
{
    return (top == -1);
}
void Stack::push(int id)
{
    if (isFull())
    {
        cout << "Stack full\n";
    }
    stackk[++top] = id;
}
int Stack::pop()
{
    if (isEmpty())
    {
        return -1;
    }
    int elem = stackk[top--];
    return elem;
}

void graph::create()
{
    char ch;
    for (int i = 0; i < n; i++)
    {
        friends *temp = head[i];
        cout << "Enter y to add friends of " << i << ": ";
        cin >> ch;
        while (ch == 'y')
        {
            friends *curr = new friends;
            cout << "Enter ID of the friend: ";
            cin >> curr->id;
            if (head[i]->id == curr->id)
            {
                cout << "Self loops are not allowed\n";
            }
            else
            {
                strcpy(curr->name, head[curr->id]->name);
                curr->next = NULL;
                temp->next = curr;
                temp = temp->next;
            }
            cout << "Enter y to add more friends: ";
            cin >> ch;
        }
    }
}
void graph::display()
{
    for (int i = 0; i < n; i++)
    {
        friends *temp = head[i];
        while (temp != NULL)
        {
            cout << temp->name << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void graph::dfs_r()
{
    int v;
    cout << "\nEnter starting vertex: ";
    cin >> v;
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    cout << "\nDFT (recursive):\n";
    dfs_r(v);
}
void graph::dfs_r(int v)
{
    visited[v] = 1;
    cout << head[v]->name << " ";
    friends *temp = head[v]->next;
    while (temp != NULL)
    {
        if (!visited[temp->id])
        {
            dfs_r(temp->id);
        }
        temp = temp->next;
    }
}
void graph::dfs_nr(int v)
{
    Stack s;
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    s.push(v);
    visited[v] = 1;
    do
    {
        v = s.pop();
        cout << head[v]->name << " ";
        friends *temp = head[v]->next;
        while (temp != NULL)
        {
            if (!visited[temp->id])
            {
                s.push(temp->id);
                visited[temp->id] = 1;
            }
            temp = temp->next;
        }
    } while (!s.isEmpty());
}

void graph::bfs(int v)
{
    Queue q;
    friends *temp = NULL;
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    q.insert(v);
    visited[v] = 1;
    while (!q.isempty())
    {
        v = q.delet();
        cout << head[v]->name << " ";
        temp = head[v]->next;
        while (temp != NULL)
        {
            if (!visited[temp->id])
            {
                q.insert(temp->id);
                visited[temp->id] = 1;
            }
            temp = temp->next;
        }
    }
}

int main()
{
    graph g;
    int v, ch;
    g.create();

    while (1)
    {
        cout << "\n1-Display adjacency list\n2-DFT (recursive)\n3-DFT (non_recursive)\n4-BFT\n5-Exit\nEnter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nAdjacency List:\n";
            g.display();
            cout << endl;
            break;

        case 2:
            g.dfs_r();
            cout << endl;
            break;

        case 3:
            cout << "Enter starting vertex: ";
            cin >> v;
            cout << "\nDFT (non recursive):\n";
            g.dfs_nr(v);
            cout << endl;
            break;

        case 4:
            cout << "\nEnter starting vertex: ";
            cin >> v;
            cout << "\nBFT:\n";
            g.bfs(v);
            cout << endl;
            break;

        case 5:
            cout << "Program has ended.\n";
            exit(0);
            break;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
