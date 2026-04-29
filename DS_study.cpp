#include <iostream>
using namespace std;
// insertion sort
void insertionsort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {

        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// selection sort
void selectionsort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int least = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[least])
            {
                least = j;
            }
            swap(arr[least], arr[i]);
        }
    }
}
//    bubble sort
void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
// shell sort
void shellsort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}
// merge sort
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = new int[n1];
    int *R = new int[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = 0;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }
    while (i < n1)
    {
        arr[k++] = L[i++];
    }
    while (j < n2)
    {
        arr[k++] = R[j++];
    }
}
void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
// quick sort
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    for (int j = low + 1; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i], arr[low]);
    return i;
}
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// radix sort
int getmax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
void countsort(int arr[], int n, int exp)
{
    int *output = new int[n];
    int count[10] = {0};
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixsort(int arr[], int n)
{
    int m = getmax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countsort(arr, n, exp);
}
// #include <stack>
// int binarytodecimal(int n)
// {
//     stack<int> s;

//     while (n > 0)
//     {
//         int digit = n % 10;

//         if (digit != 0 && digit != 1)
//         {
//             cout << "Invalid binary number";
//             return -1;
//         }

//         s.push(digit);
//         n /= 10;
//     }

//     int decimal = 0;

//     while (!s.empty())
//     {
//         decimal = decimal * 2 + s.top();
//         s.pop();
//     }

//     return decimal;
// }

// find the maximum product of two integers in an array
int maxproduct(int arr[], int n)
{
    int max1 = arr[0], max2 = arr[1];
    for (int i = 2; i < n; i++)
    {
        if (arr[i] > max1)
        {
            max2 = max1;
            max1 = arr[i];
        }
        else if (arr[i] > max2)
        {
            max2 = arr[i];
        }
    }
    return max1 * max2;
}

//    linked list
class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};
class newnode
{
public:
    Node *head;
    newnode() : head(nullptr) {}
    void insert(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void reverse()
    {
        Node *prev = nullptr, *current = head, *next = nullptr;
        while (current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    void deleteNode(int key)
    {
        Node *temp = head, *prev = nullptr;
        if (temp != nullptr && temp->data == key)
        {
            head = temp->next;
            delete temp;
            return;
        }
        while (temp != nullptr && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr)
            return;
        prev->next = temp->next;
        delete temp;
    }
    void insertAtPosition(int val, int pos)
    {
        Node *newNode = new Node(val);
        if (pos == 0)
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node *temp = head;
        for (int i = 0; temp != nullptr && i < pos - 1; i++)
        {
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            cout << "Position out of bounds" << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
};
class node
{
public:
    int data;
    node *next;
};

class stack
{
private:
    node *top;

public:
    stack()
    {
        top = nullptr;
    }

    void push(int x)
    {
        node *temp = new node();
        temp->data = x;
        temp->next = top;
        top = temp;
    }

    void pop()
    {
        if (top == nullptr)
        {
            cout << "Stack underflow" << endl;
            return;
        }
        node *temp = top;
        top = top->next;
        delete temp;
    }
    int first()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }
};

class queue
{
private:
    node *head, *tail;

public:
    queue()
    {
        head = tail = nullptr;
    }
    void enqueue(int x)
    {
        node *temp = new node();
        temp->data = x;
        temp->next = nullptr;
        if (tail)
        {
            tail->next = temp;
        }
        tail = temp;
        if (!head)
        {
            head = tail;
        }
    }
    void dequeue()
    {
        if (!head)
        {
            cout << "Queue underflow" << endl;
            return;
        }
        node *temp = head;
        head = head->next;
        delete temp;
        if (!head)
        {
            tail = nullptr;
        }
    }
    int front()
    {
        if (!head)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return head->data;
    }
};

void print(stack s)
{
    while (s.first() != -1)
    {
        cout << s.first() << " ";
        s.pop();
    }
    cout << endl;
}
int postfix(string s)
{
    stack st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int op2 = st.first();
            st.pop();
            int op1 = st.first();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            }
        }
    }
    return st.first();
}
// Queue Array based
template <class T, int size = 100>
class Queue
{
private:
    T arr[size];
    int front, rear;

public:
    Queue()
    {
        front = 0;
        rear = -1;
    }

