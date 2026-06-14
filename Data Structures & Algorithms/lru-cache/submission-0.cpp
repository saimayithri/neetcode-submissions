class LRUCache {
public:
    LRUCache(int cap) {
        capacity = cap;

        left = new Node(0, 0);
        right = new Node(0, 0);

        left->next = right;
        right->prev = left;
        
    }
    struct Node{
        int val;
        int key;
        Node* prev;
        Node* next;
        Node(int k,int v): key(k), val(v), prev(nullptr), next(nullptr){}
    };
    int capacity;
    unordered_map<int, Node*> cache;
    Node* left; Node* right;

    void remove(Node* node) {
    
        node->prev->next=node->next; 
        node->next->prev=node->prev;
        
    }


    void insert(Node* node) {

        right->prev->next=node; 
        node->prev = right->prev;
        right->prev=node; 
        node->next=right; 
    
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end())
        {
            Node *node= cache[key];
            remove(node);
            insert(node);
            return node->val;

        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end())
        {
            Node *node= cache[key];
            remove(node);            
            
        }
            Node *newNode= new Node(key,value);
            cache[key]= newNode;
            insert(newNode);

            if(cache.size()>capacity)
            {
                Node *lru=left->next;
                remove(lru);
                cache.erase(lru->key);
            }
        
    }
};
