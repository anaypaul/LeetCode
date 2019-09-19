class Solution {
public:
    int getmax(int a, int b, int c){
        return max(a, max(b,c));
    }
    int maxDistToClosest(vector<int>& seats) {
        vector<int> v;
        int dist = -1;
        for(int i = 0;i<seats.size(); i++){
            if(seats[i] == 1){
                v.push_back(i);
            }
            if(v.size()>1){
                dist = max(dist, v[v.size()-1] - v[v.size()-2]);
            }
        }
        int left = v[0];
        int right = seats.size()- v[v.size()-1] - 1;
        if(v.size()== 1){
            int left = v[0];
            int right = (seats.size() - left-1);
            return max(left, right);
        }
        return getmax(dist/2, left, right) ;
    }
};

//Approach 2
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int K = 0;
        int ans = 0;
        for(int i = 0;i<n; i++){
            if(seats[i] == 1){
                K = 0;
            }else{
                K++;
                ans = max(ans , (K+1)/2);
            }
        }
        for(int i = 0 ;i<n ;i++){
            if(seats[i] == 1){
                ans = max(ans, i);
                break;
            }
        }
        for(int i = n-1;i>=0;--i){
            if(seats[i] == 1){
                ans = max(ans, n-i -1);
                break;
            }
        }
        return ans;
    }
};