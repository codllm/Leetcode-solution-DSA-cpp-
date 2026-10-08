class BrowserHistory {
public:

    struct Node {
        string url;
        Node* next;
        Node* prev;

        Node(string link) {
            url = link;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* curnt; // current page

    BrowserHistory(string homepage) {
        Node* newNode = new Node(homepage);
        curnt = newNode;
    }
    
    void visit(string url) {

        Node* newLink = new Node(url);

        // delete forward history automatically by breaking link
        curnt->next = newLink;
        newLink->prev = curnt;

        // move current
        curnt = newLink;
    }
    
    string back(int steps) {

        while(steps > 0 && curnt->prev != nullptr) {
            curnt = curnt->prev;
            steps--;
        }

        return curnt->url;
    }
    
    string forward(int steps) {

        while(steps > 0 && curnt->next != nullptr) {
            curnt = curnt->next;
            steps--;
        }

        return curnt->url;
    }
};