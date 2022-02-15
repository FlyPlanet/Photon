//
// Created by skywards on 2/10/22.
//

#include "Data.h"

bool Photon::Data::Data::isSame(std::any *c) {
  if (c->type() != this->data.type()) {
    return false;
  }
  switch (this->type) {
    case PType::Bool:
      return std::any_cast<bool>(*c) == std::any_cast<bool>(this->data);
    case PType::Num:
      return std::any_cast<int>(*c) == std::any_cast<int>(this->data);
    case PType::String:
      return std::any_cast<std::string>(*c) ==
             std::any_cast<std::string>(this->data);
  }
  return false;
}
void Photon::Data::Data::SetData(std::string v) {
  if (PType::String != this->type) throw std::runtime_error("类型不一致");
  this->data = v;
}
void Photon::Data::Data::SetData(int v) {
  if (PType::Num != this->type) throw std::runtime_error("类型不一致");
  this->data = v;
}
void Photon::Data::Data::SetData(bool v) {
  if (PType::Bool != this->type) throw std::runtime_error("类型不一致");
  this->data = v;
}
Photon::Data::Data::Data(std::any v, Photon::Data::PType t) {
  data = std::move(v);
  type = t;
}
void Photon::Data::Data::SetData(std::any v) {
  PType t;
  if (v.type().hash_code() == typeid(std::string).hash_code()) {
    t = PType::String;
    goto a;
  }
  if (v.type().hash_code() == typeid(int).hash_code()) {
    t = PType::Num;
    goto a;
  }
  if (v.type().hash_code() == typeid(bool).hash_code()) {
    t = PType::Bool;
    goto a;
  }
a:
  if (t != type) {
    throw std::runtime_error("类型有错误");
  } else
    data = v;
}
Photon::Data::Data::Data() {}
Photon::Data::Data::Data(const Photon::Data::Data &d) {
  this->data = d.data;
  this->type = d.type;
}
