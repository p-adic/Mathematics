// c:/Users/user/Documents/Programming/Mathematics/Algebra/a.hpp

#pragma once

// - �C���^�t�F�[�X���Ȃ�ׂ����ی^�ŗ^���ĉ��z�p������B
//   - ��̓I�\�����Q��ވȏ゠����̂͂�����񒊏ی^�����z�p������B
//   - VirtualPointedSet�̂悤�ɋ�̓I�\�����P��ނ����Ȃ����̂����z�p���̃R���X�g���N�^�Ăяo����
//     �ȗ����邽�߂ɂȂ�ׂ����ی^��p�ӂ���B
//   - AbstractDijkstra�̂悤�ɑS�Ă̋�̓I�\�����P�̋�̓I�\���̔h���ł���ꍇ��
//     �C���^�t�F�[�X��K�v�Ƃ��Ȃ��B
// - �R���X�g���N�^�͂Ȃ�ׂ��ȗ��ł���悤�ɂ��邪�A�|�C���^�̓����o�ϐ��ɂ��Ȃ��B
//   - VirtualGraph�̂悤�ɋ�̓I�\�����Q��ވȏ゠����̂őS�Ăɋ��ʂ̒�`�{�̂����֐��iEdge�j��
//     �K�v�ȏꍇ�͎������c��オ��Ȃ��悤�ɒ��ی^�Ɋ֐��̒�`�����A���̂��ߒ��ی^�Ƀ����o�ϐ���
//     �K�v�ɂȂ�ꍇ�̓R���X�g���N�^��񎩖��Ȃ��̂ɂ���
//   - ����Ƀ|�C���^�𒊏ی^�̃����o�Ƃ���
//     �h���N���X�̃R���X�g���N�^�̒�`���ŃA�h���X��n���悤�ɂ���ƁA���[�u�ȂǂňӐ}����
//     �|�C���^�̎w���A�h���X���Ӑ}�ʂ�łȂ��Ȃ邱�Ƃɒ��ӂ���B
template <typename U>
class UnderlyingSet
{

public:
  using type = U;

};

template <typename U>
class VirtualPointedSet :
  virtual public UnderlyingSet<U>
{

public:
  virtual const U& Point() const noexcept = 0;
  virtual U& Point() noexcept = 0;
  DECLARATION_OF_CPOINT( Unit );
  DECLARATION_OF_CPOINT( Zero );
  DECLARATION_OF_CPOINT( One );
  DECLARATION_OF_CPOINT( Infty );
  DECLARATION_OF_CPOINT( size );
  DECLARATION_OF_POINT( init );
  DECLARATION_OF_POINT( root );

};

template <typename U>
class PointedSet :
  virtual public VirtualPointedSet<U>
{

private:
U m_b_U;

public:
  inline PointedSet( const U& b_u = U() );
  inline const U& Point() const noexcept;
  inline U& Point() noexcept;

};

template <typename U>
class VirtualNSet
  virtual public UnderlyingSet<U>
{

public:
  virtual U Transfer( const U& u ) = 0;
  inline U Inverse( const U& u );

};

template <typename U , typename F_U>
class AbstractNSet :
  virtual public VirtualNSet<U>
{

private:
  F_U& m_f_U;

public:
  inline AbstractNSet( F_U& f_U );
  inline U Transfer( const U& u );

};

template <typename U>
class VirtualMagma
  virtual public UnderlyingSet<U>
{

public:
  virtual U Product( const U& u0 , const U& u1 ) = 0;
  inline U Sum( const U& u0 , const U& u1 );

};

template <typename U = ll>
class AdditiveMagma :
  virtual public VirtualMagma<U>
{

public:
  inline U Product( const U& u0 , const U& u1 );

};

template <typename U = ll>
class MultiplicativeMagma :
  virtual public VirtualMagma<U> ,
{

public:
  inline U Product( const U& u0 , const U& u1 );

};

template <typename U , typename M_U>
class AbstractMagma :
  virtual public VirtualMagma<U>
{

private:
  M_U& m_m_U;

public:
  inline AbstractMagma( M_U& m_U );
  inline U Product( const U& u0 , const U& u1 );

};
