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

  // s��{�n�b�V��,r^����,����}�ŃR�[�h����B�iO(s.size())�j
  template <typename STR> inline CODE Encode( const STR& s , const bool& reversed = false );
  
  // {s[:0]�̃R�[�h,s[:1]�̃R�[�h,...}��Ԃ��B�iO(s.size())�j
  template <typename STR> inline VCODE CumulativeEncode( const STR& s , const bool& reversed = false );
  
  // {s[0]�̃R�[�h,s[1]�̃R�[�h,...}��Ԃ��B�iO(s.size())�j
  template <typename STR> inline VCODE PointwiseEncode( const STR& s , const bool& reversed = false );

  // {s[0:length]�̃R�[�h,s[1:length+1]�̃R�[�h,...}��Ԃ��B�iO(s.size())�j
  template <typename STR> inline VCODE FixedLengthEncode( const STR& s , const int& length , const bool& reversed = false );

  template <typename CHAR , typename INT> inline CODE Replace( CODE code , const INT& i , const CHAR& c_prev , const CHAR& c_next ) const;
  template <typename CHAR , typename INT> inline CODE swap( CODE code , const INT& i , const INT& j , const CHAR& c_i , const CHAR& c_j ) const;

  template <typename CHAR> inline CODE PopFront( CODE code , const CHAR& c_prev ) const;
  template <typename CHAR> inline CODE PopBack( CODE code , const CHAR& c_prev ) const;
  
  // code�ŃR�[�h����镶����s�ɘA��������Ƃ��Ċ܂܂����̐���l��Ԃ��B�iO(s.size())�j
  template <typename STR> inline int CountContain( const STR& s , const CODE& code , const bool& reversed = false );

  // ������ɑ΂��Ă͒ʏ�̘A���A�z��ɑ΂��Ă͑�1�����ɑ�2������A�����鉉�Z���R�[�h�ɖ|��B�iO(1)�j
  static inline CODE Concatenate( CODE code0 , const CODE& code1 );
  template <typename INT> static inline CODE Fold( CODE code , const INT& n );

};

#include "a_Alias.hpp"
// DoubleRollingHash<M0,M1,INT> = RollingHashPair<RollingHash<Mod<M0>,INT>,RollingHash<Mod<M1>,INT>>;
// TripleRollingHash<M0,M1,M2> = RollingHashPair<DoubleRollingHash<M0,M1,INT>,RollingHash<Mod<M2>,INT>>;
