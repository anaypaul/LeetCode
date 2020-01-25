class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int ax0 = rec1[0];
        int ay0 = rec1[1];
        int ax2 = rec1[2];
        int ay2 = rec1[3];
        
        int bx0 = rec2[0];
        int by0 = rec2[1];
        int bx2 = rec2[2];
        int by2 = rec2[3];
        
        return !( ay2 <= by0 || ay0 >= by2 || bx2 <= ax0 || ax2 <= bx0);
    }
};

//Implementation 2
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        //check vertically
        int x1_1 = rec1[0];
        int y1_1 = rec1[1];
        int x2_1 = rec1[2];
        int y2_1 = rec1[3];
        
        int x1_2 = rec2[0];
        int y1_2 = rec2[1];
        int x2_2 = rec2[2];
        int y2_2 = rec2[3];
        
        bool check1 = false;
        cout<<min(y1_2, y2_2)<<" "<<max(y1_2, y2_2)<<endl;
        if((min(y1_2, y2_2)< min(y1_1, y2_1) && min(y1_1, y2_1) <  max(y1_2, y2_2)) ||
           (min(y1_2, y2_2)< max(y1_1, y2_1) && max(y1_1, y2_1) <  max(y1_2, y2_2)) ||
           (min(y1_1, y2_1)< min(y1_2, y2_2) && min(y1_2, y2_2) <  max(y1_1, y2_1)) ||
           (min(y1_1, y2_1)< max(y1_2, y2_2) && max(y1_2, y2_2) <  max(y1_1, y2_1))
          ){
            cout<<"overlapps vertically"<<endl;
            check1 = true;
        }
        
        bool check2 = false;
        if((min(x1_2, x2_2) < max(x1_1, x2_1) && max(x1_1, x2_1) <  max(x1_2, x2_2)) || 
           (min(x1_2, x2_2) < min(x1_1, x2_1) && min(x1_1, x2_1) <  max(x1_2, x2_2)) ||
           (min(x1_1, x2_1) < max(x1_2, x2_2) && max(x1_2, x2_2) <  max(x1_1, x2_1)) ||
           (min(x1_1, x2_1) < min(x1_2, x2_2) && min(x1_2, x2_2) <  max(x1_1, x2_1))
          ){
            cout<<"overlaps horizontally"<<endl;
            check2 = true;
        }
        if(check1 && check2){
            return true;
        }
        return false;
    }
};