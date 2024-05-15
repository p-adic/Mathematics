// c:/Users/user/Documents/Programming/Mathematics/Function/MaxLinearFunction/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/981573

// ��{�I�ɉ��LURL��Convex Hull Trick�ɏ�����B
// https://rsk0315.hatenablog.com/entry/2022/04/29/141726

// �萔�֐�0�ɂ��\�zO(1)
// �ꎟ�֐��Ƃ�max�ɂ��S�̍X�VO(log size)
// ��_�擾O(log size)
template <typename INT>
class MaxLinearFunction
{

private:
  // m_abc[�X��a] = { y�ؕ�b , �ő�l������ԍ��[��x���Wc } �Ƃ��ĊǗ��B
  map<INT,pair<INT,INT> > m_abc;
  // m_ca[�ő�l������ԍ��[��x���Wc] = �X��a �Ƃ��ĊǗ��B
  map<INT,INT> m_ca;
  INT m_llim_c;
  INT m_ulim_c;

public:
  inline MaxLinearFunction( const INT& llim_c , const INT& ulim_c );

  void SetMax( const INT& a , const INT& b );
  INT Get( const INT& x ) const;

private:
  static INT Intersection( const INT& a0 , const INT& b0 , const INT& a1 , const INT& b1 );
  
};

template <typename INT>
class MinLinearFunction :
  public MaxLinearFunction<INT>
{

public:
  inline MinLinearFunction( const INT& llim_c , const INT& ulim_c );

  inline void SetMin( const INT& a , const INT& b );
  inline INT Get( const INT& x ) const;

};
