class LRUCache {
public:
    // Doubly Linked List Node
    class Node {
    public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int key, int value) {
            this->key = key;
            this->value = value;
            prev = NULL;
            next = NULL;
        }
    };

    Node* head;
    Node* tail;

    // key -> address of node
    unordered_map<int, Node*> mp;

    int capacity;

    // Add node just after head
    void addNode(Node* newNode) {
        Node* temp = head->next;

        newNode->next = temp;
        newNode->prev = head;

        head->next = newNode;
        temp->prev = newNode;
    }

    // Delete node from DLL
    void deleteNode(Node* delNode) {
        Node* prevNode = delNode->prev;
        Node* nextNode = delNode->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    LRUCache(int capacity) {
        this->capacity = capacity;

        // Dummy nodes
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {

        // Key doesn't exist
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* resNode = mp[key];

        int ans = resNode->value;

        // Remove from current position
        deleteNode(resNode);

        // Add at front = Most Recently Used
        addNode(resNode);

        return ans;
    }
    
    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {

            Node* existingNode = mp[key];

            // Remove old node
            deleteNode(existingNode);

            // Remove from hashmap
            mp.erase(key);
        }

        // If capacity is full
        if (mp.size() == capacity) {

            // Least Recently Used node
            Node* lruNode = tail->prev;

            // Remove from DLL
            deleteNode(lruNode);

            // Remove from hashmap
            mp.erase(lruNode->key);

            delete lruNode;
        }

        // Create new node
        Node* newNode = new Node(key, value);

        // Add to hashmap
        mp[key] = newNode;

        // Add at front = Most Recently Used
        addNode(newNode);
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */