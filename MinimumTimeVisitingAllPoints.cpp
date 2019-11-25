class Solution {
public:
    
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        if(points.size()== 0 || points.size()==1 ){
            return res;
        }
        int curri = points[0][0];
        int currj = points[0][1];
        for(int i = 1; i< points.size(); i++){
            int nexti = points[i][0];
            int nextj = points[i][1];
            while(curri!= nexti || currj != nextj){
                while(curri < nexti && currj < nextj){
                    curri++;
                    currj++;
                    res++;
                }
                while(curri < nexti && currj == nextj){
                    curri++;
                    res++;
                }
                while(curri == nexti && currj < nextj){
                    currj++;
                    res++;
                }
                while(curri > nexti && currj > nextj){
                    curri--;
                    currj--;
                    res++;
                }
                while(curri == nexti && currj > nextj){
                    currj--;
                    res++;
                }
                while(curri > nexti && currj == nextj){
                    curri--;
                    res++;
                }
                while(curri < nexti && currj > nextj){
                    curri++;
                    currj--;
                    res++;
                }
                while(curri > nexti && currj < nextj){
                    currj++;
                    curri--;
                    res++;
                }
            }
        }
        return res;
    }
};