class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, int> m1;
        map<string, int> m2;
        for(int i = 0;i<list1.size();i++){
            if(m1.find(list1[i]) == m1.end()){
                m1.insert(make_pair(list1[i], i));
            }
        }
        int x = INT_MAX;
        for(int i = 0;i<list2.size();i++){
            if(m1.find(list2[i])!=m1.end()){
                m2.insert(make_pair(list2[i], i));
                x = min(x, m1[list2[i]] + m2[list2[i]]);
            }
        }
        vector<string> res;
        for(int i = 0;i<list2.size();i++){
            if(m2.find(list2[i]) != m2.end()){
                if(m1[list2[i]] + m2[list2[i]] == x){
                    res.push_back(list2[i]);
                }
            }
        }
        return res;
    }
};

//approach 2
class Solution {
public:
    static bool mycmp(pair<int,int> p1, pair<int,int> p2){
        return p1.first + p1.second < p2.first+p2.second;
    }
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<string> res;
        unordered_map<string, int> m;
        for(int i = 0; i<list1.size(); i++){
            m[list1[i]] = i;
        }
        vector<pair<int, int>> v;
        int sum = INT_MAX;
        for(int j = 0; j<list2.size(); j++){
            if(m.find(list2[j]) != m.end()){
                v.push_back(make_pair(m[list2[j]],j));
                sum = min(sum, m[list2[j]] +j);
            }
        }
        for(int j = 0; j<list2.size(); j++){
            if(m.find(list2[j]) != m.end() && sum == m[list2[j]] + j){
                res.push_back(list2[j]);
            }
        }
        return res;
    }
};