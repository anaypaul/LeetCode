class Solution {
public:
    int search(int len, int n, string s){
        unordered_set<string> seen;
        for(int i=0; i+len<=n; i++){
            cout<<s.substr(i, len)<<endl;
            if(seen.find(s.substr(i, len)) != seen.end()){
                return i;
            }
            seen.insert(s.substr(i, len));
        }
        return -1;
    }
    int longestRepeatingSubstring(string s) {
        int n = s.size();
        int low = 1;
        int high = n;
        int mid;
        while(low!=high){
            mid = low + (high - low)/2;
            if(search(mid, n, s) != -1){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        return low-1;
    }
};