class MovingAverage {
public:
    /** Initialize your data structure here. */
    queue<double> q;
    int size;
    double sum;
    MovingAverage(int size) {
        this->size = size;
        this->sum = 0;
    }
    
    double next(int val) {
        double avg;
        if(q.size() < size){
            q.push(val);
            sum+= val;
            avg = sum/q.size();
        }else if(q.size() == size){
            double t = q.front();
            q.pop();
            q.push(val);
            sum = sum - t + val;
            avg = sum/q.size();
        }
        return avg;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */