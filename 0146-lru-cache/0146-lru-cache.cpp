struct Node{
        pair<int,int> val;
        Node* left=nullptr;
        Node* right=nullptr;
        Node(int key,int value){
            val.first=key; val.second=value;
        }
    };
    
class LRUCache {
public:
    struct Node *head=new Node(-1,-1);
    struct Node *tail=new Node(-1,-1);
    
    map<int,Node*> mp;
    int size;
    LRUCache(int capacity) {
        size=capacity;
        head->right=tail;
        tail->left=head;
    }
    
    int get(int key) {
        Node* temp=NULL;
        if(mp.find(key)==mp.end())
            return -1;
        else{
             temp=mp[key];
            temp->left->right=temp->right;
            temp->right->left=temp->left;
            temp->left=tail->left;
            temp->left->right=temp;
            temp->right=tail;
            tail->left=temp;
            mp[key]=temp;
        }
        return mp[key]->val.second;
    }
    
    void put(int key, int value) {
        Node* temp;
        if(mp.find(key)!=mp.end()){
           temp=mp[key];
            temp->left->right=temp->right;
            temp->right->left=temp->left;
            temp->val.second=value;
            
        }else{
            if(size<=mp.size()){
                mp.erase(head->right->val.first);
                head->right=head->right->right;
                head->right->left=head;
            }
            temp=new Node(key,value);
        }
        temp->left=tail->left;
        temp->left->right=temp;
        temp->right=tail;
        tail->left=temp;
        mp[key]=temp;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */