// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/CumulativeProd/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/946991�i���ݐϐρj
// https://atcoder.jp/contests/agc023/submissions/49678399�i���E��Ԑϋt�������グ�j

// �؏�ŌQ�ɒl�����֐��̗ݐϐς��v�Z����B
template <typename U>
class VirtualCumulativeProd
{

public:
  // 0 <= i,j < m_size�̏ꍇ�̂݃T�|�[�g�B
  // i����ւ�path��i=v_0->...->v_k=j�̎��ASet�����z��a�ɑ΂���
  // �E����a[v_0]...a[v_k]���v�Z����B
  virtual U PathProd( const int& i , const int& j ) = 0;

protected:
  virtual int Parent( const int& i ) = 0;
  virtual int LCA( const int& i , const int& j ) = 0;

};

template <typename U , typename GROUP>
class PathProdImplementation :
  virtual public VirtualCumulativeProd<U>
{

protected:
  int m_size;
  GROUP m_M;
  vector<U> m_right;
  vector<U> m_left;

public:
  inline PathProdImplementation( const int& size , GROUP M );
  inline U PathProd( const int& i , const int& j );

};


// �؂����ɒʏ�̔z��ł���ꍇ�B
// ���͈͓͂̔��ŗv��
// (1) M��U�̌Q�\���ł���B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B

// M.one()�ɂ�鏉����O(size)
// �z��ɂ�鏉����O(size)

// ��_����ZO(size)
// ��_�E��ZO(size)

// �E��Ԑώ擾O(1)
// ����Ԑώ擾O(1)

// �E��Ԑϋt�������グO(size log size)
// �E��Ԑϋt�������グO(size log size)
template <typename U , typename GROUP>
class CumulativeProd :
  public PathProdImplementation<U,GROUP>
{

public:
  inline CumulativeProd( const int& size , GROUP M );
  template <typename V> inline CumulativeProd( const vector<V>& a , GROUP M );

  template <typename V> inline void Set( const vector<V>& a );
  // a[i]��M.Product(t,a[i])�ɒu���ς���B
  inline void LeftMultiply( const int& i , const U& t );
  // a[i]��M.Product(a[i],t)�ɒu���ς���B
  inline void RightMultiply( const int& i , const U& t );

  // 0 <= i����i-1 <= j < m_size�̏ꍇ�̂݃T�|�[�g�B
  // �E��Ԑ�a[i]...a[j]��M�Ɋւ��Čv�Z����B
  inline U RightProd( const int& i , const int& j );
  // ����Ԑ�a[j]...a[i]��M�Ɋւ��Čv�Z����B
  inline U LeftProd( const int& i , const int& j );

  // �ȉ���M.Product()�����g�p���Ȃ��̂ŁAM.Product()���Q���Z�ł��������M.One()��M.Inverse()�����֌W�ȉ��Z�ł��悢�B
  // M�Ɋւ���E��Ԑ�a[i]...a[j]��t�Ɠ��������[i,j]�̌����v�Z����B
  ll CountRightProdInverseImage( const U& t = One() );
  // M�Ɋւ��鍶��Ԑ�a[j]...a[i]��t�Ɠ��������[i,j]�̌����v�Z����B
  ll CountLeftProdInverseImage( const U& t = One() );

private:
  inline int Parent( const int& i );
  inline int LCA( const int& i , const int& j );
  inline const U& One() const;

};
template <typename GROUP> CumulativeProd( GROUP M ) -> CumulativeProd<inner_t<GROUP>,GROUP>;
template <typename V , typename GROUP> CumulativeProd( const vector<V>& a , GROUP M ) -> CumulativeProd<inner_t<GROUP>,GROUP>;
