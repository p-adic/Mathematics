// c:/Users/user/Documents/Programming/Utility/Vector/a.hpp

#pragma once
#include "a_Macro.hpp"

#include <vector>

#ifdef DEBUG
  #include "StdStream/Debug/a.hpp"
#else
  #include "StdStream/a.hpp"
#endif

DECLARATION_OF_ARITHMETICS_FOR_VECTOR( vector );
template <typename T> inline operator*( const T& scalar , vector<T> v );

// �錾�����ł͌^���_�ł��Ȃ��̂Ő錾�̓R�����g�A�E�g����B
// template <typename V> inline auto Get( V& a );

template <typename T = int> inline vector<T> id( const int& size );

template <typename T> inline void Sort( vector<T>& a , const bool& reversed = false );
template <typename T> inline vector<int> IndexSort( const vector<T>& a , const bool& reversed = false );
