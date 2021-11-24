#include <iostream>

template <typename T>
class StackUsingArray {
    private:
        T *data;
        int nextIndex;
        int capacity;
    public:
        StackUsingArray();
        ~StackUsingArray();
        
        int size() const;
        bool isEmpty() const;

        void push(T value);
        T pop();
        T top() const;
};

template <typename T>
StackUsingArray<T>::StackUsingArray() 
    : data {new T[4]}, capacity {4}, nextIndex {0} {}

template <typename T>
StackUsingArray<T>::~StackUsingArray() {
    delete []data;
}

template <typename T>
int StackUsingArray<T>::size() const {
    return nextIndex;
}

template <typename T>
bool StackUsingArray<T>::isEmpty() const {
    return !nextIndex;
}

template <typename T>
void StackUsingArray<T>::push(T value) {
    if (nextIndex == capacity) {
       T *newData = new T[capacity * 2];

       for (int i {0}; i < capacity; ++i) {
           newData[i] = data[i];
       }

       capacity *= 2;

       delete []data;
       data = newData;
    }

    data[nextIndex++] = value;
}

template <typename T>
T StackUsingArray<T>::pop() {
    if (isEmpty()) {
        std::cout << "Stack is empty" << std::endl;
        
        return 0;
    }
    
    return data[--nextIndex];
}

template <typename T>
T StackUsingArray<T>::top() const {
    if (isEmpty()) {
        std::cout << "Stack is empty" << std::endl;

        return 0;
    }

    return data[nextIndex - 1];
}

int main() {
    StackUsingArray<float> obj1;

    obj1.push(10.1);
    obj1.push(20.2);
    obj1.push(30.3);
    obj1.push(40.4);
    obj1.push(50.5);
    obj1.push(60.6);

    std::cout << obj1.top() << std::endl;
    
    std::cout << obj1.pop() << std::endl;
    std::cout << obj1.pop() << std::endl;
    std::cout << obj1.pop() << std::endl;
    
    std::cout << obj1.size() << std::endl;
    std::cout << std::boolalpha << obj1.isEmpty() << std::endl;

    return 0;
}
