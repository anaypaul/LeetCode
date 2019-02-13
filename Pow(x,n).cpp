#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
double helper(double ans, double base, int exp){
    if(exp==0){
        return ans;
    }else{
        ans = ans*base;
        return helper(ans, base, exp-1);
    }
}
double myPow(double base, int exp){
    if(base == 1.0 || exp == 0){
        return 1.0;
    }
    if(exp<0.0){
        base = 1/base;
        exp = exp*-1;
        return helper(1.0,base, exp);
    }else{
        return helper(1.0,base, exp);
    }
}
int main(){
    double base;
    int exp;
    cin>>base>>exp;
    cout<<myPow(base,exp)<<endl;
    return 0;
}