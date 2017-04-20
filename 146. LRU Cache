class LRUCache {
struct memo{
    memo *next, *last;
    int key, value;
};
    unordered_map<int,memo*>exist;
    memo *head, *tail;
    int n, now;
public:
    LRUCache(int capacity) {
        n = capacity;
        now = 0;
        head = tail = NULL;
    }
    
    void erase(memo* t) {
        if(head == tail) {
            head = tail = NULL;
            return;
        }
        if(t == head) {
            head->next->last = NULL;
            head = head->next;
        } else if(t == tail) {
            tail->last->next = NULL;
            tail = tail->last;
        } else {
            t->last->next = t->next;
            t->next->last = t->last;
        }
    }
    
    int get(int key) {
        if(exist.find(key) != exist.end()) {
            memo *t = exist[key];
            int value = t->value;
            exist.erase(key);
            erase(t);
            insert(key, value);
            return value;
        } else return -1;
    }
    
    void insert(int key, int value) {
        memo *t = new memo();
        t->last = t->next = NULL;
        if(head == NULL) {
            head = t;
            tail = t;
        } else {
            tail->next = t;
            t->last = tail;
            tail = t;
        }
        t->key = key;
        t->value = value;
        exist[key] = t;
    }
    void put(int key, int value) {
        if(exist.find(key) != exist.end()) {
            memo *t = exist[key];
            exist.erase(key);
            erase(t);
            insert(key, value);
            return;
        }
        if(now < n) {
            insert(key, value);
            now++;
        } else {
            exist.erase(head->key);
            erase(head);
            insert(key, value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
