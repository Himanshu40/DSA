#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Triplet {
    public:
        int element;
        int arrayIndex;
        int elementIndex;

        Triplet(int element, int arrayIndex, int elementIndex)
            : element {element}, arrayIndex {arrayIndex}, elementIndex {elementIndex} {}
};

class Compare {
    public:
        bool operator()(const Triplet &num1, const Triplet &num2) {
            return num1.element > num2.element;
        }
};


vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    if (input.empty() == true) {
        return {};
    }

    priority_queue<Triplet, vector<Triplet>, Compare> pq;

    for (int i {0}; i < input.size(); ++i) {
        Triplet a(input.at(i)->at(0), i, 0);
        pq.push(a);
    }

    vector<int> mergeArrays;

    while (pq.empty() != true) {
        Triplet temp {pq.top()};
        mergeArrays.push_back(pq.top().element);
        pq.pop();

        if (temp.elementIndex < input[temp.arrayIndex]->size() - 1) {
            Triplet newElement(input[temp.arrayIndex]->at(temp.elementIndex + 1), temp.arrayIndex, temp.elementIndex + 1);
            pq.push(newElement);
        }
    }


    return mergeArrays;
}

int main() {
    int k;
    cin >> k;

    vector<vector<int> *> input;

    for (int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;

        for (int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current->push_back(a);
        }

        input.push_back(current);
    }

    // vector<int> output = 
    mergeKSortedArrays(input);

    // for (int i = 0; i < output.size(); i++) {
    //     cout << output[i] << " ";
    // }

    return 0;
}