class MyCircularDeque {
public:

    class Node {
    public:
        int val;
        Node* next;
        Node* prev;

        Node(int val) {
            this->val = val;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* front;
    Node* rare;

    int size;
    int count;

    MyCircularDeque(int k) {
        size = k;
        count = 0;

        front = nullptr;
        rare = nullptr;
    }
    
    bool insertFront(int value) {

        if(isFull()) return false;

        Node* newnode = new Node(value);

        if(count == 0) {
            front = newnode;
            rare = newnode;
        }
        else {
            newnode->next = front;
            front->prev = newnode;
            front = newnode;
        }

        count++;
        return true;
    }
    
    bool insertLast(int value) {

        if(isFull()) return false;

        Node* newnode = new Node(value);

        if(count == 0) {
            front = newnode;
            rare = newnode;
        }
        else {
            rare->next = newnode;
            newnode->prev = rare;
            rare = newnode;
        }

        count++;
        return true;
    }
    
    bool deleteFront() {

        if(isEmpty()) return false;

        Node* deleteNode = front;

        if(count == 1) {
            front = nullptr;
            rare = nullptr;
        }
        else {
            front = front->next;
            front->prev = nullptr;
        }

        delete deleteNode;
        count--;

        return true;
    }
    
    bool deleteLast() {

        if(isEmpty()) return false;

        Node* deleteNode = rare;

        if(count == 1) {
            front = nullptr;
            rare = nullptr;
        }
        else {
            rare = rare->prev;
            rare->next = nullptr;
        }

        delete deleteNode;
        count--;

        return true;
    }
    
    int getFront() {

        if(isEmpty()) return -1;

        return front->val;
    }
    
    int getRear() {

        if(isEmpty()) return -1;

        return rare->val;
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == size;
    }
};