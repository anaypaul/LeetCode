class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> m; // map for counting card of each type. 
        for_each(deck.begin(), deck.end(), [&m](int i) { ++m[i]; }); //counting cards of each type
        vector<int> cnt(m.size(), 0); // for storing all values of each card
        transform(m.begin(), m.end(), cnt.begin(), [](auto& p) { return p.second; }); //assigning count values of different cards in cnt vector.
        int gcd = 0; 
        for_each(cnt.begin(), cnt.end(), [&gcd](int i) { gcd = __gcd(i, gcd); }); //calculating gcd of all numebers
        return gcd != 1;
    }
};