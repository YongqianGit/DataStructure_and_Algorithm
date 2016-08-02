bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> stat;
        for (int item : nums) {
            if (stat.find(item) == stat.end() ) {
                stat.insert(item);
            }
            else return true;
        }
        
        return false;
    }