    bool isEmpty()
    {
        return front > rear;
    }

    bool isFull()
    {
        return rear == size - 1;
    }

    void enqueue(T x)
    {
        if (isFull())
        {
            cout << "Queue overflow" << endl;
            return;
        }
        arr[++rear] = x;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue underflow" << endl;
            return;
        }
        front++;
    }

    T first()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return T();
        }
        return arr[front];
    }
};
// circular queue
template <class T, int size = 100>
class circularQueue
{
private:
    T arr[size];
    int front, rear;

public:
    circularQueue()
    {
        front = rear = -1;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (rear + 1) % size == front;
    }

    void enqueue(T x)
    {
        if (isFull())
        {
            cout << "Queue overflow" << endl;
            return;
        }

        if (isEmpty())
            front = 0;

        rear = (rear + 1) % size;
        arr[rear] = x;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue underflow" << endl;
            return;
        }

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
    }

    T first()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return T();
        }
        return arr[front];
    }
};
// queue using SLL

// ================= Generic Node2 =================
template <typename T>
class Node2
{
public:
    T data;
    Node2<T> *next;

    Node2(T value)
    {
        data = value;
        next = nullptr;
    }
};

// ================= Generic Queue =================
template <typename T>
class QueueSLL
{
private:
    Node2<T> *front;
    Node2<T> *rear;

public:
    QueueSLL()
    {
        front = rear = nullptr;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    // enqueue
    void enqueue(T value)
    {
        Node2<T> *temp = new Node2<T>(value);

        if (isEmpty())
        {
            front = rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }

    // dequeue
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue underflow\n";
            return;
        }

        Node2<T> *temp = front;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete temp;
    }

    // get first element
    T first()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return T();
        }
        return front->data;
    }

    void remove(T value)
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }

        Node2<T> *curr = front;
        Node2<T> *prev = nullptr;

        while (curr != nullptr)
        {
            if (curr->data == value)
            {

                if (prev == nullptr)
                {
                    front = curr->next;
                    if (front == nullptr)
                        rear = nullptr;
                }
                else
                {
                    prev->next = curr->next;

                    if (curr == rear)
                        rear = prev;
                }

                delete curr;
                cout << "Element removed\n";
                return;
            }

            prev = curr;
            curr = curr->next;
        }

        cout << "Element not found\n";
    }
};
// Priority Queue using array
template <class T, int size = 100>
class PriorityQueue
{
private:
    T arr[size];
    int n; // عدد العناصر

public:
    PriorityQueue()
    {
        n = 0;
    }

    bool isEmpty()
    {
        return n == 0;
    }

    bool isFull()
    {
        return n == size;
    }

    // إضافة عنصر
    void push(T x)
    {
        if (isFull())
        {
            cout << "Overflow\n";
            return;
        }
        arr[n++] = x;
    }

    T top()
    {
        if (isEmpty())
        {
            cout << "Empty\n";
            return T();
        }

        int mxIndex = 0;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > arr[mxIndex])
                mxIndex = i;
        }

        return arr[mxIndex];
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Underflow\n";
            return;
        }

        int mxIndex = 0;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > arr[mxIndex])
                mxIndex = i;
        }

        arr[mxIndex] = arr[n - 1];
        n--;
    }
};

// Trees
template <class T>
class BSTNode
{
private:
    T key;
    BSTNode *left;
    BSTNode *right;

public:
    BSTNode() : left(nullptr), right(nullptr) {}

    BSTNode(T el, BSTNode *l = nullptr, BSTNode *r = nullptr)
    {
        key = el;
        left = l;
        right = r;
    }

    BSTNode *getLeft() { return left; }
    BSTNode *getRight() { return right; }
    T &getKey() { return key; }

    void setLeft(BSTNode *l) { left = l; }
    void setRight(BSTNode *r) { right = r; }
};

template <class T>
class BST
{
protected:
    BSTNode<T> *root;

    // ================= DFS Traversals =================
    void inorder(BSTNode<T> *node)
    {
        if (!node)
            return;
        inorder(node->getLeft());
        cout << node->getKey() << " ";
        inorder(node->getRight());
    }

