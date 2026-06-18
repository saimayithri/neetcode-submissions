class MedianFinder {
public:
    priority_queue <int> small;
    priority_queue <int,vector<int>,greater<int>> large;
    MedianFinder() {
        
    }
    
    void addNum(int num) {

        small.push(num);
        if(!small.empty()&&!large.empty())
        {
            if(small.top()>large.top())
            {
                large.push(small.top()); small.pop();
            }
        }

        while(small.size()>large.size()+1)
        {
            large.push(small.top()); small.pop();
        }
        while(large.size()>small.size()+1)
        {
            small.push(large.top()); large.pop();
        }
        
    }
    
    double findMedian() {

        if(small.size()==large.size())
        {
            return (small.top()+large.top())/2.0;
        }

        if(small.size()>large.size())
        {
            return  small.top();
        }
        return large.top();
        
    }
};
