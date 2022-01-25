#pragma once
#include "../pch.h"
namespace Photon {
namespace Control {
    using namespace std;
    class ControlBase {
      public:
        ControlBase();
        ~ControlBase();
        static void AddChild(ControlBase* in);
        static void DelChild(ControlBase* in);

      private:
        vector<ControlBase*> children;
    };
}  // namespace Control
}  // namespace Photon