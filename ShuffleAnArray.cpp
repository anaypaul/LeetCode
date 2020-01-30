class Solution {
public:
    vector<int> v;
    vector<int> aux;
    Solution(vector<int>& nums) {
        v = nums;
        aux = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return v;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if(aux.empty()){
            return aux;
        }
        int n = aux.size();
        for(int i = n; i>0; i--){
            swap(aux[i-1], aux[rand()%i]);
        }
        return aux;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */