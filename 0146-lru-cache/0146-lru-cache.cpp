class LRUCache {
public:

    class node {
    public:
        int key;
        int val;
        node* next;
        node* prev;

        node(int key, int val) {
            this->key = key;
            this->val = val;
            next = NULL;
            prev = NULL;
        }
    };

    node* head;
    node* tail;

    unordered_map<int, node*> mpp;

    int capacity;

    // Add node at the tail
    node* maintainTail(int key, int val) {

        node* newnode = new node(key, val);

        // Empty list
        if(head == NULL) {
            head = newnode;
            tail = newnode;
            return newnode;
        }

        // Add at tail
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;

        return newnode;
    }

    // Delete any node from DLL
    void deleteNode(node* getnode) {

        // Only one node
        if(head == tail) {
            head = NULL;
            tail = NULL;
            return;
        }

        // Delete head
        if(getnode == head) {
            head = head->next;
            head->prev = NULL;
            return;
        }

        // Delete tail
        if(getnode == tail) {
            tail = tail->prev;
            tail->next = NULL;
            return;
        }

        // Delete middle node
        getnode->prev->next = getnode->next;
        getnode->next->prev = getnode->prev;
    }

    // Remove least recently used node
    void removeLeastUsed() {

        node* temp = head;

        // Remove from hashmap
        mpp.erase(temp->key);

        // Remove from DLL
        deleteNode(temp);

        delete temp;
    }

    LRUCache(int capacity) {

        this->capacity = capacity;

        head = NULL;
        tail = NULL;
    }

    int get(int key) {

        // Key doesn't exist
        if(!mpp.count(key))
            return -1;

        node* getnode = mpp[key];

        int value = getnode->val;

        // Remove from current position
        deleteNode(getnode);

        // Put at tail = recently used
        node* newnode = maintainTail(key, value);

        // Update hashmap
        mpp[key] = newnode;

        // Delete old node
        delete getnode;

        return value;
    }

    void put(int key, int value) {

        // Key already exists
        if(mpp.count(key)) {

            node* getnode = mpp[key];

            // Remove old node
            deleteNode(getnode);

            // Add updated node at tail
            node* newnode = maintainTail(key, value);

            // Update hashmap
            mpp[key] = newnode;

            // Delete old node
            delete getnode;

            return;
        }

        // Cache is full
        if(mpp.size() == capacity) {
            removeLeastUsed();
        }

        // Add new node at tail
        node* newnode = maintainTail(key, value);

        // Add to hashmap
        mpp[key] = newnode;
    }
};