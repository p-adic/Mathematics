// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/ZetaTransfom/a.hpp

#pragma once
#include "a_Macro.hpp"

template <typename T , typename U , int size_max>
class ZetaTransformBody
{

private:
  int m_length;
  map<T,int> m_memory;
  vector<T> m_memory_inv;

protected:
  int m_size;
  U m_val[size_max];

public:
  // ���z�p���p�Ƀ_�~�[�̃f�t�H���g�R���X�g���N�^��ݒ�B
  inline ZetaTransformBody( const int& size = 0 );

  inline void Add( const T& t , const U& u );
  inline void AddAll( const U& u );
  inline ZetaTransformBody<T,U,size_max>& operator+=( const ZetaTransformBody<T,U,size_max>& a );
  inline void MultiplyAll( const U& u );
  inline ZetaTransformBody<T,U,size_max>& operator*=( const ZetaTransformBody<T,U,size_max>& a );

  // �q�N���X�̔������̃��r�E�X�֐��̃f�t�H���g�̍ċA�����g�����߁A
  // �ċA�[�x���󂢏ꍇ�ɂ����g���Ȃ��B
  inline U Get( const T& t );
  // mu�͎q�N���X�̔������̃��r�E�X�֐��B
  template <int mu(const T&,const T&)> inline U Get( const T& t );
  inline const U& InitialSegmentSum( const T& t );

  // f_inv_max�͒�`���r(s)���܂ޕ����ʑ�T->S�ł���A�v��
  // (1) S�͔������W���ł���B
  // (2) r(s)�͏d���������Ȃ��B�i����ďW���Ƃ݂Ȃ��j
  // (3) s��r(s)�̍ő匳�ł���B
  // (4) ��f_inv_max(s)�̗v�f����E�Ɏ���T�̗v�f�S��R�ւ�f�̐���f_R�͏����ۑ��ʑ�R->r(s)�ł���B
  // (5) r(s)�̔C�ӂ̗v�ft�ɑ΂�f_inv_max(t)���t��f_R^{-1}(t)�̍ő匳�ł���B
  // �𖞂���f�����݂���ꍇ�ɂ݈̂ȉ��̂Q���T�|�[�g�B

  // f( t ) = s�𖞂���R�̗v�ft�S�̂�n�鑍�a�擾�B
  template <typename S , T f_inv_max(const S&) , list<S> r(const S&)> inline U InverseImageSum( const S& s );
  template <typename S , T f_inv_max(const S&) , list<S> r(const S&) , int mu(const T&,const T&)> inline U InverseImageSum( const S& s );
  // f( t ) <= s�𖞂���R�̗v�ft�S�̂�n�鑍�a�擾�B�i���ʓI��r�͎g��Ȃ����v�����r�̑��݂��K�v�j 
  template <typename S , T f_inv_max(const S&)> inline const U& IntervalInverseImageSum( const S& s );

  virtual T e( const int& i );
  virtual int e_inv( const T& t );
  
private:
  virtual const U& Zero() const = 0;
  virtual U Sum( const U& u0 , const U& u1 ) const = 0;
  virtual U Prod( const U& u0 , const U& u1 ) const = 0;
  virtual list<T> Sub( const T& t ) const = 0;
  virtual list<T> Sup( const T& t ) const = 0;
  virtual int Moevius( const T& t0 , const T& t1 ) = 0;

};

template <typename T , typename U , U a_U(const U&,const U&) , const U& z_U() , U m_U(const U&,const U&) , int size_max>
class SemiRingForZetaTransform :
  virtual public ZetaTransformBody<T,U,size_max>
{
public:
  inline SemiRingForZetaTransform( const int& dummy );
  
private:
  inline const U& Zero() const;
  inline U Sum( const U& u0 , const U& u1 ) const;
  inline U Prod( const U& u0 , const U& u1 ) const;

};

template <typename T , list<T> E(const T&) , list<T> E_inv(const T&) , typename U , int size_max>
class PartiallyOrderedSetForZetaTransform :
  virtual public ZetaTransformBody<T,U,size_max>
{

private:
  map<int,map<int,int> > m_moevius;

  inline list<T> Sub( const T& t ) const;
  inline list<T> Sup( const T& t ) const;
  // �f�t�H���g�̍ċA���ł��邽�߁A�ċA�[�x���󂢏ꍇ�ɂ����g���Ȃ��B
  inline int Moevius( const T& t0 , const T& t1 );
  
};

