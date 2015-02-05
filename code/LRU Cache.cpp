struct LinkedListNode {
    LinkedListNode(): pre(nullptr), next(nullptr) { }
    int key, value;
    LinkedListNode *pre, *next;
};

class LRUCache{
public:
    LRUCache(int capacity): capacity(capacity) {
        head.next = &tail;
        tail.pre = &head;
    }

    ~LRUCache() {
    	for (LinkedListNode *node = head.next; node != &tail; node = head.next) {
    		head.next = node->next;
    		delete node;
    	}
    }

    int get(int key) {
        if (hashtable.find(key) != hashtable.end()) {
            LinkedListNode* node = hashtable[key];
            erase(node), push(node);
            return node->value;
        }
        return -1;
    }
    
    void set(int key, int value) {
        LinkedListNode* node;
        if (hashtable.find(key) != hashtable.end()) {
            node = hashtable[key];
            node->key = key, node->value = value;
            erase(node), push(node);
            return ;
        }
        if (hashtable.size() == capacity) {
            node = tail.pre;
            erase(node);
            hashtable.erase(node->key);
        } else {
            node = new LinkedListNode();
        }
        node->key = key, node->value = value;
        hashtable[key] = node;
        push(node);
    }
    
private:
    
    void push(LinkedListNode* node) {
        node->pre = &head;
        node->next = head.next;
        head.next->pre = node;
        head.next = node;
    }
    
    void erase(LinkedListNode* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
    
    LinkedListNode head, tail;
    unordered_map<int, LinkedListNode*> hashtable;
    int capacity;
};
