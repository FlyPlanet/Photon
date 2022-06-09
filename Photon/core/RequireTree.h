#include "../pch.h"
#include "RequireTree.h"
#include "RequireElement.h"
namespace Photon::Core{
    using namespace Photon::Core;
    class RequireError:public std::runtime_error{
        public:
            RequireError(const std::string& msg):std::runtime_error(msg){}
    };
    enmu class RequireNodeType{
        Listener,Action
    }
    struct RequireNode{
        RequireElement element;
        //父列表
        std::vector<RequireNode*> parents;
        //子列表
        std::vector<RequireNode*> children;
        //距离从每个父节点出发，到达该节点的距离
        std::map<RequireNode *, int> distance;
        //节点类型
        RequireNodeType type;
    }
    }
    class RequireTree{
        public:
            //构造函数
            RequireTree();
            //析构函数
            virtual ~RequireTree();
            
            //添加Listener
            void addListener(Listener listener);
            //添加Require
            void addRequire(RequireElement father,RequireElement son);

            //求解运行时的依赖关系
            void solve();


            void run();
        private:

            //运行的队列，二维动态数组，类型为Action*
            //第一维度为优先级，第二维度为队列,不分先后顺序
            std::vector<std::vector<Action*>> runQueue;
            //所有的Listener
            std::vector<Listener*> listeners;

            //所有的RequireElement
            std::vector<RequireNode*> nodes;

            

    }
}