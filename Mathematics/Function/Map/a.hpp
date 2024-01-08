// c:/Users/user/Documents/Programming/Mathematics/Function/Map/a.hpp

#pragma once

class is_ordered
{

private:
  is_ordered() = delete;
  template <typename T> static constexpr auto Check( const T& t ) -> decltype( t < t , true_type() );
  static constexpr false_type Check( ... );

public:
  template <typename T> static constexpr const bool value = is_same_v< decltype( Check( declval<T>() ) ) , true_type >;

};

#include "a_Alias.hpp"
// Map<T,U>��
// - unordered_map<T,U>()��well-formed�Ȃ��unordered_map<T,U>
// - �����łȂ�operator<(declval<T>(),declval<T>())��well-formed�Ȃ��map<T,U>
// - �����łȂ��Ȃ��void
