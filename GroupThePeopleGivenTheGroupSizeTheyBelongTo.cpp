class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& arr) {
        vector<vector<int>> res;
        unordered_map<int, vector<int>> m;
        for(int i = 0; i<arr.size(); i++){
            m[arr[i]].push_back(i);
        }
        for(auto each : m){
            int items = each.first;
            vector<int> temp;
            for(int i = 0; i<each.second.size(); i++){
                temp.push_back(each.second[i]);
                if(temp.size() == each.first){
                    res.push_back(temp);
                    temp.clear();
                }
            }
            cout<<endl;
        }
        return res;
    }
};