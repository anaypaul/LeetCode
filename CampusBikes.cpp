//Approach 1
//using priority queue
class Solution {
public:
    struct Dis{
        int d; 
        int worker;
        int bike;
        bool operator<(const Dis& x) const {
            if(x.d != d){
                return d > x.d;
            }
            if(worker != x.worker){
                return worker > x.worker;
            }
            return bike > x.bike;
        }
    };
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<int> res(workers.size(), -1);
        priority_queue<Dis> q;
        for(int i= 0; i<workers.size(); i++){
            for(int j = 0; j<bikes.size(); j++){
                int d = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                q.push({d, i, j});
            }
        }
        
        vector<bool> visitedBike(bikes.size(), false);
        while(!q.empty()){
            auto [d, i, j] = q.top();
            q.pop();
            if(res[i] == -1 && visitedBike[j] == false){
                visitedBike[j] = true;
                res[i] = j;
            }
        }
        return res;
    }
};

//Approach 2
//Using bucket sort
class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& W, vector<vector<int>>& B) {
        //using bucket sort
        int workers = W.size();
        int bikes = B.size();
        vector<int> res(workers, -1);
        vector<bool> occ(1000, false);
        array<vector<unsigned int>, 2000 > m;
        
        for(int i= 0; i< workers ; i++){
            for(int j = 0; j< bikes; j++){
                int d = abs(W[i][0] - B[j][0]) + abs(W[i][1] - B[j][1]);
                m[d].push_back(i<<16 | j);
            }
        }
        
        int c = 0;
        for(int dist = 0; dist < 2000; dist++){
            for(auto x : m[dist]){
                int bike = x & 0xFFFF;
                int worker = x>>16;
                if(occ[bike] == false && res[worker] ==-1){
                    res[worker] = bike;
                    occ[bike] = true;
                    c++;
                }
                if(c == workers){
                    return res;
                }
            }
        }
        return res;
    }
};