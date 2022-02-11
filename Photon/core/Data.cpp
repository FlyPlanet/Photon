//
// Created by skywards on 2/10/22.
//

#include "Data.h"
void Photon::Data::Data::SetData( std::any &v ) { this->data = v; }
bool Photon::Data::Data::isSame( std::any *c ) {
    if ( c->type() != this->data.type() ) {
        return false;
    }
    switch ( this->type ) {
    case PType::Bool:
        return std::any_cast<bool>( *c ) == std::any_cast<bool>( this->data );
        break;
    case PType::Num:
        return std::any_cast<int>( *c ) == std::any_cast<int>( this->data );
        break;
    case PType::String:
        return std::any_cast<std::string>( *c ) ==
               std::any_cast<std::string>( this->data );
        break;
    }
    return false;
}
