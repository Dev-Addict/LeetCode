#include <iterator>
#include <map>
#include <random>
using namespace std;

class RandomizedSet {
  map<int, bool> set;
  int size;
  mt19937 gen;

public:
  RandomizedSet() : size(0), gen(random_device{}()) {}

  bool insert(int val) {
    if (set.find(val) != set.end()) {
      return false;
    }
    size++;
    set[val] = true;
    return true;
  }

  bool remove(int val) {
    if (set.find(val) != set.end()) {
      size--;
      set.erase(val);
      return true;
    }
    return false;
  }

  int getRandom() {
    uniform_int_distribution<> distr(0, size - 1);

    int randomIndex = distr(gen);

    auto it = set.begin();
    std::advance(it, randomIndex);

    return it->first;
  }
};
