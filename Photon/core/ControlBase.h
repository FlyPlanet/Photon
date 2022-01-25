#pragma once
#include "../pch.h"
namespace Photon {
namespace Control {
    using namespace std;
    class ControlBase {
      public:
        ControlBase();
        ~ControlBase();
        void AddChild(ControlBase* in);
        void DelChild(ControlBase* in);

      private:
        vector<ControlBase*> children;
        void pushMsg(...);
    };
}  // namespace Control
}  // namespace Photon