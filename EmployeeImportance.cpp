/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
//Depth First Search Approach 
class Solution {
public:
    int dfs(vector<Employee*> emp, int id, int& val){
        for(int i = 0;i<emp.size(); i++){
            if(emp[i]->id == id){
                val += emp[i]->importance;
                for(int j = 0; j<emp[i]->subordinates.size(); j++){
                    dfs(emp, emp[i]->subordinates[j], val);
                }
            }
        }
        return val;
    }
    int getImportance(vector<Employee*> employees, int id) {
        int res = 0;
        dfs(employees, id, res);
        return res;
    }
};