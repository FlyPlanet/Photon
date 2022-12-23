#pragma once
#include <vector>
struct DOMUnit
{
    std::vector<DOMUnit> children;
    void free()
    {
    }
};
class DOMTree
{
  private:
    DOMUnit root;
  public:
    DOMTree();
    ~DOMTree()
    {
        auto freeChild = [&](DOMUnit du) {
            for (auto &i : du.children)
            {
                i.free();
            }
            du.free();
        };
        freeChild(root);
    }
};
extern DOMTree domTree;