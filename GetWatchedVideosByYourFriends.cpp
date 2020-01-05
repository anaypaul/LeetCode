class Solution {
public:
    static bool mycmp(pair<int, string> p1, pair<int, string> p2){
        if(p1.first < p2.first){
            return true;
        }else if(p1.first == p2.first){
            if(p1.second.compare(p2.second) < 0){
                return true;
            }else{
                return false;
            }
        }
        return false;
    }
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        vector<string> res;
        int n = friends.size();
        vector<vector<int>> graph(n, vector<int>());
        vector<bool> vis(n , false);
        for(int i = 0; i<friends.size(); i++){
            for(auto x : friends[i]){
                graph[i].push_back(x);
            }
        }

        vector<int> ff;
        queue<pair<int,int>> q;
        q.push(make_pair(id, 0));
        vis[id] = true;
        bool stop = false;
        while(!q.empty()){
            int x = q.size();
            for(int i = 0; i<x; i++){
                auto curr = q.front();
                if(curr.second == level){
                    stop = true;
                    break;
                }
                for(auto next : graph[curr.first]){
                    if(!vis[next]){
                        q.push(make_pair(next, curr.second + 1));
                        vis[next] = true;
                    }
                }
                q.pop();
            }
            if(stop){
                break;
            }
        }
        
        while(!q.empty()){
            ff.push_back(q.front().first);
            q.pop();
        }
        unordered_map<string, int> m;
        for(auto x : ff){
            for(auto x : watchedVideos[x]){
                m[x]++;
            }
        }
        vector<pair<int, string>> ans;
        for(auto x: m){
            ans.push_back(make_pair(x.second, x.first));
        }
        sort(ans.begin(), ans.end(), mycmp);
        for(auto x : ans){
            res.push_back(x.second);
        }
        return res;
    }
};