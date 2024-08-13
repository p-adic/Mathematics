// c:/Users/user/Documents/Programming/Utility/Set/Map/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"

// �f�o�b�O�p�iCERR�}�N�����ł̂ݎg�p�j
#ifdef DEBUG
  #include "StdStream/a.hpp"
#endif

#include "a_Alias.hpp"

// Map<T,U>��
// - unordered_map<T,U>()��well-formed�Ȃ��unordered_map<T,U>
// - �����łȂ�operator<(declval<T>(),declval<T>())��well-formed�Ȃ��map<T,U>
// - �����łȂ��Ȃ��void

DECLARATION_OF_ARITHMETICS_FOR_MAP( map );
DECLARATION_OF_ARITHMETICS_FOR_MAP( unordered_map );
