// 706. Design HashMap

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class MyHashMap {
private:
    unordered_map<int, int> myMap;
public:
    MyHashMap() {
        //unordered_map<int, int> myMap;
    }
    
    void put(int key, int value) {
        myMap[key] = value;
    }
    
    int get(int key) {
        auto it = myMap.find(key);
        if (it != myMap.end())
            return it->second;
        else 
            return -1;
    }
    
    void remove(int key) {
        myMap.erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main() {
    MyHashMap* myHashMap = new MyHashMap();

    // Corresponding to: ["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
    //                  [[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]

    vector<string> operations = {"MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"};
    vector<vector<int>> arguments = {{}, {1, 1}, {2, 2}, {1}, {3}, {2, 1}, {2}, {2}, {2}};

    for (size_t i = 0; i < operations.size(); ++i) {
        string op = operations[i];
        if (op == "MyHashMap") {
            cout << "null" << endl;
        } else if (op == "put") {
            myHashMap->put(arguments[i][0], arguments[i][1]);
            cout << "null" << endl;
        } else if (op == "get") {
            int result = myHashMap->get(arguments[i][0]);
            cout << result << endl;
        } else if (op == "remove") {
            myHashMap->remove(arguments[i][0]);
            cout << "null" << endl;
        }
    }

    delete myHashMap;
    return 0;
}
