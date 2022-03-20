#include <iostream>
#include "../Photon/Photon.h"
using namespace std;
using namespace Photon;
void add(){
  cout<<"Fuck"<<endl;
}
int main() {
  Event::EventCenter ec;
  Event::EventClient e;
  ec.addOrigin(Event::MsgOrigin::MouseX);
  ec.addProvider(Event::MsgOrigin::MouseX, [&](function<void(std::any)> f) {
    cout << "fucked" << endl;
    f(100);
  });
  e.addRequire(Event::MsgType::Changed, Event::MsgOrigin::MouseX);
  e.regisiter(&ec);
  ec.runProviders();
  auto a = e.fetch(Event::MsgOrigin::MouseX, Event::MsgType::Changed);

}