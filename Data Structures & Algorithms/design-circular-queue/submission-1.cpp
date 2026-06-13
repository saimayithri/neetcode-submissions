class MyCircularQueue {

private:
    vector<int>q;
    int capacity;
    int count;
    int tail;
    int head;

public:
    MyCircularQueue(int k) {
        q.resize(k);
        capacity=k;
        count=0;
        tail=-1;
        head=0;
        
    }
   
    bool enQueue(int value) {
        
        if(capacity==count)
        {
            return false;
        }
        tail=(tail+1)%capacity;
        q[tail]=value;
        count++;
        return true;
       
        
    }
    
    bool deQueue() {
        if(count==0)
        {
            return false;
        }
         q[head]=0;
        head=(head+1)%capacity;
        count--;
        return true;

        
    }
    
    int Front() {
        if(count ==0)
        {
            return -1;
        }
        return q[head];
        
    }
    
    int Rear() {

        if(count ==0)
        {
            return -1;
        }
        return q[tail];
        
    }
    
    bool isEmpty() {
        if(count==0)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
    
    bool isFull() {
        if(count==capacity)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */