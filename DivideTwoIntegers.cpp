#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
// int divide(int dividend, int divisor) {
//     if(dividend == -2147483648 && divisor == -1){
//         //overflow case
//         return 2147483647;
//     }else if(dividend == 2147483647 && divisor == -1 ){
//         return -2147483647;
//     }
//     int sign = 1;
//     if(dividend==0){
//         cout<<"dividend = 0"<<endl;
//         return 0;
//     }
//     if(divisor<0){
//         divisor = -1*divisor;
//         sign = -1;
//     }
//     if(dividend <0){
//         if(dividend != -2147483648){
//         dividend = -1*dividend;
//         cout<<"changin sign of dividend"<<dividend<<endl;
//         sign = -1*sign;
//         }
//         else{
//             dividend = 2147483648;
//             sign = -1*sign;
//         }
//     }
    
//     cout<<dividend<<" "<<divisor<<endl;
//     if(divisor==1 ||divisor==-1){
//         cout<<"special case "<<endl;
//         cout<<sign<<" * "<<dividend<<endl;
//         return sign * dividend;
//     }
//     int q = 0;
//     int t = 0;
//     while(dividend - t>= divisor){
//         q++;
//         cout<<q<<endl;
//         if(t!=0){
//             dividend-= t;
//         }
//         t = divisor;
//     }
//     cout<<"normal case"<<endl;
//     return sign*q;
// }
int divide(long long int dividend,long long int divisor){
    int sign = 1;
    if(dividend<0){sign *= -1;}
    if(divisor<0){sign *= -1;}
    dividend = abs(dividend);
    divisor = abs(divisor);
    // cout<<abs(dividend)<<" "<<abs(divisor)<<endl;
    // cout<<dividend<<" "<<divisor<<endl;

    if(divisor==1 ||divisor==-1){
        cout<<"special case "<<endl;
        cout<<sign<<" * "<<dividend<<endl;
        return sign * dividend;
    }
    long long int q = 0;
    long long int t = 0;
    while(dividend - t>= divisor){
        q++;
        // cout<<q<<endl;
        if(t!=0){
            dividend-= t;
        }
        t = divisor;
    }
    cout<<"normal case"<<endl;
    return sign*q;
}
int main(){
    int dividend,divisor;
    cin>>dividend;
    cin>>divisor;
    cout<<divide(dividend,divisor)<<endl;
    return 0;
}