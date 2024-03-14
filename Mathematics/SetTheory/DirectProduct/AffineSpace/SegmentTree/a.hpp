// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SegmentTree/a.hpp

#pragma once
#include "../../../../Algebra/Monoid/a.hpp"

// verify:
// https://yukicoder.me/submissions/959653�iAbstract�A�z��ɂ�鏉�����A��_�X�V�A��Ԑώ擾�j
// https://yukicoder.me/submissions/947852�i�z��ɂ�鏉�����A��_�X�V�A��Ԑώ擾�j

// M.One()�ɂ�鏉����O(size)
// �z��ɂ�鏉����O(N)

// ��_�X�VO(log_2 N)

// ��_�擾O(1)
// ��Ԑώ擾O(log_2 N)
template <typename U , typename MONOID>
class AbstractSegmentTree
{
private:
  MONOID m_M;
  int m_size;
  int m_power;
  vector<U> m_a;

public:
  inline AbstractSegmentTree( MONOID M , const int& size = 0 );
  inline AbstractSegmentTree( MONOID M , const vector<U>& a );

  template <typename...Args> inline void Initialise( const Args&... args );
  void Set( const int& i , const U& u );

  inline const U& operator[]( const int& i ) const;
  inline const U& Get( const int& i ) const;
  U IntervalProduct( const int& i_start , const int& i_final );

};
template <typename MONOID , typename...Args> AbstractSegmentTree( MONOID M , const Args&... args ) -> AbstractSegmentTree<inner_t<MONOID>,MONOID>;

template <typename U>
class SegmentTree :
  public AbstractSegmentTree<U,MultiplicativeMonoid<U>>
{

public:
  template <typename...Args> inline SegmentTree( const U& one_U , const Args&... args );

};
