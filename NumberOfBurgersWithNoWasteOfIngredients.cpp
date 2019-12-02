class Solution {
public:
    bool check(int t, int c, int x, int y){
        return t == (y * 4 + x * 2) && c == (x + y) && x >= 0 && y >=0;
    }
    vector<int> numOfBurgers(int t, int c) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<int> res;
        // y is jumbo burgers and x is small burger
        int x = (4 * c - t) / 2;
        int y = c - x;
        if(!check(t,c, x, y)){
            return res;
        }
        return {y,x};
    }
};