template <typename U , int size_max>
class EnumerationForZetaTransform :
  virtual public ZetaTransformBody<int,U,size_max>
{

private:
  inline int e( const int& i );
  inline int e_inv( const int& t );
  
};

// ���͈͓͂̔��ŗv��
// (1) E��int��̔�����<�̃O���t��E_inv��(int,>)�̃O���t�ł���B
// �𖞂����ꍇ�ɂ݈̂ȉ����T�|�[�g�B

// 0�ɂ�鏉����O(size_max)
// �[�[�^�ϊ��O�̔z��ɂ�鏉����O(�n�ؕЂ̃T�C�Y�̑��a)

// ��_���ZO(�I�ؕ�[t,��)�̃T�C�Y)
// �S�̉��ZO(size)
// �e�_���@O(size)
// �S�̏�ZO(size)
// (int,<)��join�����ł���ꍇ�̏�ݍ��ݏ�@O(size)

// ��_�擾O(�n�ؕ�(-��,t]�̃T�C�Y�~���r�E�X�֐��̌v�Z��)
// ��Ԙa�擾O(1)

// �t���a�擾O(�n�ؕ�(-��,f_inv_max(r_max)]�̃T�C�Y�~���r�E�X�֐��̌v�Z��)
// ��ԋt���a�擾O(1)
template <list<int> E(const int&) , list<int> E_inv(const int&) , int size_max>
class ZetaTransform :
  public PartiallyOrderedSetForZetaTransform<int,E,E_inv,ll,size_max> ,
  public EnumerationForZetaTransform<ll,size_max>
{

public:
  inline ZetaTransform( const int& size );
  inline ZetaTransform( const int& size , const ll ( &a )[size_max] );

private:
  inline const ll& Zero() const;
  inline ll Sum( const ll& u0 , const ll& u1 ) const;
  inline ll Prod( const ll& u0 , const ll& u1 ) const;

};

// ���͈͓͂̔��ŗv��
// (1) 2^digit <= size_max
// (2) (U,a_U:U^2->U,z_U:1->U,m_U:U^2->U)���P�ʓI�ł���B
// �𖞂����ꍇ�ɂ݈̂ȉ����T�|�[�g�B

// z_U()�ɂ�鏉����O(size_max)
// �[�[�^�ϊ��O�̔z��ɂ�鏉����O(digit 2^digit)�i�����@���m�C�h�����g���j

// ��_���ZO(2^digit)�i�����@���m�C�h�����g���j
// �S�̉��ZO(2^digit)�i�����@���m�C�h�������ł������ł��邪�P�ʓI�������g���j
// �e�_���@O(2^digit)�i���@���m�C�h�����g���j
// �S�̏�ZO(2^digit)�i�������g���j
// ��ݍ��ݏ�@O(2^digit)�i�������g���j

// ��_�擾O(2^digit)�i�P�ʓI�����g���B�𒼂Ɠ����I�[�_�[�j
// ���_�擾O(digit 2^digit)�i�P�ʓI�����g���j
// ��Ԙa�擾O(1)�i�����@���m�C�h�����g���j
// �t���a�擾O(�n�ؕ�(-��,f_inv_max(r_max)]�̃T�C�Y)�i�P�ʓI�����g���j
// ��ԋt���a�擾O(1)�i�����@���m�C�h�����g���j
template <typename U , U a_U(const U&,const U&) , const U& z_U() , U m_U(const U&,const U&) , int size_max>
class FastZetaTransform :
  public SemiRingForZetaTransform<int,U,a_U,z_U,m_U,size_max> ,
  public EnumerationForZetaTransform<U,size_max>
{

private:
  int m_digit;
  
public:
  inline FastZetaTransform( const int& digit );
  inline FastZetaTransform( const int& digit , const U ( &a )[size_max] );

  inline FastZetaTransform<U,a_U,z_U,m_U,size_max>& operator+=( const FastZetaTransform<U,a_U,z_U,m_U,size_max>& a );
  inline FastZetaTransform<U,a_U,z_U,m_U,size_max>& operator*=( const FastZetaTransform<U,a_U,z_U,m_U,size_max>& a );

  inline void FastMoeviusTransform( U ( &a )[size_max] );

private:
  inline list<int> Sub( const int& t ) const;
  inline list<int> Sup( const int& t ) const;
  inline int Moevius( const int& t0 , const int& t1 );

};

