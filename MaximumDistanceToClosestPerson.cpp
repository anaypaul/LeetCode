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