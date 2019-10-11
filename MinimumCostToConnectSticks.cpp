class Solution {
public:
    int connectSticks(vector<int>& s) {
        priority_queue <int, vector<int>, greater<int> > pq;
        for(auto x: s){
            pq.push(x);
        }
        int res = 0;
        while(!pq.empty() && pq.size()>1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            res += x + y;
            pq.push(x + y);
        }
        return res;
    }
};