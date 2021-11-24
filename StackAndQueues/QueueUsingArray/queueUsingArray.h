#include <iostream>

template <typename T>
class QueueUsingArray {
    private:
        T *data;
        int nextIndex;
        int frontIndex;
        int size;
        int capacity;
    public:
        QueueUsingArray(int s);
        ~QueueUsingArray();

        int getSize() const;
        bool isEmpty() const;
        T front() const;

        void enqueue(T element);
        T dequeue();
};

template <typename T>
QueueUsingArray<T>::QueueUsingArray(int s)
    : data {new T[s]}, nextIndex {0}, frontIndex {-1}, size {0}, capacity {s} {}

template <typename T>
QueueUsingArray<T>::~QueueUsingArray() {
    delete []data;
}

template <typename T>
int QueueUsingArray<T>::getSize() const {
    return size;
}

template <typename T>
bool QueueUsingArray<T>::isEmpty() const {
    return !size;
}

template <typename T>
T QueueUsingArray<T>::front() const {
    if (frontIndex == -1) {
        std::cout << "Queue is empty!!!" << std::endl;

        return 0;
    }

    return data[frontIndex];
}

template <typename T>
void QueueUsingArray<T>::enqueue(T element) {
    if (size == capacity) {
        std::cout << "Queue full" << std::endl;
        return;
    }

    data[nextIndex] = element;
    nextIndex = (nextIndex + 1) % capacity;

    if (frontIndex == -1) {
        frontIndex = 0;
    }
    ++size;
}

template <typename T>
T QueueUsingArray<T>::dequeue() {
    if (isEmpty()) {
        std::cout << "Queue is empty!!!" << std::endl;

        return 0;
    }

    T ans = data[frontIndex];
    frontIndex = (frontIndex + 1) % capacity;
    size--;

    if (!size) {
        frontIndex = -1;
        nextIndex = 0;
    }

    return ans;
}
