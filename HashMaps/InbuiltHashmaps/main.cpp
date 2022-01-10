#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    unordered_map<string, int> ourMap;

    // insert
    pair<string, int> p("abc", 1);
    ourMap.insert(p);

    ourMap["def"] = 2;

    // find or access
    cout << ourMap["abc"] << endl;
    cout << ourMap.at("abc") << endl;

    // Exception thrown
    // cout << ourMap.at("ghi") << endl;
    
    // Inserts key "ghi" and store value 0
    cout << ourMap["ghi"] << endl;

    // check Presense
    if (ourMap.count("ghi") > 0) {
        cout << "ghi is present" << endl;
    }

    // erase
    ourMap.erase("ghi");
    cout << "Size: " << ourMap.size() << endl;

    if (ourMap.count("ghi") > 0) {
        cout << "ghi is present" << endl;
    }

    return 0;
}
