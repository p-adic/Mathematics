// c:/Users/user/Documents/Programming/Mathematics/Function/Iteration/Doubling/a.hpp

#pragma once

// verify:
// https://atcoder.jp/contests/abc013/submissions/49214926�iDoubling�j
// https://yukicoder.me/submissions/942761�iDoubling�j
// https://yukicoder.me/submissions/942770�iMemorisationDoubling�j
// https://yukicoder.me/submissions/942771�iEnumerationDoubling�j

// 2^16 = 65536
// 2^17 = 131072
// 2^18 = 262144
// 2^60 = 1152921504606846976 > 10^18
// 2^63 = 9223372036854775808 < 10^19

// F��T->U(-->T)�ɑ�������^
template <typename T , typename F>
class Doubling_Body
{
  
protected:
  F m_f;
  int m_size;
  int m_digit;
  vector<vector<int> > m_doubling;
  
  inline Doubling_Body( F f , const int& size , const int& digit );
  
public:
  // f^n(t)���v�Z����B
  template <typename INT> T IteratedComposition( T t , INT n );

private:
  virtual T e( const int& i ) = 0;
  virtual int e_inv( const T& t ) = 0;

};

// size�����̔񕉐����S�̂̏W����S�ƒu���B�v��
// (1) S�̔C�ӂ̗v�fi�ɑ΂�f(i)��S�̗v�f�ł���B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B

// S�̊e�v�ft��n < 2^digit�𖞂����e�񕉐���n���킽��f^n(t)�S�̂�
// ���vO(size log n)�̌v�Z�ʂŋ��߂�B
template <typename F>
class Doubling :
  public Doubling_Body<int,F>
{

public:
  inline Doubling( F f , const int& size , const int& digit = 64 );
  
private:
  inline int e( const int& i );
  inline int e_inv( const int& t );

};

// �v�f��size�̂���W��S���v��
// (1) S�̔C�ӂ̗v�fi�ɑ΂�f(i)��S�̗v�f�ł���B
// (2) f�̓f�t�H���g�����ɂ��Ăяo���\�i���_�⏕�ɗp����j
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// ���̂悤��S�̊e�v�ft��n < 2^digit�𖞂����e�񕉐���n���킽��f^n(t)�S�̂�
// ���vO(size log size log n)�̌v�Z�ʂŋ��߂�B
template <typename T, typename F>
class MemorisationDoubling :
  public Doubling_Body<T,F>
{

private:
  int m_length;
  Map<T,int> m_memory;
  vector<T> m_memory_inv;
  
public:
  inline MemorisationDoubling( F f , const int& size , const int& digit = 64 );
  
private:
  inline T e( const int& i );
  inline int e_inv( const T& t );
  
};
template <typename F,typename... Args> MemorisationDoubling(F,Args...) -> MemorisationDoubling<decltype(declval<F>()()),F>;

// �v�f��size�̂���W��S���v��
// (1) S�̔C�ӂ̗v�fi�ɑ΂�f(i)��S�̗v�f�ł���B
// (2) f�̓f�t�H���g�����ɂ��Ăяo���\�i���_�⏕�ɗp����j
// (3) (enum_T,enum_T_inv)��S��size�����̔񕉐����S�̂̏W���̊Ԃ̑S�P�˂�^����B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// ���̂悤��S�̊e�v�ft��n < 2^digit�𖞂����e�񕉐���n���킽��f^n(t)�S�̂�
// ���vO(size log n)�̌v�Z�ʂŋ��߂�B
template <typename T , typename Enum_T , typename Enum_T_inv , typename F>
class EnumerationDoubling :
  public Doubling_Body<T,F>
{

private:
  Enum_T m_enum_T;
  Enum_T_inv m_enum_T_inv;

public:
  inline EnumerationDoubling( Enum_T enum_T , Enum_T_inv enum_T_inv , F f , const int& size , const int& digit = 64 );
  
private:
  inline T e( const int& i );
  inline int e_inv( const T& t );

};
template <typename Enum_T,typename Enum_T_inv,typename F,typename...Args> EnumerationDoubling(Enum_T,Enum_T_inv,F,Args...) -> EnumerationDoubling<decltype(declval<F>()()),Enum_T,Enum_T_inv,F>;
