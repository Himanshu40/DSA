#include <vector>
#include <utility>

class PriorityQueue {
    // Declare the data members here
    std::vector<int> pq;

   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
        pq.push_back(element);

        int childIndex {pq.size() - 1};

        while (childIndex > 0) {
            int parentIndex {(childIndex - 1) / 2};

            if (pq[parentIndex] < pq[childIndex]) {
                std::swap(pq[parentIndex], pq[childIndex]);
            }
            else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int getMax() {
        // Implement the getMax() function here
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    int removeMax() {
        // Implement the removeMax() function here
        if (isEmpty()) {
                return 0;
        }

        int ans {pq[0]};

        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        int parentIndex {0};

        int lci {2 * parentIndex + 1};
        int rci {2 * parentIndex + 2};

        while (lci < pq.size()) {
            int maxIndex {parentIndex};
                
            if (pq[maxIndex] < pq[lci]) {
                    maxIndex = lci;
            }

            if (rci < pq.size() && pq[rci] > pq[maxIndex]) {
                    maxIndex = rci;
            }

            if (maxIndex == parentIndex) {
                    break;
            }

            std::swap(pq[maxIndex], pq[parentIndex]);
            parentIndex = maxIndex;

            lci = 2 * parentIndex + 1;
            rci = 2 * parentIndex + 2;
        }

        return ans;
    }

    int getSize() { 
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return pq.size() == 0;
    }
};