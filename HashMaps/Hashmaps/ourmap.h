#include <string>

template <typename V>
class MapNode {
    public:
        std::string key;
        V value;
        MapNode *next;

        MapNode(std::string key, V value)
            : key {key}, value {value}, next {nullptr} {}

        ~MapNode() {
            delete next;
        }
};

template <typename V>
class Ourmap {
    MapNode<V> **buckets;
    int count;
    int numBuckets;

    int getBucketIndex(std::string key) {
        int hashCode {0};
        int coefficient {1};

        for (int i {static_cast<int>(key.length() - 1)}; i >= 0; --i) {
            hashCode += key[i] * coefficient;
            hashCode %= numBuckets;
            coefficient *= 37;
            coefficient %= numBuckets;
        }

        return hashCode % numBuckets;
    }

    void rehash() {
        MapNode<V> **temp {buckets};
        buckets = new MapNode<V>*[2 * numBuckets];

        for (int i {0}; i < 2 * numBuckets; ++i) {
            buckets[i] = nullptr;
        }

        int oldBucketCount {numBuckets};
        numBuckets *= 2;
        count = 0;

        for (int i {0}; i < oldBucketCount; ++i) {
            MapNode<V> *head {temp[i]};

            while (head != nullptr) {
                std::string key {head->key};
                V value {head->value};
                insert(key, value);

                head = head->next;
            }
        }

        for (int i {0}; i < oldBucketCount; ++i) {
            MapNode<V> *head {temp[i]};
            delete head;
        }

        delete [] temp;
    }

    public:
        Ourmap()
            : count {0}, numBuckets {5} {
                buckets = new MapNode<V>*[numBuckets];

                for (int i {0}; i < numBuckets; ++i) {
                    buckets[i] = nullptr;
                }
            }

        ~Ourmap() {
            for (int i {0}; i < numBuckets; ++i) {
                delete buckets[i];    
            }

            delete [] buckets;
        }

        int size() {
            return count;
        }

        void insert(std::string key, V value) {
            int bucketIndex {getBucketIndex(key)};
            MapNode<V> *head {buckets[bucketIndex]};

            while (head != nullptr) {
                if (head->key == key) {
                    head->value = value;

                    return;
                }

                head = head->next;
            }

            head = buckets[bucketIndex];
            MapNode<V> *node {new MapNode<V>(key, value)};

            node->next = head;
            buckets[bucketIndex] = node;
            ++count;

            double loadFactor {static_cast<double>(count) / numBuckets};

            if (loadFactor > 0.7) {
                rehash();
            }
        }

        V getValue(std::string key) {
            int bucketIndex {getBucketIndex(key)};
            MapNode<V> *head {buckets[bucketIndex]};

            while (head != nullptr) {
                if (head->key == key) {
                    return head->value;
                }

                head = head->next;
            }

            return 0;
        }

        V remove(std::string key) {
            int bucketIndex {getBucketIndex(key)};
            MapNode<V> *head {buckets[bucketIndex]};
            MapNode<V> *prev {nullptr};

            while (head != nullptr) {
                if (head->key == key) {
                    if (prev == nullptr) {
                        buckets[bucketIndex] = head->next;
                    }
                    else {
                        prev->next = head->next;
                    }

                    V value {head->value};
                    head->next = nullptr;
                    delete head;
                    --count;

                    return value;
                }
                
                prev = head;
                head = head->next;
            }

            return 0;
        }

        double getLoadFactor() {
            return static_cast<double>(count) / numBuckets;
        }
};
