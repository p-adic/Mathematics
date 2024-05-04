// c:/Users/user/Documents/Programming/Utility/Set/a.hpp

#pragma once
#include "a_Macro.hpp"

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
// Set<T>��
// - unordered_set<T>()��well-formed�Ȃ��unordered_set<T>
// - �����łȂ�operator<(declval<T>(),declval<T>())��well-formed�Ȃ��set<T>
// - �����łȂ��Ȃ��void

// Map<T,U>��
// - unordered_map<T,U>()��well-formed�Ȃ��unordered_map<T,U>
// - �����łȂ�operator<(declval<T>(),declval<T>())��well-formed�Ȃ��map<T,U>
// - �����łȂ��Ȃ��void
