class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int minDist = INT_MAX;
        //going start to dest
        int total = accumulate(distance.begin(), distance.end(), 0);
        int n = distance.size();
        int f = 0;
        for(int i = start ;i%n!=destination;i++){
            f += distance[i%n];
        }
        cout<<f<<endl;
        
        cout<<total-f<<endl;
        return min(f,total - f);
    }
};