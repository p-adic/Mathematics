// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/CumulativeProd/a.hpp

#pragma once
// verify: https://atcoder.jp/contests/agc023/submissions/45472183

// ���͈͓͂̔��ŗv��
// (1) (T,m_T:T^2->T,i_T:T->T)���Q�ł���B
// �����藧�ꍇ�̂݃T�|�[�g�B�i�P�ʌ��̓e���v���[�g�����ɓn���Ȃ��Ă悢�j
template <typename T , T m_T(const T&,const T&) , T i_T(const T&) , int size_max>
class CumulativeProd_Body
{

protected:
  int m_size;
  T m_a[size_max];
  T m_a_reverse[size_max];

public:
  inline CumulativeProd_Body( const int& size );

  // 0 <= i,j < m_size�̏ꍇ�̂݃T�|�[�g�B
  // i����ւ�path��i=v_0->...->v_k=j�̎�m_a[v_0]...m_a[v_k]��
  // Prod��t����Prod�Ɋւ��Čv�Z����B
  inline T PathProd( const int& i , const int& j );

private:
  virtual int Parent( const int& i ) = 0;
  virtual int LCA( const int& i , const int& j ) = 0;

};


// �ʏ�̔z���̗ݐϐρB
// �e���v���[�g�����ɒP�ʌ�e_T:1->T���n���B

// �z��ɂ�鏉����O(size)

// �E��Ԑώ擾O(1)
// ����Ԑώ擾O(1)

// ��Ԑς��P�ʌ��ł����Ԃ̐����グO(size log size)
// ��Ԑς��P�ʌ��ł����Ԃ̗�O(size log size + ��Ԑ�)
template <typename T , T m_T(const T&,const T&) , const T& e_T() , T i_T(const T&) , int size_max>
class CumulativeProd :
  public CumulativeProd_Body<T,m_T,i_T,size_max>
{

public:
  inline CumulativeProd( const T ( &a )[size_max] , const int& size );

  // 0 <= i����i-1 <= j < m_size�̏ꍇ�̂݃T�|�[�g�B
  // m_a[i]...m_a[j]��m_T�Ɋւ��ĂŌv�Z����B
  inline T RightProd( const int& i , const int& j );
  // m_a[j]...m_a[i]��m_T�Ɋւ��Čv�Z����B
  inline T LeftProd( const int& i , const int& j );

  // ��Ԑς�e_T()�Ɠ�������Ԃ̌����v�Z����B
  ll CountUnitProdRange();
  // ��Ԑς�e_T()�Ɠ�������Ԃ�񋓂���B
  list<pair<int,int> > UnitProdRange();
  
private:
  inline int Parent( const int& i );
  inline int LCA( const int& i , const int& j );

};
