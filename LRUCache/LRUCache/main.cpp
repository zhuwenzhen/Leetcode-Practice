//
//  main.cpp
//  LRUCache
//
//  Created by Wenzhen Zhu on 6/6/17.
//  Copyright © 2017 Wenzhen Zhu. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity){
        _capacity = capacity;
    }
    
    int get(int key) {
        auto item = _cache.find(key);
        
        // if the key doesn't exsit, return -1;
        if(item == _cache.end()){
            return -1;
        }
        // if the key exist, return the value, update the LRU
        use(item);
        return item -> second.first;
    }
    
    void put(int key, int value) {
        auto item = _cache.find(key);
        // if the key exists, just set the value and update
        if(item != _cache.end()) {
            use(item);
            _cache[key] = {value, _lru.begin()};
            return;
        }
        // if the key doesn't exsit, check the capacity
        if(_cache.size() == _capacity){
            //kick out the LRU item
            _cache.erase(_lru.back());
            _lru.pop_back();
        }
        _lru.push_front(key);
        // insert new key value pair
        _cache.insert({key, {value, _lru.begin()} });
    }
    
    void use(unordered_map<int, pair<int, list<int>::iterator>> ::iterator& it){
        _lru.erase(it->second.second);
        _lru.push_front(it->first);
        it->second.second = _lru.begin();
    }
    
private:
    int _capacity;
    // <key, <value, key iterator>>
    unordered_map<int, pair<int, list<int>::iterator>> _cache;
    // list of keys
    list<int> _lru;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    LRUCache cache = *new LRUCache(2);
    cache.put(1, 10);
    cache.put(2, 20);
    
    cout << cache.get(1) << endl;
    return 0;
}
