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

//Implementation 2 : Using DFS
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
class Solution {
public:
    void solve(vector<Employee*> employees, int currId, unordered_map<int,int>& m, unordered_set<int>& vis, int & res){
        if(vis.find(currId) != vis.end()){
            return ;
        }
        vis.insert(currId);
        res += employees[m[currId]]->importance;
        for(auto each : employees[m[currId]]->subordinates){
            solve(employees, each, m, vis, res);
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        int res = 0;
        unordered_map<int, int> m;
        for(int i = 0; i<employees.size(); i++){
            m[employees[i]->id] = i;
        }
        unordered_set<int> vis;
        solve(employees, id, m, vis, res);
        return res;
    }
};

// Implementation 3 : Using BFS
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
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int res = 0;
        unordered_map<int, int> m;
        for(int i = 0; i<employees.size(); i++){
            m[employees[i]->id] = i;
        }
        
        queue<int> q;
        q.push(id);
        unordered_set<int> vis;
        vis.insert(id);
        while(!q.empty()){
            auto id = q.front();
            q.pop();
            res += employees[m[id]]->importance;
            for(auto each : employees[m[id]]->subordinates){
                if(vis.find(each) == vis.end()){
                    q.push(each);
                    vis.insert(each);
                }
            }
        }
        return res;
    }
};