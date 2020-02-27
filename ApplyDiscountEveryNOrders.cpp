class Cashier {
public:
    unordered_map<int, int > m;
    bool first;
    int n;
    int dis;
    int idx;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->n = n;
        this->dis = discount;
        idx = 0;
        for(int i = 0; i<products.size(); i++){
            m[products[i]] = prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double billAmt = 0.0;
        idx++;
        double total = 0.0;
        for(int i = 0; i<product.size(); i++){
            total += m[product[i]] * amount[i];
        }
        if(idx %n == 0){
            billAmt = total - ((dis * total *1.0)/100.0);
        }else{
            billAmt = (double)total;
        }
        return billAmt;
        
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */