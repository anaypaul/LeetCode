class Solution {
public:
    bool check(int num, vector<int> after){
        bool hasDiff = false;
        int res = 0;
        int x = num;
        vector<int> number;
        while(num > 0){
            int x = num%10;
            if(x == 2 || x == 5 || x == 6 || x == 9){
                hasDiff = true;
            }
            if(after[x] == -1){
                return false;
            }
            number.push_back(after[x]);
            num = num /10;
        }
        if(!hasDiff){
            return false;
        }
        reverse(number.begin(), number.end());
        for(int i = 0; i<number.size(); i++){
            res = res *10 + number[i];
        }
        if(res != x){
            return true;
        }
        return false;
    }
    int rotatedDigits(int N) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int> after(10, -1);
        after[0] = 0;
        after[1] = 1;
        after[8] = 8;
        after[2] = 5;
        after[5] = 2;
        after[6] = 9;
        after[9] = 6;
        int count = 0;
        for(int i = 1; i<=N; i++){
            if(check(i, after)){
                count++;
            }
        }
        return count;
    }
};