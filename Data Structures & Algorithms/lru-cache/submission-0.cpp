class Node{
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int k, int v){
        key = k;
        val = v;
        prev = NULL;
        next = NULL;
    }
};

// Create a DLL with head and tail 

// Map: To calculate size, delete from map

class LRUCache {

private:
    int capacity;
    unordered_map<int, Node*>mp;
    Node* head;
    Node* tail;

    void remove(Node* node){ // Remove the LRU (Before right)
        Node* prevNode = node->prev;
        Node* nxtNode = node->next;

        prevNode->next = nxtNode;
        nxtNode->prev = prevNode;
    }

    void insert(Node* node){ // Insert after left
        Node* nextNode = head->next;

        head->next = node;
        node->prev = head;
        node->next = nextNode;
        nextNode->prev = node;
    }

public:

    LRUCache(int cap) {
        capacity = cap;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
        
    }
    
    int get(int key) {
        // 1. get value from map
        // 2. Make it recently used:
            // Delete from tails prev, and make it after head

        int ans = -1;
        if(mp.find(key)!=mp.end()){
            Node* node = mp[key];
            remove(node);
            insert(node);
            ans = node->val;
        }
        return ans;

    }
    
    void put(int key, int value) {
        // If already found, update the value

        if(mp.find(key)!=mp.end()){
            Node* node = mp[key];
            node->val = value;
            remove(node);
            insert(node);
            return;
        }
        // If not found;
        if(mp.size()>=capacity){ // Remove and insert new 
            Node* toRemove = tail->prev;
            remove(toRemove); // Removed LRU
            mp.erase(toRemove->key); // Removed from map
        }
        Node* newNode = new Node(key, value);
        insert(newNode);
        mp[key] = newNode;
    }
};
