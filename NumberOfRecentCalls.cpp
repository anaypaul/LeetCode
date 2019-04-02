class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {
    }
    
    int ping(int t) {
        int x = 1;
        if(t- q.front() <= 3000){
            x += q.size();
            q.push(t);
        }else{
            while(t- q.front()>3000 && !q.empty()){
                q.pop();
            }
            x += q.size();
            q.push(t);
        }
        return x;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */