// c:/Users/user/Documents/Programming/Utility/String/RollingHash/a.hpp

#pragma once
#include "a_Macro.hpp"

// verify:
// https://yukicoder.me/submissions/981380�iEncode�j
// https://yukicoder.me/submissions/982690�iCumulativeEncode�j

// �f���̌��
// { 999182201 , 999281719 , 999309403 , 999391993 , 999462649 , 999582757 , 999682811 , 999728287 , 999892849 , 999927217 };

// MODINT�͑f����@�Ƃ��鐮���^�B
// ��������E�����ɁA�z���Y�������Ɏ����t�����ăn�b�V��������B
// Fold�ȂǂŒ�����32bit�Ɏ��܂�Ȃ�����INT��ll�ɂ���B
template <typename MODINT , typename INT = int>
class RollingHash
{
  
private:
  INT m_size;
  MODINT m_r;
  MODINT m_r_inv;
  vector<MODINT> m_r_power;

public:
  inline RollingHash( MODINT r );

  inline const MODINT& r() const noexcept;
  inline const MODINT& r_inv() const noexcept;
  inline const vector<MODINT>& r_power() const noexcept;
  
  // s��{�n�b�V��,r^����,����}�ŃR�[�h����B�iO(s.size())�j
  template <typename STR> inline tuple<MODINT,MODINT,INT> Encode( const STR& s , const bool& reversed = false );
  template <typename STR , typename Enum> tuple<MODINT,MODINT,INT> Encode( const STR& s , Enum& e , const bool& reversed = false );
  
  // {s[:0]�̃n�b�V��,s[:1]�̃n�b�V��,...}��Ԃ��B�iO(s.size())�j
  template <typename STR> inline vector<MODINT> CumulativeEncode( const STR& s , const bool& reversed = false );
  template <typename STR , typename Enum> vector<MODINT> CumulativeEncode( const STR& s , Enum& e , const bool& reversed = false );
  
  // {s[0]�̃R�[�h,s[1]�̃R�[�h,...}��Ԃ��B�iO(s.size())�j
  template <typename STR> inline vector<tuple<MODINT,MODINT,INT>> PointwiseEncode( const STR& s , const bool& reversed = false );
  template <typename STR , typename Enum> vector<tuple<MODINT,MODINT,INT>> PointwiseEncode( const STR& s , Enum& e , const bool& reversed = false );

  template <typename CHAR> inline tuple<MODINT,MODINT,INT> Replace( tuple<MODINT,MODINT,INT> code , const INT& i , const CHAR& c_prev , const CHAR& c_next ) const;
  template <typename CHAR , typename Enum> tuple<MODINT,MODINT,INT> Replace( tuple<MODINT,MODINT,INT> code , const INT& i , const CHAR& c_prev , const CHAR& c_next , Enum& e ) const;
  
  // code�ŃR�[�h����镶����s�ɘA��������Ƃ��Ċ܂܂����̐���l��Ԃ��B�iO(s.size())�j
  template <typename STR> inline INT CountContain( const STR& s , const tuple<MODINT,MODINT,INT>& code , const bool& reversed = false );
  template <typename STR , typename Enum> INT CountContain( const STR& s , const tuple<MODINT,MODINT,INT>& code , Enum& e , const bool& reversed = false );

  // ������ɑ΂��Ă͒ʏ�̘A���A�z��ɑ΂��Ă͑�1�����ɑ�2������A�����鉉�Z���R�[�h�ɖ|��B�iO(1)�j
  static inline tuple<MODINT,MODINT,INT> Concatenate( tuple<MODINT,MODINT,INT> code0 , const tuple<MODINT,MODINT,INT>& code1 );
  static inline tuple<MODINT,MODINT,INT> Fold( tuple<MODINT,MODINT,INT> code , INT n );

private:
  void CheckSize( const INT& size );
  template <typename CHAR> static inline MODINT Enumeration( const CHAR& c );

};

