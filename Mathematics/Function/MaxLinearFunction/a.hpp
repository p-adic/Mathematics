// c:/Users/user/Documents/Programming/Mathematics/Function/MaxLinearFunction/a.hpp

#pragma once

// verify: https://yukicoder.me/submissions/908941

// ��{�I�ɉ��LURL��Convex Hull Trick�ɏ�����B
// https://rsk0315.hatenablog.com/entry/2022/04/29/141726

// �萔�֐�0�ɂ��\�zO(1)
// �ꎟ�֐��Ƃ�max�ɂ��X�VO(log size)
// ��_�擾O(log size)
template <typename INT , INT llim_a , INT ulim_a , INT llim_b , INT ulim_b , INT llim_c , INT ulim_c>
class MaxLinearFunction
{

private:
  // m_abc[�X��a] = { y�ؕ�b , �ő�l������ԍ��[��x���Wc } �Ƃ��ĊǗ��B
  map<INT,pair<INT,INT> > m_abc;
  // m_ca[�ő�l������ԍ��[��x���Wc] = �X��a �Ƃ��ĊǗ��B
  map<INT,INT> m_ca;

public:
  inline MaxLinearFunction();

  void SetMax( const INT& a , const INT& b );
  INT Get( const INT& x ) const;

private:
  static INT Intersection( const INT& a0 , const INT& b0 , const INT& a1 , const INT& b1 );
  
};

template <typename INT , INT llim_a , INT ulim_a , INT llim_b , INT ulim_b , INT llim_c , INT ulim_c>
class MinLinearFunction :
  public MaxLinearFunction<INT,-ulim_a,-llim_a,-ulim_b,-llim_b,llim_c,ulim_c>
{

public:
  inline MinLinearFunction();

  inline void SetMin( const INT& a , const INT& b );
  inline INT Get( const INT& x ) const;

};
