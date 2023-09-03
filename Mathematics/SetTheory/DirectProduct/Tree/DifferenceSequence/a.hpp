// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/Tree/DifferenceSequence/a.hpp

#pragma once

// ����ɑ΂���imos�@
// https://imoz.jp/algorithms/imos_method.html
// ��XV��̃��m�C�hT�l�֐���㰓����Z���W��U����̏����^Action�̑g(T,U,Action)
// �Ɉ�ʉ������f�[�^�\���B
template <typename V , typename T , typename U , int size_max>
class DifferenceSequenceBody
{

protected:
  int m_size;
  U m_a[size_max];
  U m_lazy_addition[size_max];
  bool m_updated;

public:
  inline DifferenceSequenceBody( const int& size );

  // ��p�̒x���]�����������Ă���l��������B
  inline void Set( const V& v , const U& u );
  // ��p�̒x���]�����������Ă���l���Q�Ƃ���B
  inline const U& Get( const V& v );
  // ��p�̒x���]�������������Ɍ��X�̒l���Q�Ƃ���B
  inline U& Ref( const V& v );

  // v�ł̒l��u��x���]�������ɉ��Z����B
  inline void Add( const V& v , const U& u );

  // �v��
  // (1) v_start����v_final�̊e�v�f�ւ̗L���p�X�����݂���B
  // (2) v_final�̗v�f�Ԃ̗L���p�X�����݂��Ȃ��B
  // �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
  // ����
  // (1) v_start����v�ւ̗L���p�X�����݂���B
  // (2) v_final�̂�����̗v�f�����v�ւ̗L���p�X�����݂��Ȃ��B
  // �𖞂���V�̊e�v�fv�ɑ΂��Av�ł̒l��u��x���]���ŉ��Z����B
  void SubTreeAdd( const V& v_start , const list<V>& v_final , const U& u );

  inline DifferenceSequenceBody<V,T,U,size_max>& operator+=( const DifferenceSequenceBody<V,T,U,size_max>& a );

  // ��p�̒x���]������������B
  void Update();

private:
  virtual list<V> Edge( const V& v ) const = 0;
  virtual V Edge_inv( const V& v ) const = 0;
  virtual V e( const int& i ) const = 0;
  virtual int e_inv( const V& v ) const = 0;
  virtual const T& Unit() const = 0;
  virtual T& Addition( const T& t0 , T& t1 ) const = 0;
  virtual U Inverse( const U& u ) const = 0;
  virtual T& Action( const U& u , T& t ) const = 0;

};


// �ʏ�̔z���̊K������B

// ���͈͓͂̔��ŗv��
// (6) (T,operator+:T^2->T,T(),operator-:T->T)�͉��Q�ł���B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B

// 0�ɂ�鏉����O(size_max)
// �z��ɂ�鏉����O(size_max)

// ��_���O(size)�i��p�̒x���]������������B���X��p�̒x���]�����Ȃ��ꍇ��O(1)�j
// ��_�擾O(size)�i��p�̒x���]������������B���X��p�̒x���]�����Ȃ��ꍇ��O(1)�j

// ��_���ZO(1)�i��p��x���]�����Ȃ��j
// �n�ؕЉ��ZO(1)�i��p��x���]������j
// �I�ؕЉ��ZO(1)�i��p��x���]������j
// ��ԉ��ZO(1)�i��p��x���]������j
// ���@O(size)�i��p�̒x���]������������j
template <typename T , int size_max>
class DifferenceSequence :
  public DifferenceSequenceBody<int,T,T,size_max>
{

public:
  inline DifferenceSequence( const int& size );
  inline DifferenceSequence( const T ( &a )[size_max] , const int& size );
  inline DifferenceSequence( T ( &&a )[size_max] , const int& size );

  inline void InitialSegmentAdd( const int& v_start , const T& u );
  inline void FinalSegmentAdd( const int& v_final , const T& u );
  inline void IntervalAdd( const int& v_start , const int& v_final , const T& u );
  inline void IntervalSubtract( const int& v_start , const int& v_final , const T& u );

private:
  inline list<int> Edge( const int& v ) const;
  inline int Edge_inv( const int& v ) const;
  inline int e( const int& i ) const;
  inline int e_inv( const int& v ) const;
  inline const T& Unit() const;
  inline T& Addition( const T& t0 , T& t1 ) const;
  inline T Inverse( const T& u ) const;
  inline T& Action( const T& u , T& t ) const;

};


// �X��̊K������B

// ���͈͓͂̔��ŗv��
// (1) �O���t(V,E)�͗L���O���t�Ƃ��Ċe�A�������������؂ł���B
// (2) (V,E)�̊e��v0->v1�ɑ΂�v0 = E_inv(v1)�����藧�B
// (3) (V,E)�̊e�A�������̍�v�ɑ΂�E_inv(v) = v�����藧�B
// (4) (enum_V:N->V,enum_V_inv:V->N)�݂͌��ɋt�ʑ��ł���B
// (5) (V,E)�̊e��v0->v1�ɑ΂�e_inv(v0) < e_inv(v1)�����藧�B
// (6) (T,m_T:T^2->T,e_T:1->T)�͉����m�C�h�ł���B
// (7) (U,inv_U:U->U)��㰓����Z���W���ł���B
// (8) o_U:U�~T->T��(U,inv_U)����(T,m_T,e_T)�̉t���S�̂̌Q�ւ̏����^��m_T�̍����ł���B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B�i�Ⴆ��T�����Q��U=T��o_U��������T�̉��Z�j

// e_T()�ɂ�鏉����O(size_max)

// ��_���O(size)�i��p�̒x���]������������B���X��p�̒x���]�����Ȃ��ꍇ��O(1)�j
// ��_�擾O(size)�i��p�̒x���]������������B���X��p�̒x���]�����Ȃ��ꍇ��O(1)�j

// ��_���ZO(1)�i��p��x���]�����Ȃ��j
// �����؉��ZO(1+t_final�̃T�C�Y)�i��p��x���]������j
// ���@O(size)�i��p�̒x���]������������j
template <typename V , list<V> E(const V&) , V E_inv(const V&) , V enum_V(const int&) , int enum_V_inv(const V&) , typename T , T& m_T(const T&,T&) , const T& e_T() , typename U , U inv_U(const U&) , T& o_U(const U&,T&) , int size_max>
class EnumerationDifferenceSequence :
  public DifferenceSequenceBody<V,T,U,size_max>
{

public:
  inline EnumerationDifferenceSequence( const int& size );
  
private:
  inline list<V> Edge( const V& v ) const;
  inline V Edge_inv( const V& v ) const;
  inline V e( const int& i ) const;
  inline int e_inv( const V& v ) const;
  inline const T& Unit() const;
  inline T& Addition( const T& t0 , T& t1 ) const;
  inline U Inverse( const U& u ) const;
  inline T& Action( const U& u , T& t ) const;

};
