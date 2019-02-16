#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// double helper(double ans, double base, int exp){
//     if(exp==0){
//         return ans;
//     }else{
//         ans = ans*base;
//         return helper(ans, base, exp-1);
//     }
// }
// double myPow(double base, int exp){
//     if(base == 1.0 || exp == 0){
//         return 1.0;
//     }
//     if(exp<0.0){
//         base = 1/base;
//         exp = exp*-1;
//         return helper(1.0,base, exp);
//     }else{
//         return helper(1.0,base, exp);
//     }
// }
double helper(double base , int exp){
    if(exp%2 == 0){
        if(exp ==1){
            return base;
        }else{
            return helper(base*base, (int)exp/2);
        }
    }else{
        if(exp==1){
            return base;
        }else{
            double x = helper(base*base, (int)exp/2);
            x = x * base;
            return x;
        }
    }
}
double power(double base, int exp){
    if(exp==0){
        cout<<"zero power"<<endl;
        return 1;
    }else if(exp<0){
        cout<<"negative power"<<endl;
        base = 1.0/base;
        exp = exp*-1;
    }else{
        cout<<"positive power"<<endl;
        
    }
}
int main(){
    double base;
    int exp;
    cin>>base>>exp;
    cout<<power(base,exp)<<endl;
    return 0;
}