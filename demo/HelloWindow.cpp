#include <iostream>
#define DEBUG
#include "../Photon/Photon.h"
using namespace std;
using namespace Photon;
int main() {
  Event::EventCenter ec;
  Event::Event e;
  ec.addOrigin(Event::MsgOrigin::MouseX);
  ec.addProvider(Event::MsgOrigin::MouseX,
                 [&](function<void(std::any)> f) { f(100); });
  e.addRequire(Event::MsgType::Remain, Event::MsgOrigin::MouseX);
  e.regisiter(&ec);
}