    void preorder(BSTNode<T> *node)
    {
        if (!node)
            return;
        cout << node->getKey() << " ";
        preorder(node->getLeft());
        preorder(node->getRight());
    }

    void postorder(BSTNode<T> *node)
    {
        if (!node)
            return;
        postorder(node->getLeft());
        postorder(node->getRight());
        cout << node->getKey() << " ";
    }

    // ================= Helper for deletion =================
  template<class T>
void BST<T>::deleteByCopying(BSTNode<T>* &node) 
{
    BSTNode<T> *prev, *tmp = node;   

    // Case 1: Node has NO RIGHT child
    if (node->right == nullptr) {           
        node = node->left;                  // Replace node with its left child
    }

    // Case 2: Node has NO LEFT child
    else if (node->left == nullptr) {
        node = node->right;                 // Replace node with its right child
    }

    // Case 3: Node has BOTH LEFT and RIGHT children  
    else {
        tmp = node->left;                   
        prev = node;                        // prev will track parent of tmp

        // Step 2: Find the RIGHTMOST node in the left subtree
        // (This is the Inorder Predecessor)
        while (tmp->right != nullptr) {
            prev = tmp;
            tmp = tmp->right;
        }

        // Step 3: Copy the predecessor's key into the node we want to delete
        node->key = tmp->key;

        // Step 4 & 5: Delete the predecessor (tmp)
        if (prev == node) {
            // This means the predecessor was the direct left child
            prev->left = tmp->left;
        } else {
            // Predecessor was deeper in the right chain
            prev->right = tmp->left;
        }
    }

    delete tmp;   // Free the memory of the deleted node
}

public:
    BST() : root(nullptr) {}

    // ================= INSERT =================
    void insert(T el)
    {
        BSTNode<T> *newNode = new BSTNode<T>(el);

        if (!root)
        {
            root = newNode;
            return;
        }

        BSTNode<T> *p = root;
        BSTNode<T> *prev = nullptr;

        while (p)
        {
            prev = p;
            if (el < p->getKey())
                p = p->getLeft();
            else
                p = p->getRight();
        }

        if (el < prev->getKey())
            prev->setLeft(newNode);
        else
            prev->setRight(newNode);
    }

    // ================= BFS =================
    void levelOrder()
    {
        if (!root)
            return;

        queue<BSTNode<T> *> q;
        q.push(root);

        while (!q.empty())
        {
            BSTNode<T> *node = q.front();
            q.pop();

            cout << node->getKey() << " ";

            if (node->getLeft())
                q.push(node->getLeft());
            if (node->getRight())
                q.push(node->getRight());
        }
    }

    // ================= DFS =================
    void inorder() { inorder(root); }
    void preorder() { preorder(root); }
    void postorder() { postorder(root); }

    // ================= DELETE =================
    void remove(T key)
    {
        root = deleteNode(root, key);
    }

    // ================= SUCCESSOR =================
    BSTNode<T> *successor(T key)
    {
        BSTNode<T> *curr = root;
        BSTNode<T> *succ = nullptr;

        while (curr)
        {
            if (key < curr->getKey())
            {
                succ = curr;
                curr = curr->getLeft();
            }
            else
                curr = curr->getRight();
        }
        return succ;
    }

    // ================= PREDECESSOR =================
    BSTNode<T> *predecessor(T key)
    {
        BSTNode<T> *curr = root;
        BSTNode<T> *pred = nullptr;

        while (curr)
        {
            if (key > curr->getKey())
            {
                pred = curr;
                curr = curr->getRight();
            }
            else
                curr = curr->getLeft();
        }
        return pred;
    }
};

class Ticket
{
public:
    int id;
    string name;
    string from;
    string to;

    Ticket(int id = -1, string name = "", string from = "", string to = "")
    {
        this->id = id;
        this->name = name;
        this->from = from;
        this->to = to;
    }

    bool operator==(const Ticket &other) const
    {
        return id == other.id;
    }
};

int main()
{
    QueueSLL<Ticket> q;

    q.enqueue(Ticket(1, "Ali"));
    q.enqueue(Ticket(2, "Sara"));

    q.remove(Ticket(2, "")); // compare by id
}