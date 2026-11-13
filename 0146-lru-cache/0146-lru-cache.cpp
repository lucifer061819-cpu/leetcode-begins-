class LRUCache {
    int capacity;
    list<pair<int, int>> dq;
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        auto it = mp[key];
        int value = it->second;

        dq.erase(it);
        dq.push_front({key, value});
        mp[key] = dq.begin();

        return value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            dq.erase(mp[key]);
        }
        else if (dq.size() == capacity) {
            int oldKey = dq.back().first;
            dq.pop_back();
            mp.erase(oldKey);
        }

        dq.push_front({key, value});
        mp[key] = dq.begin();
    }
};