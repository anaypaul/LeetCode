//Accepted earlier
//Times out with new test cases
class Solution {
public:
    int distance(string s1, string s2){
        int dist = 0;
        for(int i = 0; i<s1.length(); i++){
            if(s1[i] != s2[i]){
                dist++;
            }
        }
        return dist;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = wordList.size();
        vector<bool> visited(n, false);
        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 1));
        while(!q.empty()){
            int x = q.size();
            for(int i = 0; i<x; i++){
                auto curr = q.front();
                if(curr.first.compare(endWord) == 0){
                    return curr.second;
                }
                q.pop();
                for(int i = 0; i<wordList.size(); i++){
                    if(!visited[i] && distance(curr.first, wordList[i]) == 1){
                        q.push(make_pair(wordList[i], curr.second + 1));
                        visited[i] = true;
                    }
                }
            }
        }
        return 0;
    }
};
//Approach 2 : 
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> curr;
        queue<string> next;
        curr.push(beginWord);
        int len = 2;
        while(!curr.empty()){
            string node = curr.front();
            curr.pop();
            for(auto& x : wordList){
                if(x == "" || check(x, node) == false){
                    continue;
                }
                if(x == endWord){
                    return len;
                }
                next.push(x);
                x = "";
            }
            if(curr.empty()){
                len++;
                swap(curr, next);
            }
        }
        return 0;
    }
    bool check(string& a, string& b){
        int diff = 0;
        for(int i = 0; i<a.size(); i++){
            if(a[i] != b[i]){
                diff++;
            }
            if(diff > 1){
                return false;
            }
        }
        return diff == 1;
    }
};