// ���͈͓͂̔��ŗv��
// (1) E��T��̔�����<�̃O���t��E_inv��(T,>)�̃O���t�ł���B
// (2) (U,a_U:U^2->U,z_U:1->U,m_U:U^2->U)���P�ʓI�ł���B
// �𖞂����ꍇ�ɂ݈̂ȉ����T�|�[�g�B

// z_U()�ɂ�鏉����O(size_max)

// ��_���ZO(�I�ؕ�[t,��)�̃T�C�Y�~log_2(size))�i�����@���m�C�h�����g���j
// �S�̉��ZO(size)�i�����@���m�C�h�������ł������ł��邪�P�ʓI�������g���j
// �e�_���@O(size)�i���@���m�C�h�����g���j
// �S�̏�ZO(size)�i�������g���j
// (T,<)��join�����ł���ꍇ�̏�ݍ��ݏ�@O(size)�i�������g���j

// ��_�擾O(�n�ؕ�(-��,t]�̃T�C�Y�~���r�E�X�֐��̌v�Z�ʁ~log_2(size))�i�P�ʓI�����g���j
// ��Ԙa�擾O(log_2(size))�i�����@���m�C�h�����g���j

// �t���a�擾O(�n�ؕ�(-��,f_inv_max(r_max)]�̃T�C�Y�~���r�E�X�֐��̌v�Z�ʁ~log_2(size))�i�P�ʓI�����g���j
// ��ԋt���a�擾O(log_2(size))�i�����@���m�C�h�����g���j
template <typename T , list<T> E(const T&) , list<T> E_inv(const T&) , typename U , U a_U(const U&,const U&) , const U& z_U() , U m_U(const U&,const U&) , int size_max>
class MemorisationZetaTransform :
  public SemiRingForZetaTransform<T,U,a_U,z_U,m_U,size_max> ,
  public PartiallyOrderedSetForZetaTransform<T,E,E_inv,U,size_max>
{

public:
  inline MemorisationZetaTransform( const int& size );

};

// ���͈͓͂̔��ŗv��
// (1) E��T��̔�����<�̃O���t��E_inv��(T,>)�̃O���t�ł���B
// (2) (U,a_U:U^2->U,z_U:1->U,m_U:U^2->U)���P�ʓI�ł���B
// (3) enum_T:int->T��enum_T_inv:int->T���݂��ɋt�ʑ��ł���B
// �𖞂����ꍇ�ɂ݈̂ȉ����T�|�[�g�B

// z_U()�ɂ�鏉����O(size_max)

// ��_���ZO(�I�ؕ�[t,��)�̃T�C�Y)�i�����@���m�C�h�����g���j
// �S�̉��ZO(size)�i�����@���m�C�h�������ł������ł��邪�P�ʓI�������g���j
// �e�_���@O(size)�i���@���m�C�h�����g���j
// �S�̏�ZO(size)�i�������g���j
// (T,<)��join�����ł���ꍇ�̏�ݍ��ݏ�@O(size)�i�������g���j

// ��_�擾O(�n�ؕ�(-��,t]�̃T�C�Y�~���r�E�X�֐��̌v�Z��)�i�P�ʓI�����g���j
// ��Ԙa�擾O(1)�i�����@���m�C�h�����g���j

// �t���a�擾O(�n�ؕ�(-��,f_inv_max(r_max)]�̃T�C�Y�~���r�E�X�֐��̌v�Z��)�i�P�ʓI�����g���j
// ��ԋt���a�擾O(1)�i�����@���m�C�h�����g���j
template <typename T , list<T> E(const T&) , list<T> E_inv(const T&) , typename U , U a_U(const U&,const U&) , const U& z_U() , U m_U(const U&,const U&) , int size_max , T enum_T(const int&) , int enum_T_inv(const T&)>
class EnumerationZetaTransform :
  public SemiRingForZetaTransform<T,U,a_U,z_U,m_U,size_max> ,
  public PartiallyOrderedSetForZetaTransform<T,E,E_inv,U,size_max>
{

public:
  inline EnumerationZetaTransform( const int& size );

private:
  inline T e( const int& i );
  inline int e_inv( const T& t );

};

// �ÓT�I�ȃ��r�E�X�֐���../../Arithmetic/Prime/Divisor/a_Body.hpp�Œ�`

