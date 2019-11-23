class Solution {
public:
    double getdist(vector<int> p1, vector<int> p2){
        return sqrt(pow(p1[0]-p2[0], 2) +  pow(p1[1]-p2[1], 2));
    }
    bool check(double a, double b, double c){
        return a + b > c && b + c > a && c + a > b;
    }
    double area(double a, double b, double c){
        double s = (a + b + c) * 0.5;
        double x = s * (s - a) * (s - b) * (s - c);
        return sqrt(x);
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        double res=0;
        for(int i=0;i<points.size()-2;i++){
            for(int j=i+1;j<points.size()-1;j++){
                for(int k=j+1;k<points.size();k++){
                    double a = getdist(points[i], points[j]);
                    double b = getdist(points[i], points[k]);
                    double c = getdist(points[j], points[k]);
                    if(check(a,b,c)){
                        res = max(res, area(a, b, c));
                    }
                }
            }
        }
        return res;
    }
};