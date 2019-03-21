class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int x = image[sr][sc];
        if(x==newColor){
            return image;
        }
        int rows = image.size();
        int cols = image[0].size();
        queue<pair<int,int>> q;
        q.push(make_pair(sr,sc));
        image[sr][sc] = newColor;
        while(!q.empty()){
            pair<int, int> temp = q.front();
            q.pop();
            if(temp.first+1 < rows && image[temp.first+1][temp.second] == x){
                q.push(make_pair(temp.first+1, temp.second));
                image[temp.first+1][temp.second] = newColor;
            }
            if(temp.first-1 >=0 && image[temp.first-1][temp.second] == x){
                q.push(make_pair(temp.first-1, temp.second));
                image[temp.first-1][temp.second] = newColor;
            }
            if(temp.second + 1<cols && image[temp.first][temp.second+1] == x){
                q.push(make_pair(temp.first, temp.second+1));
                image[temp.first][temp.second+1] = newColor;
            }
            if(temp.second -1 >=0 && image[temp.first][temp.second-1] == x){
                q.push(make_pair(temp.first,temp.second-1));
                image[temp.first][temp.second-1] = newColor;
            }
        }
        return image;
    }
};