// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Monoid/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/950162�i�돉�����A��_��Z�A��Ԑρj
// https://yukicoder.me/submissions/950344�i�z�񏉊����A��_����A��Ԑρj

// ���͈͓͂̔��ŗv��
// (1) M��U�̉����m�C�h�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// ��_��Z�ȊO��MonoidBIT�̉��ʌ݊��ł���̂ň�_��Z���s�v�Ȃ�MonoidBIT���g���Ηǂ��B

// M.One()�ɂ�鏉����O(N)
// �z��ɂ�鏉����O(N)

// ��_�擾O(1)
// M.Product()�Ɋւ����Ԑώ擾O(N^{1/2})

// ��_���O(N^{1/2})
// M.Product()�ɂ���_��ZO(1)�i�������g���j

// �ȉ����͈͓͂̔��ŗv��
// (2) bool operator<(const U&,const U&)�Ɋւ���M��U�̑S���������m�C�h�\���ł���B
// (3) m_a,m_b�̑S�Ă̐�����M.One()�ȏ�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// M.Product()�Ɋւ����Ԑς̒l�T��O(N^{1/2})
template <typename U , typename COMM_MONOID>
class MonoidSqrtDecomposition
{

protected:
  COMM_MONOID m_M;
  int m_N;
  int m_N_sqrt;
  int m_N_d;
  int m_N_m;
  vector<U> m_a;
  vector<U> m_b;
  
public:
  inline MonoidSqrtDecomposition( COMM_MONOID M , const int& N );
  inline MonoidSqrtDecomposition( COMM_MONOID M , const int& N , const int& N_sqrt );
  inline MonoidSqrtDecomposition( COMM_MONOID M , vector<U> a );
  inline MonoidSqrtDecomposition( COMM_MONOID M , vector<U> a , const int& N_sqrt );

  template <typename...Args> inline void Reset( Args&&... args );
  inline void Set( const int& i , const U& u );
  inline void Multiply( const int& i , const U& u );

  inline const U& operator[]( const int& i ) const;
  inline const U& Get( const int& i ) const;
  inline U IntervalProduct( const int& i_start , const int& i_final );

  // u <= IntervalProduct( i_start , i_final )�𖞂���i_start�ȏ�̍ŏ���i_final��T���B
  // ���݂��Ȃ��ꍇ��-1��Ԃ��B
  inline int Search( const int& i_start , const U& u );
  
private:
  int Search_Body( const int& i_start , const U& u , U sum_temp );
  
};
template <typename COMM_MONOID , typename...Args> MonoidSqrtDecomposition( COMM_MONOID M , Args&&...args ) -> MonoidSqrtDecomposition<inner_t<COMM_MONOID>,COMM_MONOID>;
