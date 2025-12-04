#include <iostream>
#include <string>

using namespace std;

class avl_node
{
public:
    string word;
    string meaning;
    avl_node *left;
    avl_node *right;
    avl_node(string word, string meaning)
    {
        this->word = word;
        this->meaning = meaning;
        left = right = nullptr;
    }
    friend class avlTree;
};

class avlTree
{
    avl_node *root;

public:
    avlTree()
    {
        root = nullptr;
    }

    int height(avl_node *);
    int diff(avl_node *);
    avl_node *rr_rotation(avl_node *);
    avl_node *ll_rotation(avl_node *);
    avl_node *lr_rotation(avl_node *);
    avl_node *rl_rotation(avl_node *);
    avl_node *balance(avl_node *);
    avl_node *insert(avl_node *, string, string);
    void display(avl_node *, int);
    void inorder(avl_node *);
    void preorder(avl_node *);
    void postorder(avl_node *);
};

// Utility functions for AVL tree balancing
int avlTree::height(avl_node *node)
{
    if (node == nullptr)
        return 0;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int avlTree::diff(avl_node *node)
{
    return height(node->left) - height(node->right);
}

avl_node *avlTree::rr_rotation(avl_node *parent)
{
    avl_node *temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

avl_node *avlTree::ll_rotation(avl_node *parent)
{
    avl_node *temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

avl_node *avlTree::lr_rotation(avl_node *parent)
{
    parent->left = rr_rotation(parent->left);
    return ll_rotation(parent);
}

avl_node *avlTree::rl_rotation(avl_node *parent)
{
    parent->right = ll_rotation(parent->right);
    return rr_rotation(parent);
}

avl_node *avlTree::balance(avl_node *node)
{
    int balanceFactor = diff(node);
    if (balanceFactor > 1)
    {
        if (diff(node->left) > 0)
            node = ll_rotation(node);
        else
            node = lr_rotation(node);
    }
    else if (balanceFactor < -1)
    {
        if (diff(node->right) < 0)
            node = rr_rotation(node);
        else
            node = rl_rotation(node);
    }
    return node;
}

avl_node *avlTree::insert(avl_node *node, string word, string meaning)
{
    if (node == nullptr)
    {
        node = new avl_node(word, meaning);
        return node;
    }

    if (word < node->word)
    {
        node->left = insert(node->left, word, meaning);
    }
    else if (word > node->word)
    {
        node->right = insert(node->right, word, meaning);
    }

    return balance(node);
}

void avlTree::display(avl_node *node, int level)
{
    if (node == nullptr)
        return;
    display(node->right, level + 1);
    for (int i = 0; i < level; i++)
        cout << "    ";
    // Display the node's word and its balance factor
    cout << node->word << " (" << diff(node) << ")" << endl;
    display(node->left, level + 1);
}

void avlTree::inorder(avl_node *node)
{
    if (node == nullptr)
        return;
    inorder(node->left);
    cout << node->word << " => " << node->meaning << endl;
    inorder(node->right);
}

void avlTree::preorder(avl_node *node)
{
    if (node == nullptr)
        return;
    cout << node->word << " => " << node->meaning << endl;
    preorder(node->left);
    preorder(node->right);
}

void avlTree::postorder(avl_node *node)
{
    if (node == nullptr)
        return;
    postorder(node->left);
    postorder(node->right);
    cout << node->word << " => " << node->meaning << endl;
}

int main()
{
    int choice;
    string word, meaning;
    avlTree avl;
    avl_node *root = nullptr;

    while (1)
    {
        cout << "AVL Tree Implementation for Dictionary" << endl;
        cout << "1. Insert word and meaning" << endl;
        cout << "2. Display AVL Tree (with balance factor)" << endl;
        cout << "3. Inorder Traversal" << endl;
        cout << "4. Preorder Traversal" << endl;
        cout << "5. Postorder Traversal" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore the newline character

        switch (choice)
        {
        case 1:
            cout << "Enter word: ";
            getline(cin, word);
            cout << "Enter meaning: ";
            getline(cin, meaning);
            root = avl.insert(root, word, meaning);
            break;
        case 2:
            if (root == nullptr)
            {
                cout << "Tree is empty." << endl;
            }
            else
            {
                cout << "AVL Tree (with balance factors):" << endl;
                avl.display(root, 0);
            }
            break;
        case 3:
            cout << "Inorder Traversal (Sorted Dictionary):" << endl;
            avl.inorder(root);
            break;
        case 4:
            cout << "Preorder Traversal:" << endl;
            avl.preorder(root);
            break;
        case 5:
            cout << "Postorder Traversal:" << endl;
            avl.postorder(root);
            break;
        case 6:
            exit(0);
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
