class Solution {
public:
    static bool mycmp(vector<int>& v1, vector<int>& v2){
        if(v1[1] < v2[1]){
            return true;
        }else if(v1[1] > v2[1]){
            return false;
        }else if(v1[1] == v2[1]){
            if(v1[0] < v2[0]){
                return true;
            }
            return false;
        }
        return false;
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        priority_queue<int> q;
        sort(courses.begin(), courses.end(), mycmp);
        int currTime = 0;
        for(int i = 0; i<courses.size(); i++){
            int cost = courses[i][0];
            q.push(cost);
            currTime += cost;
            if(currTime > courses[i][1]){
                currTime -= q.top();
                q.pop();
            }
        }
        return q.size();
    }
};