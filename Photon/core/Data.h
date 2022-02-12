//
// Created by skywards on 2/10/22.
//

#ifndef PHOTONDEMO_DATA_H
#define PHOTONDEMO_DATA_H
#include "../Photon.h"
#include "../pch.h"
namespace Photon::Data {
enum class PType { String, Num, Bool };
class Data {
 public:
  Data();
  Data(int v);
  Data(bool v);

  void SetData(std::any &v);
  bool isSame(std::any *c);
  template <class T>
  inline T c_type() {
    //把Photon数据转换成c++数据
    T i;
    try {
      i = std::any_cast<T>(data);
    } catch (std::bad_any_cast &e) {
      throw e;
    }
    return i;
  }

 private:
  PType type;
  std::any data;
};
}  // namespace Photon::Data
#endif  // PHOTONDEMO_DATA_H
