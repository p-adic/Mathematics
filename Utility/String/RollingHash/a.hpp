// c:/Users/user/Documents/Programming/Utility/String/RollingHash/a.hpp

#pragma once
#include "a_Macro.hpp"

// verify:
// https://yukicoder.me/submissions/981380 (Encode)
// https://yukicoder.me/submissions/982690 (CumulativeEncode)
// https://yukicoder.me/submissions/1013739 (FixedLengthEncode)

// �f���̌��
// { 999182201 , 999281719 , 999309403 , 999391993 , 999462649 , 999582757 , 999682811 , 999728287 , 999892849 , 999927217 };

// MODINT�͑f����@�Ƃ��鐮���^�B
// ��������E�����ɁA�z���Y�������Ɏ����t�����ăn�b�V��������B�ireversed=true�Ŕ��]�j
// Fold�ȂǂŒ�����32bit�Ɏ��܂�Ȃ�����INT��ll�ɂ���B
template <typename MODINT , typename INT = int , typename CODE = tuple<MODINT,MODINT,INT>>
class RollingHash
{
  
protected:
  INT m_size;
  MODINT m_r;
  MODINT m_r_inv;
  vector<MODINT> m_r_power;

public:
  inline RollingHash();
  inline RollingHash( MODINT r );

  inline const MODINT& r() const noexcept;
  inline const MODINT& r_inv() const noexcept;
  inline const vector<MODINT>& r_power() const noexcept;
  
  // s��{�n�b�V��,r^����,����}�ŃR�[�h����B�iO(s.size())�j
  template <typename STR> inline CODE Encode( const STR& s , const bool& reversed = false );
  
  // {s[:0]�̃R�[�h,s[:1]�̃R�[�h,...}��Ԃ��B�iO(s.size())�j
  template <typename STR> inline vector<CODE> CumulativeEncode( const STR& s , const bool& reversed = false );
  
  // {s[0]�̃R�[�h,s[1]�̃R�[�h,...}��Ԃ��B�iO(s.size())�j
  template <typename STR> inline vector<CODE> PointwiseEncode( const STR& s , const bool& reversed = false );

  // {s[0:length]�̃R�[�h,s[1:length+1]�̃R�[�h,...}��Ԃ��B�iO(s.size())�j
  template <typename STR> inline vector<CODE> FixedLengthEncode( const STR& s , const int& length , const bool& reversed = false );

  template <typename CHAR> inline CODE Replace( CODE code , const INT& i , const CHAR& c_prev , const CHAR& c_next ) const;

  template <typename CHAR> inline CODE PopFront( CODE code , const CHAR& c_prev ) const;
  template <typename CHAR> inline CODE PopBack( CODE code , const CHAR& c_prev ) const;
  
  // code�ŃR�[�h����镶����s�ɘA��������Ƃ��Ċ܂܂����̐���l��Ԃ��B�iO(s.size())�j
  template <typename STR> inline INT CountContain( const STR& s , const CODE& code , const bool& reversed = false );

  // ������ɑ΂��Ă͒ʏ�̘A���A�z��ɑ΂��Ă͑�1�����ɑ�2������A�����鉉�Z���R�[�h�ɖ|��B�iO(1)�j
  static inline CODE Concatenate( CODE code0 , const CODE& code1 );
  static inline CODE Fold( CODE code , INT n );

protected:
  MODINT GetRand();
  void CheckSize( const INT& size );
  virtual MODINT Twist( const ll& c );

};

