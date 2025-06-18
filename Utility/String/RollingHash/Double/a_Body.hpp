// c:/Users/user/Documents/Programming/Mathematics/Utility/String/RollingHash/Double/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

#include "../../../Tuple/Wrap/a_Body.hpp"

template <typename RH0 , typename RH1 , typename CODE , typename VCODE> inline RollingHashPair<RH0,RH1,CODE,VCODE>::RollingHashPair() : m_rh0() , m_rh1() {}

template <typename RH0 , typename RH1 , typename CODE , typename VCODE> inline RH0& RollingHashPair<RH0,RH1,CODE,VCODE>::operator[]( const TupleAccessIndex<0>& i ) noexcept { return m_rh0; }
template <typename RH0 , typename RH1 , typename CODE , typename VCODE> inline RH1& RollingHashPair<RH0,RH1,CODE,VCODE>::operator[]( const TupleAccessIndex<1>& i ) noexcept { return m_rh1; }

template <typename RH0 , typename RH1 , typename CODE , typename VCODE> template <typename STR> inline CODE RollingHashPair<RH0,RH1,CODE,VCODE>::Encode( const STR& s , const bool& reversed ) { return {m_rh0.Encode(s,reversed),m_rh1.Encode(s,reversed)}; }

template <typename RH0 , typename RH1 , typename CODE , typename VCODE> template <typename STR> inline VCODE RollingHashPair<RH0,RH1,CODE,VCODE>::CumulativeEncode( const STR& s , const bool& reversed ) { return {m_rh0.CumulativeEncode(s,reversed),m_rh1.CumulativeEncode(s,reversed)}; }

template <typename RH0 , typename RH1 , typename CODE , typename VCODE> template <typename STR> inline VCODE RollingHashPair<RH0,RH1,CODE,VCODE>::PointwiseEncode( const STR& s , const bool& reversed ) { return {m_rh0.PointwiseEncode(s,reversed),m_rh1.PointwiseEncode(s,reversed)}; }

template <typename RH0 , typename RH1 , typename CODE , typename VCODE> template <typename STR> inline VCODE RollingHashPair<RH0,RH1,CODE,VCODE>::FixedLengthEncode( const STR& s , const int& length , const bool& reversed ) { return {m_rh0.FixedLengthEncode(s,reversed),m_rh1.FixedLengthEncode(s,reversed)}; }

template <typename RH0 , typename RH1 , typename CODE , typename VCODE> template <typename CHAR , typename INT> inline CODE RollingHashPair<RH0,RH1,CODE,VCODE>::Replace( CODE code , const INT& i , const CHAR& c_prev , const CHAR& c_next ) const  { return {m_rh0.Replace(move(code[O]),i,c_prev,c_next),m_rh1.Replace(move(code[I]),i,c_prev,c_next)}; }

template <typename RH0 , typename RH1 , typename CODE , typename VCODE> template <typename CHAR , typename INT> inline CODE RollingHashPair<RH0,RH1,CODE,VCODE>::swap( CODE code , const INT& i , const INT& j , const CHAR& c_i , const CHAR& c_j ) const { return Replace( Replace( move( code ) , i , c_i , c_j ) , j , c_j , c_i ); }

template <typename RH0 , typename RH1 , typename CODE , typename VCODE> template <typename CHAR> inline CODE RollingHashPair<RH0,RH1,CODE,VCODE>::PopFront( CODE code , const CHAR& c_prev ) const { return {m_rh0.PopFront(move(code[O]),c_prev),m_rh1.PopFront(move(code[I]),c_prev)}; }

template <typename RH0 , typename RH1 , typename CODE , typename VCODE> template <typename CHAR> inline CODE RollingHashPair<RH0,RH1,CODE,VCODE>::PopBack( CODE code , const CHAR& c_prev ) const { return {m_rh0.PopBack(move(code[O]),c_prev),m_rh1.PopBack(move(code[I]),c_prev)}; }

template <typename RH0 , typename RH1 , typename CODE , typename VCODE> template <typename STR> inline int RollingHashPair<RH0,RH1,CODE,VCODE>::CountContain( const STR& s , const CODE& code , const bool& reversed )
{

  const int size0 = s.size();
  auto n = Pair{ get<0>( code[O] ) , get<0>( code[I] ) };
  auto& size1 = get<2>( code[O] );
  assert( size1 == get<2>( code[I] ) );

  if( size1 == 0 ){

    return 1;
    
  }
  
  auto r_power = Pair{ m_rh0.r_power( size1 - 1 ) , m_rh1.r_power( size1 - 1 ) };
  int answer = 0;
  decltype( r_power ) temp{};

  for( int i = 0 ; i < size0 ; i++ ){

    ( i < size1 ? temp += Pair{ m_rh0.Twist( s[reversed ? size0 - 1 - i : i] ) * m_rh0.r_power( i ) , m_rh1.Twist( s[reversed ? size0 - 1 - i : i] ) * m_rh1.r_power( i ) } : ( ( temp -= Pair{ m_rh0.Twist( s[reversed ? size0 + size1 - 1 - i : i - size1] ) , m_rh1.Twist( s[reversed ? size0 + size1 - 1 - i : i - size1] ) } ) *= Pair{ m_rh0.r_inv() , m_rh1.r_inv() } ) += Pair{ m_rh0.Twist( s[reversed ? size0 - 1 - i : i] ) , m_rh1.Twist( s[reversed ? size0 - 1 - i : i] ) } * r_power ) == n ? ++answer : answer;

  }

  return answer;

}

template <typename RH0 , typename RH1 , typename CODE , typename VCODE> inline CODE RollingHashPair<RH0,RH1,CODE,VCODE>::Concatenate( CODE code0 , const CODE& code1 ) { return {RH0::Concatenate(move(code0[O]),code1[O]),RH1::Concatenate(move(code0[I]),code1[I])}; }

template <typename RH0 , typename RH1 , typename CODE , typename VCODE> template <typename INT> inline CODE RollingHashPair<RH0,RH1,CODE,VCODE>::Fold( CODE code , const INT& n ) { return {RH0::Fold(move(code[O]),n),RH1::Fold(move(code[I]),n)}; }
