class LRUCache {
public:

    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int key, int val) {
            this->key = key;
            this->val = val;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* head;
    Node* tail;

    int capacity;

    unordered_map<int, Node*> mpp;

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = nullptr;
        tail = nullptr;
    }

    // Add node at the end = most recently used
    void addNode(Node* newNode) {

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // Remove a node from linked list
    void deleteNode(Node* cur) {

        if (cur == head) {
            head = cur->next;

            if (head != nullptr)
                head->prev = nullptr;
        }
        else if (cur == tail) {
            tail = cur->prev;

            if (tail != nullptr)
                tail->next = nullptr;
        }
        else {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
        }
    }

    // Move node to most recently used position
    void moveToTail(Node* cur) {

        if (cur == tail)
            return;

        deleteNode(cur);
        addNode(cur);
    }

    int get(int key) {

        if (!mpp.count(key))
            return -1;

        Node* cur = mpp[key];

        // Accessing it makes it recently used
        moveToTail(cur);

        return cur->val;
    }

    void put(int key, int value) {

        // Key already exists
        if (mpp.count(key)) {

            Node* cur = mpp[key];

            cur->val = value;

            // It becomes recently used
            moveToTail(cur);

            return;
        }

        // Create new node
        Node* newNode = new Node(key, value);

        addNode(newNode);
        mpp[key] = newNode;

        if (mpp.size() > capacity) {

            Node* leastRecentlyUsed = head;

            mpp.erase(leastRecentlyUsed->key);

            deleteNode(leastRecentlyUsed);

            delete leastRecentlyUsed;
        }
    }
};