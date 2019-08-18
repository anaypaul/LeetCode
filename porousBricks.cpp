#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define mk make_pair
using namespace std;
int main(){
    int n;
    int m;
    cout<<"Enter size of the brick wall: ";
    cin>>n>>m;
    vector<vector<bool> >isPorous(n ,vector<bool>(m, true));
    cout<<"Set prorous bricks"<<endl;
    int bricks;
    cout<<"Enter number of non-porous bricks :";
    cin>>bricks;
    int x,y;
    for(int i = 0;i<bricks;i++){
        cin>>x;
        cin>>y;
        isPorous[x][y] = false;
    }

    vector<pair<int, int> > startingPoints;
    for(int j = 0;j<m;j++){
        if(isPorous[0][j]){
            startingPoints.push_back(make_pair(0,j));
        }
    }
    
    int result = INT_MAX;
    for(int idx = 0 ;idx<startingPoints.size(); idx++){
        pair<int, int> start = startingPoints[idx];
        int level = 1;
        vector<vector<bool> >isVisited(n ,vector<bool>(m, false));

        queue<pair<pair<int,int>, int> > q;
        isVisited[start.first][start.second] = true;
        q.push(mk(start, level));
        while(!q.empty()){
            int x = q.size();
            for(int c = 0;c< x;c++){
                pair<int, int > curr = q.front().first;
                if(curr.first+1 == n){
                    result = min(result, q.front().second);
                }
                int curr_level = q.front().second;
                //left
                cout<<"left"<<endl;
                if(curr.first < n && curr.second-1 >=0 && isVisited[curr.first][curr.second-1]==false && isPorous[curr.first][curr.second-1]){
                    isVisited[curr.first][curr.second-1] = true;
                    q.push(mk(mk(curr.first,curr.second-1), curr_level+1));
                }
                //right
                cout<<"right"<<endl;
                if(curr.first < n && curr.second+1 <m && isVisited[curr.first][curr.second+1] == false && isPorous[curr.first][curr.second+1]){
                    isVisited[curr.first][curr.second+1] = true;
                    q.push(mk(mk(curr.first, curr.second+1), curr_level+1));
                }
                //bottom
                if(curr.first+1 <n && curr.second < m && isVisited[curr.first+1][curr.second] == false && isPorous[curr.first+1][curr.second]){
                    isVisited[curr.first+1][curr.second] = true;
                    q.push(mk(mk(curr.first+1, curr.second), curr_level+1));
                }
                q.pop();
            }
        }
    }
    if(result != INT_MAX){
        cout<<"Minimum time for rain water to reach floor is : "<<result<<endl;
    }else{
        cout<<"Rain water doesn't reach the floor"<<endl;
    }
    return 0;
}