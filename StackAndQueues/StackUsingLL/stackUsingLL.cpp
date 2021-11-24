#include <iostream>

template <typename T>
class Node {
    public:
        T data;
        Node<T> *next;

        Node(T data) : data {data}, next {nullptr} {}
};

template <typename T>
class Stack {
    private:
        Node<T> *head;
        int size;
    public:
        Stack() : head {nullptr}, size {0} {}

        int getSize() const {
            return size;
        }

        bool isEmpty() {
            return !size;
        }

        void push(T element) {
            Node<T> *newNode {new Node<T>(element)};
            
            newNode->next = head;
            head = newNode;
            ++size;
        }

        T pop() {
            if (!head) {
                return -1;
            }

            T store {head->data};
            Node<T> *temp {head};

            head = head->next;
            delete temp;
            --size;

            return store;
        }

        T top() {
            if (!head) {
                return -1;
            }

            return head->data;
        }
};

int main() {
    Stack<int> st;

    int q;
    std::cin >> q;

    while (q--) {
        int choice, input;
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cin >> input;
                st.push(input);
                break;
            case 2:
                std::cout << st.pop() << "\n";
                break;
            case 3:
                std::cout << st.top() << "\n";
                break;
            case 4:
                std::cout << st.getSize() << "\n";
                break;
            default:
                std::cout << ((st.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }

    return 0;
}
