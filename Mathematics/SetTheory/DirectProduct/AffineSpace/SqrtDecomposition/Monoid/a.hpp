// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Monoid/a.hpp

#pragma once
#include "../a_Macro.hpp"

#include "../Sqrt/a.hpp"

// verify:
// https://yukicoder.me/submissions/981581�i�z�񏉊����A��_����A��Ԑρj

// ���͈͓͂̔��ŗv��
// (1) M��U�̃��m�C�h�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �����m�C�h���������̊��N���X�̂��߂̌^�ł��肱��P�̂ł�MonoidBIT�̉��ʌ݊��ł���B

// M.One()�ɂ�鏉����O(N)
// �z��ɂ�鏉����O(N)

// ��_�擾O(1)
// M.Product()�Ɋւ���E��Ԑώ擾O(N^{1/2})�iIntervalProduct(l,r)��a[l]*...*a[r]��Ԃ��j

// ��_���O(N^{1/2})

// �ȉ����͈͓͂̔��ŗv��
// (2) bool operator<(const U&,const U&)�Ɋւ���M��U�̑S�������m�C�h�\���ł���B
// (3) m_a,m_b�̑S�Ă̐�����M.One()�ȏ�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// M.Product()�Ɋւ����Ԑς̒l�T��O(N^{1/2})
template <typename U , typename MONOID>
class MonoidSqrtDecomposition :
  public SqrtDecompositionCoordinate
{

protected:
  MONOID m_M;
  vector<U> m_a;
  vector<U> m_b;
  
public:
  template <typename...Args> inline MonoidSqrtDecomposition( MONOID M , const int& N = 0 , const Args&... args );
  template <typename...Args> inline MonoidSqrtDecomposition( MONOID M , vector<U> a , const Args&... args );

  template <typename...Args> inline void Initialise( Args&&... args );
  inline void Set( const int& i , const U& u );

  inline const U& operator[]( const int& i ) const;
  inline const U& Get( const int& i ) const;
  inline U IntervalProduct( const int& i_start , const int& i_final );

  // F�͐Ϗ����Ɋւ��ĒP���Ȏʑ�f:U \times int -> {0,1}�ɑ�������^�B
  // f( IntervalProduct( i_start , i ) , i )��true�ƂȂ�i_start�ȏ�̍ŏ���i��T���B
  // ���݂��Ȃ��ꍇ��-1��Ԃ��B
  template <typename F , SFINAE_FOR_SD_S = nullptr> inline int Search( const int& i_start , const F& f );
  // u <= IntervalProduct( i_start , i )�𖞂���i_start�ȏ�̍ŏ���i��T���B
  // ���݂��Ȃ��ꍇ��-1��Ԃ��B
  inline int Search( const int& i_start , const U& u );
  
private:
  template <typename F> int Search_Body( const int& i_start , const F& f , U product_temp );
  
};
template <typename MONOID , typename...Args> MonoidSqrtDecomposition( MONOID M , Args&&...args ) -> MonoidSqrtDecomposition<inner_t<MONOID>,MONOID>;

// �Ⴆ��max�����Z�ɂ��鎞��MaxSemilattice{ 0LL }�Ȃǂ�n���B
// Search�̑召������t�ɂ��������͔z���-1�{����B

