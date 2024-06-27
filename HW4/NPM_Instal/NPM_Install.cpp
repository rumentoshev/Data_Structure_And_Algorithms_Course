#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

struct Node
{
    int value;
    Node* next = nullptr;
    Node* prev = nullptr;

    Node(int val)
    {
        this->value = val;
    }
};

class DoublyLinkedList
{
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    void copyFrom(const DoublyLinkedList& other)
    {

        Node* otherIter = other.head;
        while (otherIter != nullptr)
        {
            pushBack(otherIter->value);
            otherIter = otherIter->next;
        }
    }
    void free()
    {
        Node* iter = head;
        while (iter != nullptr)
        {
            Node* toDelete = iter;
            iter = iter->next;
            delete toDelete;
        }

        head = tail = nullptr;
    }
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr)
    {}
    ~DoublyLinkedList()
    {
        free();
    }
    DoublyLinkedList(const DoublyLinkedList& other) : head(nullptr), tail(nullptr)
    {
        copyFrom(other);
    }
    DoublyLinkedList& operator=(const DoublyLinkedList& other)
    {
        if (this != &other)
        {
            free();
            copyFrom(other);
        }
        return *this;
    }

    void pushBack(const int el)
    {
        Node* added = new Node(el);
        if (isEmpty())
            head = tail = added;
        else
        {
            tail->next = added;
            added->prev = tail;
            tail = added;
        }
    }
    void pushFront(const int& el)
    {
        Node* added = new Node(el);
        if (isEmpty())
        {
            head = tail = added;
        }
        else
        {
            added->next = head;
            head->prev = added;
            head = added;
        }
    }

    void popBack()
    {
        if (isEmpty())
            throw std::runtime_error("The list is empty!");

        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            tail->prev->next = nullptr;

            Node* toDelete = tail;
            tail = tail->prev;

            delete toDelete;
        }
    }
    void popFront()
    {
        if (isEmpty())
            throw std::runtime_error("The list is empty!");


        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            head->next->prev = nullptr;

            Node* toDelete = head;
            head = head->next;

            delete toDelete;
        }
    }

    bool isEmpty() const
    {
        return head == nullptr && tail == nullptr;
    }

    void remove(Node* el)
    {
        if (isEmpty())
        {
            throw std::runtime_error("The list is empty!");
        }
        if (el == tail)
        {
            popBack();
            return;
        }
        else if (el == head)
        {
            popFront();
            return;
        }
        else
        {
            Node* toDel = el;
            Node* temp_next = el->next;
            Node* temp_prev = el->prev;
            temp_prev->next = temp_next;
            temp_next->prev = temp_prev;

            delete toDel;
        }
    }
    Node* getHead() const
    {
        return head;
    }
    Node* getTail() const
    {
        return tail;
    }
};

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numberOfInstalls, capacity;
    cin >> numberOfInstalls >> capacity;
    DoublyLinkedList list;
    vector<int> installsOrder(numberOfInstalls);
    for (int i = 0; i < numberOfInstalls; ++i)
    {
        int temp;
        cin >> temp;
        installsOrder[i] = temp;
    }
    vector<Node*> arrToCheck(100001);
    int counter = 0;
    for (int i = 0; i < numberOfInstalls; ++i)
    {
        if (counter<capacity)
        {
            if (arrToCheck[installsOrder[i]] == nullptr)
            {
                list.pushFront(installsOrder[i]);
                arrToCheck[installsOrder[i]] = list.getHead();
                counter++;
                cout << "false"<<"\n";
            }
            else
            {
                list.remove(arrToCheck[installsOrder[i]]);
                list.pushFront(installsOrder[i]);
                arrToCheck[installsOrder[i]] = list.getHead();
                cout << "true" << "\n";
            }
        }
        else if(counter == capacity)
        {
            if (arrToCheck[installsOrder[i]] == nullptr)
            {
                int temp = list.getTail()->value;
                arrToCheck[temp] = nullptr;
                list.popBack();
                list.pushFront(installsOrder[i]);
                arrToCheck[installsOrder[i]] = list.getHead();
                cout << "false" << "\n";
            }
            else
            {
                list.remove(arrToCheck[installsOrder[i]]);
                list.pushFront(installsOrder[i]);
                arrToCheck[installsOrder[i]] = list.getHead();
                cout << "true" << "\n";
            }
        }
        Node* j = list.getHead();
        while (j != nullptr)
        {
            cout << j->value << " ";
            j = j->next;
        }
        cout << "\n";
    }

    return 0;
}