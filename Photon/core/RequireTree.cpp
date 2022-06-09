#include "RequireTree.h"
namespace Photon::Core{
    void RequireTree::run(){
        for (auto i = 0;i<runQueue.size();i++){
            for (auto j = 0;j<runQueue[i].size();j++){
                runQueue[i][j]->run();
            }
        }
    }
    void func(int flag,RequireNode node*,RequireNode* root){
        node->distance[root] = flag;
        for (auto i = 0;i<node->children.size();i++){
            func(flag+1,node->children[i],root);
        }
    }
    void RequireTree::solve(){
        for(auto i*:this->listeners){
            for(auto *j:i->children){
                func(1, j, i);
            }
        }
    }
    
    void RequireTree::~RequireTree()
    {
        //遍历nodes，释放内存
        for (auto i = 0;i<nodes.size();i++){
            delete nodes[i];
        }
    }
    void RequireTree::addListener(Listener listener){
        listeners.push_back(&listener);

    }
    void RequireTree::addRequire(RequireElement father,RequireElement son){

    }
}