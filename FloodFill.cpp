class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor){
            return image;
        }
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        int n = image.size();
        int m = image[0].size();
        int oldColor = image[sr][sc];
        image[sr][sc] = newColor;
        queue<pair<int, int >> q;
        q.push(make_pair(sr, sc));
        while(!q.empty()){
            int x = q.size();
            for(int i = 0;i<x;i++){
                pair<int, int> temp = q.front();
                int x = temp.first;
                int y = temp.second;
                for(int idx = 0;idx<4;idx++){
                    if(x+dx[idx]>=0 && x+dx[idx]<n && y+dy[idx]>=0 && y + dy[idx]<m && image[x+dx[idx]][y+dy[idx]] == oldColor){
                        q.push(make_pair(x+dx[idx], y+dy[idx]));
                        image[x+dx[idx]][y+dy[idx]] = newColor;
                    }
                }
                q.pop();
            }
        }
        return image;
    }
};