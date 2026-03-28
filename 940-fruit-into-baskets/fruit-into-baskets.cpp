class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int left = 0, right = 0, maxFruits = 0;
        while (right < fruits.size()){
            if(mp.count(fruits[right]) || mp.size() < 2){
                mp[fruits[right++]]++;
            }
            else{
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0) mp.erase(fruits[left]);
                left++;
            }
            maxFruits = max(maxFruits, right-left);
        }
        return maxFruits;
    }
};