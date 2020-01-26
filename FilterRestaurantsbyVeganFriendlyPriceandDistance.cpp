class Solution {
public:
    static bool mycmp(vector<int> v1, vector<int> v2){
        if(v1[1] > v2[1]){
            return true;
        }else if(v1[1] == v2[1]){
            if(v1[0] > v2[0]){
                return true;
            }else{
                return false;
            }
        }
        return false;
    }
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<int> res;
        vector<vector<int>> v;
        if(veganFriendly == 1){
            for(int i = 0; i< restaurants.size(); i++){
                if(restaurants[i][2] == 1 &&restaurants[i][3] <=maxPrice && restaurants[i][4] <= maxDistance){
                    v.push_back({restaurants[i][0], restaurants[i][1], restaurants[i][3], restaurants[i][4]});
                }
            }
        }else{
            for(int i = 0; i< restaurants.size(); i++){
                if(restaurants[i][3] <=maxPrice && restaurants[i][4] <= maxDistance){
                    v.push_back({restaurants[i][0], restaurants[i][1], restaurants[i][3], restaurants[i][4]});
                }
            }
        }
        
        sort(v.begin(), v.end(), mycmp);
        
        for(int i = 0; i<v.size(); i++){
            res.push_back(v[i][0]);    
        }
        return res;
    }
};