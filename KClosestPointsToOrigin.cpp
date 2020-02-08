class Solution {
public:
    static bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){ 
        return (a.second < b.second);      
    } 
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> result;
        vector<pair<int, int>> arr;
        for(int i = 0;i<points.size();i++){
            int val = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            pair<int, int> p = make_pair(i,val);
            arr.push_back(p);
        }
        sort(arr.begin(), arr.end(), sortbysec);
        
        for(int i = 0;i<K;i++){
            result.push_back(points[arr[i].first]);
        }
        return result;
    }
};


//Approach 2 : O(n) using quick select strategy
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if(points.size() < K){
            return vector<vector<int>>();
        }
        int mid;
        int low = 0;
        int high = points.size()-1;
        while((mid = partition(points, low, high)) != K-1){
            if(mid < K-1){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return vector<vector<int>>(points.begin(), points.begin()+K);
    }
private:
    int partition(vector<vector<int>>& points, int low, int high){
        int pivot = low;
        int i = high+1;
        int j = high;
        while(j > low){
            if(dist(points[j]) > dist(points[pivot])){
                i--;
                swap(points[j], points[i]);
            }
            j--;
        }
        swap(points[low], points[i-1]);
        return i-1;
    }
    
    int dist(vector<int> p){
        return (p[0] * p[0]) + (p[1] * p[1]);
    }
};