#include <iostream>
#include <map>
using namespace std;

template <typename Key, typename Value>
class Pair {
    private:
        map<Key, Value> data;
    public:
        void add(const Key& key, const Value& value){
            data[key] = value;
        }

        Value get(const Key& key) const {
            return data.at(key);
        }
        
};

int main(){
    Pair<string, int> p;
    p.add("one", 1);

}

