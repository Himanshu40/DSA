#include <iostream>

using namespace std;

template <typename T>
class Node {
    public:
        T data;
        Node<T> *next;

        Node(T data);
};

template <typename T>
Node<T>::Node(T data)
    : data {data}, next {nullptr} {}

template <typename T>
class Queue {
    private:
        Node<T> *head;
        Node<T> *tail;
        int size;
    public:
        Queue();

        int getSize() const;
        bool isEmpty() const;
        int front() const;

        void enqueue(T element);
        T dequeue();
};

template <typename T>
Queue<T>::Queue()
    : head {nullptr}, tail {nullptr}, size {0} {}

template <typename T>
int Queue<T>::getSize() const {
    return size;
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return !size;
}

template <typename T>
int Queue<T>::front() const {
    if (!head) {
        return 0;
    }

    return head->data;
}

template <typename T>
void Queue<T>::enqueue(T element) {
    Node<T> *newNode {new Node<T>(element)};
    
    if (!head) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }

    ++size;
}

template <typename T>
T Queue<T>::dequeue() {
    if (!head) {
        return 0;
    }

    T store {head->data};
    Node<T> *temp {head};

    head = head->next;
    delete temp;
    --size;

    return store;
}

int main() {
    Queue<int> q;

    int t;
    cin >> t;

    while (t--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                q.enqueue(input);
                break;
            case 2:
                cout << q.dequeue() << "\n";
                break;
            case 3:
                cout << q.front() << "\n";
                break;
            case 4:
                cout << q.getSize() << "\n";
                break;
            default:
                cout << ((q.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }

    return 0;
}
