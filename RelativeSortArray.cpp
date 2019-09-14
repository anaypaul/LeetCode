map<int, int> m;
class Solution {
public:
    static bool mycomp(int a, int b ){
        bool ans;
        if(m.find(a) != m.end() && m.find(b) != m.end()){
            ans =  m[a] < m[b];
        }else if(m.find(a)!=m.end() && m.find(b)==m.end()){
            ans = true;
        }else if(m.find(a)==m.end() && m.find(b) != m.end()){
            ans = false;
        }else if(m.find(a)==m.end() && m.find(b)==m.end()){
            ans = a<b;
        }
        return ans;
    }
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        for(int i = 0;i<arr2.size();i++){
            m.insert(make_pair(arr2[i], i));
        }
        sort(arr1.begin(), arr1.end(), mycomp);
        m.clear(); //need to clear since global variable. 
        return arr1;
    }
};