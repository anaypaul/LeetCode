class Solution {
public:
    static bool mycmp(pair<string, int> p1 , pair<string, int> p2){
        if(p1.second > p2.second){
            return true;
        }else if(p1.second == p2.second){
            int i = 0;
            int j = 0;
            while(i<p1.first.length() && j<p2.first.length()){
                if(p1.first[i] < p2.first[j]){
                    return true;
                }else if(p1.first[i] > p2.first[j]){
                    return false;
                }else if(p1.first[i] == p2.first[j]){
                    i++;
                    j++;
                }
            }
            if(p1.first.length() <= p2.first.length()){
                return true;
            }else if(p1.first.length() > p2.first.length()){
                return false;
            }
        }
        return false;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> um;
        for(auto x : words){
            um[x]+=1;
        }
        vector<pair<string, int>> v;
        for(auto x : um){
            v.push_back(make_pair(x.first, x.second));
        }
        vector<string> res;
        sort(v.begin(), v.end(), mycmp);
        for(int i = 0;i<v.size();i++){
            cout<<v[i].first<<" "<<v[i].second<<endl;
            if(i<k){
            res.push_back(v[i].first);
            }
        }
        return res;
    }
};