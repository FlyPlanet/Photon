#include "DOMTree.h"
#include "Object.h"
#include <cstddef>
DOMUnit* DOMTree::NewObject(Object *o,DOMUnit *parent)
{
    if (parent == nullptr)
    {
        parent=&root;
    }
    parent->children.push_back(DOMUnit(parent, o));
    return &(parent->children.back());
}
void DOMTree::Run()
{
    while (!shouldClose)
    {
        //消息循环是运行每个Object的ObserveFunctions的过程
    }
}