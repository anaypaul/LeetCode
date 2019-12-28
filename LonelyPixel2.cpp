class Solution {
public:
    string vec2string(vector<int> arr){
        string res = "";
        for(int i = 0; i<arr.size(); i++){
            res += to_string(arr[i]) + "#";
        }
        return res;
    }
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = picture.size();
        int m = picture[0].size();
        vector<vector<int>> blackRows(n, vector<int>());
        vector<vector<int>> blackCols(m, vector<int>());
        for(int i = 0; i<picture.size(); i++){
            for(int j = 0; j<picture[0].size(); j++){
                if(picture[i][j] == 'B'){
                    blackRows[i].push_back(j);
                    blackCols[j].push_back(i);
                }
            }
        }
        unordered_map<int , string > rowMap;
        for(int i = 0; i<n; i++){
            rowMap[i] = vec2string(blackRows[i]);
        }        
        int res = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(picture[i][j] == 'B' &&blackRows[i].size() == blackCols[j].size() && blackRows[i].size() == N){
                    //check rule 2
                    int c = 1;
                    for(int k = 0; k<n; k++){
                        if(i!=k &&rowMap[i].compare(rowMap[k]) == 0){
                            c++;
                        }
                    }
                    cout<<c<<endl;
                    if(c == N){
                        res++;
                    }
                }
            }
        }
        return res;
    }
};