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

//Implementation 2 :
//Bi-directional BFS 
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        //search if the endWord is present in the word list 
        //if not, no point in searching, just return 0
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        
        //now we would need 2 queue for maintaining the current level and the next level
        //each for 1 direction. 
        
        // curr0 = current level at beginning of the graph.(BFS originating at beginWord)
        // next0 = next level of curr0

        //curr1 = current level at end of the graph.(BFS originating at endWord)
        //next1 = next level of curr1

        //we will also maintain pointers for executing bfs alternating between top 
        //bottom ie the two directions
        // *curr will hold the address of the queue currently being used for bfs
        // *next will hold the address of the next queue currently being used for bfs
        // and this will keep alternating at each level wise iteration of the bfs
        unordered_set<string> visited0, visited1, *v0(&visited0), *v1(&visited1);
        queue<string> curr0, next0, curr1, next1, *curr, *next;
        
        curr0.push(beginWord);
        curr1.push(endWord);
        
        visited0.insert(beginWord);
        visited1.insert(endWord);
        
        int len = 2;
        bool flag = true;
        
        while(!curr0.empty() && !curr1.empty()){
            curr = flag ? &curr0 : &curr1;
            next = flag ? &next0 : &next1;
            string node = curr->front();
            curr->pop();
            for(auto& x : wordList){
                if(v0->count(x) || !isNeighbor(x, node)){
                    continue;
                }
                if(v1->count(x)){
                    return len;
                }
                v0->insert(x);
                next->push(x);
            }
            if(curr->empty()){
                //increment lenth of the path and swtich the direction of BFS
                // by swithing between the queue for curr level , next level and 
                // visited set by changing the flag value 
                len++;
                swap(*curr, *next);
                swap(v0, v1);
                flag = !flag;
            }
        }
        return 0;
    }
    
    bool isNeighbor(string& a, string& b){
        int diff = 0;
        for(int i = 0; i < a.size(); i++) if(a[i] != b[i] && ++diff > 1) return false;
        return diff == 1;
    }
};
