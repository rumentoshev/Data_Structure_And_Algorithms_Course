#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node
{
    Node* left;
    Node* right;

    Node()
    {
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Tree
{
private:
    Node* root;
public:
    Tree()
    {
        this->root = new Node();
    }
    void insert(int num,int &counter)
    {
        this->root = this->check(this->root, num, counter);
    }
    Node* check(Node* node, int num, int& counter)
    {
        queue<Node*> nodes;
        nodes.push(this->root);

        while (num != 0)
        {
            int size = nodes.size();

            for (int i = 0; i < size; i++)
            {
                Node* temp = nodes.front();
                nodes.pop();
                if (num % 2 == 0)
                {
                    if (temp->left == nullptr)
                    {
                        temp->left = new Node();
                        nodes.push(temp->left);
                    }
                    else
                    {
                        nodes.push(temp->left);
                    }
                }
                else if (num % 2 == 1)
                {
                    if (temp->right == nullptr)
                    {
                        temp->right = new Node();
                        counter++;
                        nodes.push(temp->right);
                    }
                    else
                    {
                        nodes.push(temp->right);
                    }
                    if (temp->left == nullptr)
                    {
                        temp->left = new Node();
                        nodes.push(temp->left);
                    }
                    else
                    {
                        nodes.push(temp->left);
                    }
                }
            }
            num /= 2;
        }

        return root;
    }

    Node* getRoot()
    {
        return root;
    }
};
int main() {

    int N;
    cin >> N;
    int counter = 1;
    Tree tr;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        tr.check(tr.getRoot(), num, counter);
    }

    cout << counter;
    return 0;
}