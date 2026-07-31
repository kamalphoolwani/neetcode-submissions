class TimeMap {
    // Storing {timestamp, value} allows standard STL algorithms to search smoothly
    unordered_map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) return "";
        
        // Grab a constant reference to avoid copying the vector
        const auto& vals = mp[key];
        
        // upper_bound finds the first element STRICTLY GREATER than the target timestamp
        // We pass a dummy pair with our target timestamp for comparison
        auto it = upper_bound(vals.begin(), vals.end(), make_pair(timestamp, string("")), 
                              [](const pair<int, string>& a, const pair<int, string>& b) {
                                  return a.first < b.first;
                              });
        
        // If it points to the beginning, it means all stored timestamps are greater than the target
        if (it == vals.begin()) return "";
        
        // Otherwise, step back one position to get the largest timestamp_prev <= timestamp
        return prev(it)->second;
    }
};