#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    string text;
    Node* left;
    Node* right;

    Node(string text)
    {
        this->text = text;
    }
};
class BST
{
private:
    Node* root;
    void free(Node* root)
    {
        if (root == nullptr)
            return;
        free(root->left);
        free(root->right);
        delete root;
    }
public:
    BST()
    {
        root = nullptr;
    }
    ~BST()
    {
        free(this->root);
    }
    void Insert(string data)
    {
        this->root = insert(this->root, data);
    }
    Node* insert(Node* root, string data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        if (data < root->text)
            root->left = insert(root->left, data);
        else if (data > root->text)
            root->right = insert(root->right, data);

        return root;
    }
    bool isIn(Node* root, string data)
    {
        if (root == nullptr)
        {
            return false;
        }

        if (root->text == data)
        {
            return true;
        }

        return isIn(root->left, data) || isIn(root->right, data);
    }
    Node* getRoot()
    {
        return root;
    }
};
int main()
{
    int N;
    cin >> N;
    BST tree;
    for (int i = 0; i < N; ++i)
    {
        string temp;
        cin >> temp;
        tree.Insert(temp);
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i)
    {
        string temp;
        cin >> temp;
        if (tree.isIn(tree.getRoot(), temp))
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }
    return 0;
}