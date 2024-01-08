// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/CumulativeProd/a.hpp

#pragma once
#include "a_Macro.hpp"

// verify: https://atcoder.jp/contests/agc023/submissions/49156204�i���E��Ԑϋt�������グ�j

// ���͈͓͂̔��ŗv��
// (1) (T,m_T:T^2->T,i_T:T->T)���Q�ł���B
// �����藧�ꍇ�̂݃T�|�[�g�B�i�P�ʌ��̓e���v���[�g�����ɓn���Ȃ��Ă悢�j
template <typename T , T m_T(const T&,const T&) , T i_T(const T&)>
class CumulativeProd_Body
{

protected:
  int m_size;
  vector<T> m_right;
  vector<T> m_left;

public:
  inline CumulativeProd_Body( const int& size = 0 );

  // 0 <= i,j < m_size�̏ꍇ�̂݃T�|�[�g�B
  // i����ւ�path��i=v_0->...->v_k=j�̎��ASet�����z��a�ɑ΂���
  // �E����a[v_0]...a[v_k]���v�Z����B
  inline T PathProd( const int& i , const int& j );

private:
  virtual int Parent( const int& i ) = 0;
  virtual int LCA( const int& i , const int& j ) = 0;

};

// �ʏ�̔z���̗ݐϐρB
// �e���v���[�g�����ɒP�ʌ�e_T:1->T���n���B

// e_T�ɂ�鏉����O(size)
// �z��ɂ�鏉����O(size)

// ��_����ZO(size)
// ��_�E��ZO(size)

// �E��Ԑώ擾O(1)
// ����Ԑώ擾O(1)

// �E��Ԑϋt�������グO(size log size)
// �E��Ԑϋt�������グO(size log size)
template <typename T , T m_T(const T&,const T&) , const T& e_T() , T i_T(const T&)>
class CumulativeProd :
  public CumulativeProd_Body<T,m_T,i_T>
{

public:
  inline CumulativeProd( const int& size = 0 );
  template <typename U , SFINAE_FOR_CUMULATIVE_PROD( = nullptr )> inline CumulativeProd( const vector<U>& a );

  template <typename U , SFINAE_FOR_CUMULATIVE_PROD( = nullptr )> inline void Set( const vector<U>& a );
  // a[i]��m_T(t,a[i])�ɒu���ς���B
  inline void LeftMultiply( const int& i , const T& t );
  // a[i]��m_T(a[i],t)�ɒu���ς���B
  inline void RightMultiply( const int& i , const T& t );
  
  // 0 <= i����i-1 <= j < m_size�̏ꍇ�̂݃T�|�[�g�B
  // �E��Ԑ�a[i]...a[j]��m_T�Ɋւ��Čv�Z����B
  inline T RightProd( const int& i , const int& j );
  // ����Ԑ�a[j]...a[i]��m_T�Ɋւ��Čv�Z����B
  inline T LeftProd( const int& i , const int& j );

  // �ȉ���e_T��i_T���g�p���Ȃ��̂ŁAm_T���Q���Z�ł��������e_T��i_T��m_T�Ɩ��֌W�Ȃ��̂ɂ��Ă��悢�B
  // �E��Ԑ�a[i]...a[j]��t�Ɠ��������[i,j]�̌����v�Z����B
  ll CountRightProdInverseImage( const T& t );
  // ����Ԑ�a[j]...a[i]��t�Ɠ��������[i,j]�̌����v�Z����B
  ll CountLeftProdInverseImage( const T& t );
  
private:
  inline int Parent( const int& i );
  inline int LCA( const int& i , const int& j );

};
