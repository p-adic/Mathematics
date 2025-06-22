// c:/Users/user/Documents/Programming/Utility/Vector/a.hpp

#pragma once
#include "a_Macro.hpp"

#include <vector>

#if !defined( SAMPLE_CHECK ) && defined( DEBUG )
  #include "StdStream/Debug/a.hpp"
#else
  #include "StdStream/a.hpp"
#endif

DECLARATION_OF_ARITHMETICS_FOR_VECTOR( vector );
DECLARATION_OF_ARITHMETICS_FOR_VECTOR( list );
template <typename T> inline operator*( const T& scalar , vector<T> v );
DECLARATION_OF_SHIFT_FOR_VECTOR( basic_string );

// 宣言だけでは型推論できないので宣言はコメントアウトする。
// template <typename V> inline auto Get( V& a );

template <typename T = int> inline vector<T> id( const int& size );

template <typename T> inline void Sort( vector<T>& a , const bool& reversed = false );
template <typename T0 , typename T1> inline void Sort( vector<T0>& a , vector<T1>& b , const bool& reversed = false );
template <typename T> inline vector<int> IndexSort( const vector<T>& a , const bool& reversed = false );

template <typename V> inline int len( const V& a );

template <typename T> inline T pop( vector<T>& a );

template <typename V> inline void Reverse( V& a );
template <typename V> inline V Reversed( V a );
