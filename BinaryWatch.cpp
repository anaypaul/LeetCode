class Solution {
public:
    string getTime(bitset<10> time){
        int hour = 0;
        int minute = 0;
        int exp = 0;
        for(int i = 3; i>=0; i--){
            hour += time[i] * pow(2, exp);
            exp++;
        }
        
        exp = 0;
        for(int i = 9; i>=4; i--){
            minute += time[i] * pow(2, exp);
            exp++;
        }
        
        if(hour>=0 && hour<=11 && minute>=0 && minute<=59){
            return to_string(hour)+(minute<10 ? ":0" : ":")+to_string(minute);
        }
        return "";
    }
    void permute(int num, vector<string>& res, bitset<10>& time,int count, int curr){
        if(count == num){
            string temp = getTime(time);
            if(temp.size()>0){
                res.push_back(temp);
            }
            return ;
        }
        for(int i = curr; i<10; i++){
            time[i] = 1;
            permute(num, res, time ,count+1, i + 1);
            time[i] = 0;
        }
    }
    vector<string> readBinaryWatch(int num) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<string> res;
        if(num >10){
            return res;
        }
        // reverse
        bitset<10> time; //first 4 bits for the hour right to left
        //next 6 bits for seconds from right to left
        permute(num, res, time, 0, 0);
        return res;
    }
};