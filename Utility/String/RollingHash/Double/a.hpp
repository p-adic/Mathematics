// c:/Users/user/Documents/Programming/Mathematics/Utility/String/RollingHash/Double/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1099665

#include "../a.hpp"
#include "../../../Tuple/Wrap/a.hpp"

template <typename RH0 , typename RH1 , typename CODE = Pair<decltype(declval<RH0>().Encode("")),decltype(declval<RH1>().Encode(""))> , typename VCODE = Pair<decltype(declval<RH0>().CumulativeEncode("")),decltype(declval<RH1>().CumulativeEncode(""))>>
class RollingHashPair
{
  
protected:
  RH0 m_rh0;
  RH1 m_rh1;

public:
  inline RollingHashPair();

  inline RH0& operator[]( const TupleAccessIndex<0>& i ) noexcept;
  inline RH1& operator[]( const TupleAccessIndex<1>& i ) noexcept;

  // sを{ハッシュ,r^長さ,長さ}でコードする。（O(s.size())）
  template <typename STR> inline CODE Encode( const STR& s , const bool& reversed = false );
  
  // {s[:0]のコード,s[:1]のコード,...}を返す。（O(s.size())）
  template <typename STR> inline VCODE CumulativeEncode( const STR& s , const bool& reversed = false );
  
  // {s[0]のコード,s[1]のコード,...}を返す。（O(s.size())）
  template <typename STR> inline VCODE PointwiseEncode( const STR& s , const bool& reversed = false );

  // {s[0:length]のコード,s[1:length+1]のコード,...}を返す。（O(s.size())）
  template <typename STR> inline VCODE FixedLengthEncode( const STR& s , const int& length , const bool& reversed = false );

  template <typename CHAR , typename INT> inline CODE Replace( CODE code , const INT& i , const CHAR& c_prev , const CHAR& c_next ) const;
  template <typename CHAR , typename INT> inline CODE swap( CODE code , const INT& i , const INT& j , const CHAR& c_i , const CHAR& c_j ) const;

  template <typename CHAR> inline CODE PopFront( CODE code , const CHAR& c_prev ) const;
  template <typename CHAR> inline CODE PopBack( CODE code , const CHAR& c_prev ) const;
  
  // codeでコードされる文字列がsに連続部分列として含まれる個数の推定値を返す。（O(s.size())）
  template <typename STR> inline int CountContain( const STR& s , const CODE& code , const bool& reversed = false );

  // 文字列に対しては通常の連結、配列に対しては第1引数に第2引数を連結する演算をコードに翻訳。（O(1)）
  static inline CODE Concatenate( CODE code0 , const CODE& code1 );
  template <typename INT> static inline CODE Fold( CODE code , const INT& n );

};

#include "a_Alias.hpp"
// DoubleRollingHash<M0,M1,INT> = RollingHashPair<RollingHash<Mod<M0>,INT>,RollingHash<Mod<M1>,INT>>;
// TripleRollingHash<M0,M1,M2> = RollingHashPair<DoubleRollingHash<M0,M1,INT>,RollingHash<Mod<M2>,INT>>;
