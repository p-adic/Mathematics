// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/IntervalSet/a.hpp

#pragma once
#include "../Sqrt/a.hpp"

// ���͈͓͂̔��ŗv��
// (1) M��operator<(const U&const U&)�Ɋւ���U�̑S����Z���Q�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// M.Zero()�ɂ�鏉����O(N log N)
// �z��ɂ�鏉����O(N log N)

// ��_�擾O(1)
// M.Sum()�Ɋւ����Ԑώ擾O((N log N)^{1/2})

// ��_�ő�l�X�VO(log(N/log(N)))
// ��ԍő�l�X�VO((N log N)^{1/2})
template <typename U , typename Z_MODULE>
class IntervalSetMaxAbstractSqrtDecomposition :
  public SqrtDecompositionCoordinate
{

protected:
  Z_MODULE m_M;
  vector<U> m_a;
  vector<U> m_b;
  U m_val_min;
  vector<U> m_lazy_set_max;
  vector<bool> m_a_updated;
  vector<int> m_b_updated;

  // m_lazy_set_max[d]���傫��������m_set[d]�Ɋi�[����B
  vector<set<pair<U,int>>> m_set;
  
public:
  inline IntervalSetMaxAbstractSqrtDecomposition( const Z_MODULE& M , const U& val_min , const int& N = 0 );
  IntervalSetMaxAbstractSqrtDecomposition( Z_MODULE M , const U& val_min , vector<U> a );

  template <typename...Args> inline void Initialise( Args&&... args );
  inline void SetMax( const int& i , const U& u );
  inline void IntervalSetMax( const int& i_start , const int& i_final , const U& u );

  // �Q�ƕԂ��łȂ����Ƃɒ���
  inline U operator[]( const int& i );
  inline U Get( const int& i );
  inline U IntervalSum( const int& i_start , const int& i_final );

private:
  IntervalSetMaxAbstractSqrtDecomposition( Z_MODULE& M , const U& val_min , const int& N , vector<U>& a );
  inline void IntervalSetMax_Body( const int& i_min , const int& i_ulim , const int& d , const U& u );
  inline U IntervalSum_Body( const int& i_min , const int& i_ulim , const int& d );
  
};
template <typename Z_MODULE , typename...Args> IntervalSetMaxAbstractSqrtDecomposition( Z_MODULE M , Args&&... args ) -> IntervalSetMaxAbstractSqrtDecomposition<inner_t<Z_MODULE>,Z_MODULE>;

template <typename U = ll>
class IntervalSetMaxSqrtDecomposition :
  public IntervalSetMaxAbstractSqrtDecomposition<U,Module<int,U>>
{

public:
  template <typename...Args> inline IntervalSetMaxSqrtDecomposition( Args&&... args );

};
template <typename U , typename...Args> IntervalSetMaxSqrtDecomposition( const U& val_min , Args&&... args ) -> IntervalSetMaxSqrtDecomposition<U>;

template <class Traits , typename U , typename Z_MODULE> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , IntervalSetMaxAbstractSqrtDecomposition<U,Z_MODULE>& sd );

// - ����Z���Q���悹�鎞��
//   IntervalSetMaxSqrtDecomposition<ll> sd( ll( -1e18 ) , A );
// - AbstractModule���悹�鎞��
//   IntervalSetMaxAbstractSqrtDecomposition sd( AbstructModule( 0 , action , AbstractMonoid( product , unit ) ) , val_min , A );
// �Ƃ���΂悢�B

