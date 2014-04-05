class LRUCache{
public:
    LRUCache(int capacity) {
        keys = new int[capacity];
        values = new int[capacity];
        last = new int[capacity];
        for (int i = 0; i < capacity; ++i) {
            last[i] = -1;
        }
        this->capacity = capacity;
    }
    
    ~LRUCache() {
        delete keys;
        delete values;
        delete last;
    }
    
    int get(int key) {
        for (int i = 0; i < capacity; ++i) {
            if (last[i] != -1 && keys[i] == key) {
                last[i] = ++ counter;
                return values[i];
            }
        }
        return -1;
    }
    
    void set(int key, int value) {
        for (int i = 0; i < capacity; ++i) {
            if (last[i] != -1 && keys[i] == key) {
                last[i] = ++ counter;
                values[i] = value;
                return ;
            }
        }
        int minid = 0;
        for (int i = 0; i < capacity; ++i) {
            if (last[minid] > last[i]) {
                minid = i;
            }
        }
        last[minid] = ++counter;
        keys[minid] = key;
        values[minid] = value;
    }
private:
    int *keys, *values, *last, capacity;
    static int counter;
};

int LRUCache::counter = 0;