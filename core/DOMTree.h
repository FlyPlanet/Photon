#pragma once
#include "../pch.h"
class Object;
class Observer;

struct DOMUnit
{
    DOMUnit *parent = nullptr;
    Object * object;
    std::vector<DOMUnit> children;
    
    DOMUnit(DOMUnit* d,Object* o):parent(d),object(o){}
    void free()
    {
    }
};

class DOMTree
{
  private:
    DOMUnit root;
    
    bool shouldClose=false;
  public:
    
    DOMTree();
    DOMUnit *NewObject(Object *o,DOMUnit *parent=nullptr);
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
    void Run();

};
extern DOMTree domTree;