class Solution {
public:
    //time complexity : O(nlogn) since using map can also use unordered_map instead of map for constant time search 
    //which makes the algorithmic time complexity O(n)
    // map took 16 ms and unordered_map took 8ms 
    vector<int> partitionLabels(string s) {
        vector<int> res;
        map<char, int> m;
        for(auto x : s){
            m[x] += 1;
        }
        for(int i = 0;i<s.length();){
            int j = i;
            int count= 0;
            int sum = 0;
            set<char> temp;
            if(m[s[j]]>0){
                count++;
                m[s[j]]--;
                sum = m[s[j]];
                temp.insert(s[j]);
            }
            j++;
            while(j < s.length() && sum>0){
                count++;
                if(m[s[j]] > 0){//for safety
                    if(temp.find(s[j]) == temp.end()){
                        temp.insert(s[j]);
                        m[s[j]]--;
                        sum += m[s[j]];
                    }else{
                        m[s[j]]--;
                        sum--;
                    }
                }
                j++;
            }
            i = j;
            res.push_back(count);
        }
        return res;
    }
};

//Time Complexity : O(n)
//Space Complexity: O(n)
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> index(26, 0);
        for(int i =0;i<s.length(); i++){
            index[s[i]-'a'] = i;
        }
        vector<int> res;
        int start = 0;
        int x = 0;
        for(int i = 0;i<s.length(); i++){
            x = max(x, index[s[i]-'a']);
            if(i == x){
                res.push_back(i - start + 1);
                start = i+1;
            }
        }
        return res;
    }
};
