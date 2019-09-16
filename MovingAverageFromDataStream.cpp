class MovingAverage {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    int len = 0 ;
    int x = 0;
    int curr_sum = 0;
    MovingAverage(int size) {
        x = size;
        curr_sum = 0;
    }
    
    double next(int val) {
        if(len + 1> x){
            curr_sum -= q.front();
            q.pop();
            q.push(val);
            curr_sum+=val;
        }else{
            q.push(val);
            len++;
            curr_sum += val;
        }
        return (double)curr_sum /(double) q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */