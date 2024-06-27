#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node
{
    int val;
    vector<Node*> children;

    Node(int val) : val(val) {}

};

class Tree
{
public:
    Node* root;
    Tree()
    {
        root = nullptr;
    }
    Node* addElement(int parent, int child)
    {
        if (root == nullptr)
        {
            this->root = new Node(parent);
            Node* temp = new Node(child);
            this->root->children.push_back(temp);
            return root;
        }
        else
        {
            Node* temp = find1(this->root, parent);
            Node* tempKid = new Node(child);
            temp->children.push_back(tempKid);
            return this->root;
        }
    }
    bool isElementIn(Node* root, int num1)
    {
        queue<Node*> arr;
        arr.push(root);
        while (!arr.empty())
        {
            Node* temp = arr.front();
            arr.pop();
            if (temp->val == num1)
            {
                return true;
                break;
            }
            int size = root->children.size();
            for (int i = 0; i < size; i++)
            {
                if (isElementIn(root->children[i], num1))
                    return true;
            }
        }
        return false;
    }

    Node* find(Node* root, int num,int num1,bool flag)
    {
        queue<Node*> arr;
        arr.push(root);

        while (!arr.empty())
        {
            Node* helper = arr.front();
            arr.pop();

            if (helper->val == num)
            {

                return helper;
            }
            if (helper->val == num1)
            {
                flag = true;
                return helper;
            }

            for (int i = 0; i < helper->children.size(); i++)
            {
                arr.push(helper->children[i]);
            }
        }
        return root;
    }
    Node* find1(Node* root, int num)
    {
        queue<Node*> arr;
        arr.push(root);

        while (!arr.empty())
        {
            Node* helper = arr.front();
            arr.pop();

            if (helper->val == num)
            {

                return helper;
            }
            for (int i = 0; i < helper->children.size(); i++)
            {
                arr.push(helper->children[i]);
            }
        }
        return root;
    }

    Node* getRoot()
    {
        return root;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    Tree tr;
    for (int i = 0; i < N - 1; i++)
    {
        int first, second;
        cin >> first >> second;
        tr.root = tr.addElement(first, second);
    }
    int Q;
    cin >> Q;
    vector<string> answer;
    for (int i = 0; i < Q; i++)
    {
        int first, second;
        cin >> first >> second;
        if (first == tr.root->val)
        {
            answer.push_back("YES");
            continue;
        }
        else if (second == tr.root->val)
        {
            answer.push_back("NO");
            continue;
        }
        if (first == second)
        {
            answer.push_back("YES");
            continue;
        }
        bool flag = false;
        Node* temp = tr.find(tr.root, first,second,flag);
        if (flag == true)
        {
            answer.push_back("NO");
            continue;
        }
        if (tr.isElementIn(temp, second))
        {
            answer.push_back("YES");
        }
        else
        {
            answer.push_back("NO");
        }
    }

    for (int i = 0; i < Q; i++)
    {
        cout << answer[i] << "\n";
    }

    return 0;
}