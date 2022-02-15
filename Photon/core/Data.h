//
// Created by skywards on 2/10/22.
//

#ifndef PHOTONDEMO_DATA_H
#define PHOTONDEMO_DATA_H

#include "../pch.h"
namespace Photon::Data {
enum class PType { String, Num, Bool };
class Data {
 public:
  explicit Data(int v) : Data(v, PType::Num) {}
  explicit Data(std::string v) : Data(v, PType::String) {}
  explicit Data(PType t) : Data(NULL, t) {}
  Data(const Data &d);
  Data();
  void SetData(std::string v);
  void SetData(int v);
  void SetData(bool v);
  void SetData(std::any v);
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
  Data(std::any v, PType t);

  PType type;
  std::any data;
};
}  // namespace Photon::Data
#endif  // PHOTONDEMO_DATA_H
