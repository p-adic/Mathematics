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

// �錾�����ł͌^���_�ł��Ȃ��̂Ő錾�̓R�����g�A�E�g����B
// template <typename V> inline auto Get( V& a );

template <typename T = int> inline vector<T> id( const int& size );

template <typename V> inline void Sort( V& a , const bool& reversed = false );
template <typename V0 , typename V1> inline void Sort( V0& a , V1& b , const bool& reversed = false );
// {index[j]=A���j�Ԗڂ̓Y��,ord[i]=i�����Ԗڂ̓Y����=index^{-1}[i]}
template <typename V> inline pair<vector<int>,vector<int>> IndexSort( const V& a , const bool& reversed = false );

template <typename V> inline int len( const V& a );

template <typename V> inline void Reverse( V& a );
template <typename V> inline V Reversed( V a );

template <typename RET , template <typename...> typename V , typename T> inline V<RET> cast( const V<T>& a );
