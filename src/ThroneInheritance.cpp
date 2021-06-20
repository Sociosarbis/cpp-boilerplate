#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct Person {
  string name;
  vector<Person*> children;
  bool death;
};

class ThroneInheritance {
public:
    unordered_map<string, Person*> nameToPerson;
    Person *root = nullptr;
    ThroneInheritance(string kingName) {
      root = new Person {
        kingName
      };
      nameToPerson.insert({ kingName, root });
    }
    
    void birth(string parentName, string childName) {
      Person* parent = nameToPerson[parentName];
      Person* child = new Person {
        childName
      };
      parent->children.push_back(child);
      nameToPerson.insert({ childName, child });
    }
    
    void death(string name) {
      Person* person = nameToPerson[name];
      person->death = true;
    }
    
    vector<string> getInheritanceOrder() {
      vector<string> ret;
      dfs(ret, root);
      return ret;
    }

    void dfs(vector<string> &order, Person* curPerson) {
      if (!curPerson->death) {
        order.push_back(curPerson->name);
      }
      if (!curPerson->children.empty()) {
        for (auto child:curPerson->children) {
          dfs(order, child);
        }
      }
    }
};