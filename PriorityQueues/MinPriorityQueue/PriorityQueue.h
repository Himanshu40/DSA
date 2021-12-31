#include <vector>
#include <utility>

class PriorityQueue {
        std::vector<int> pq;
    public:
        PriorityQueue() {}

        bool isEmpty() {
            return pq.empty();
        }

        int getSize() {
            return pq.size();
        }

        int getMin() {
            if (isEmpty()) {
                return 0;
            }

            return pq[0];
        }

        void insert(int element) {
            pq.push_back(element);

            auto childIndex  {pq.size() - 1};

            while (childIndex > 0) {
                auto parentIndex {(childIndex - 1) / 2};

                if (pq[childIndex] < pq[parentIndex]) {
                    int temp {pq[childIndex]};

                    pq[childIndex] = pq[parentIndex];
                    pq[parentIndex] = temp;
                }
                else {
                    break;
                }

                childIndex = parentIndex;
            }
        }

        int removeMin() {
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
                int minIndex {parentIndex};
                
                if (pq[minIndex] > pq[lci]) {
                    minIndex = lci;
                }

                if (rci < pq.size() && pq[rci] < pq[minIndex]) {
                    minIndex = rci;
                }

                if (minIndex == parentIndex) {
                    break;
                }

                std::swap(pq[minIndex], pq[parentIndex]);
                parentIndex = minIndex;

                lci = 2 * parentIndex + 1;
                rci = 2 * parentIndex + 2;
            }

            return ans;
        }
};
