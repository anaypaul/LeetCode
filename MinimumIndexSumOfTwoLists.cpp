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