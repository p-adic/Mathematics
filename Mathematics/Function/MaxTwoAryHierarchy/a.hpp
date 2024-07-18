// c:/Users/user/Documents/Programming/Mathematics/Function/MaxTwoAryHierarchy/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../../Utility/Reverse/a.hpp"

// verify:
// https://yukicoder.me/submissions/995706�i�ꎟ�֐��j

// ��{�I�ɉ��LURL��Convex Hull Trick�ɏ�����B
// https://rsk0315.hatenablog.com/entry/2022/04/29/141726

template <typename U , typename V , typename X>
class VirtualTwoAryHierarchyIntersection
{

protected:
  virtual X Intersection( const U& u0 , const V& v0 , const U& u1 , const V& v1 ) = 0;
  
};

// FUNC�͊֐�func:U \times V \times X \to Y�ɑ�������^�B
// ���͈͓͂̔��ŗv��
// (1) bool operator<(const U&const U&)�͑S�����ł���B
// (2) bool operator<(const V&const V&)�͑S�����ł���B
// (3) bool operator<(const X&const X&)�͑S�����ł���B
// (4) bool operator<(const Y&const Y&)�͑S�����ł���B
// (5) x_min <= x_max�ł���B
// (6) �C�ӂ�(u0,u1) in U^2��v in V�ɑ΂��Au0 < u1�Ȃ�΂���x0 in X�����݂��āA
//     �C�ӂ�x in [x_min,x_max]�ɑ΂�func(u0,v,x) > func(u1,v,x)��x < x0�͓��l�ł���B
// (7) �C�ӂ�u in U��(v0,v1) in V^2�ɑ΂��Av0 < v1�Ȃ�΂���x0 in X�����݂��āA
//     �C�ӂ�x in [x_min,x_max]�ɑ΂�func(u,v0,x) > func(u,v1,x)��x < x0�͓��l�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �Ⴆ��U=V=X=Y=ll��func(u,v,x) = ux+v�ȂǁB�ȉ�u���X���Av��Y�ؕЂƌĂԁB

// (6),(7)�̕s�����𔽓]������ɂ�Reversed���g���B
// ���������삵�Ȃ�����(6),(7)�̕s�������^�����ƁB

// �S�̍X�V�񐔂�Q�ƒu���B

// func(u,v,-)�ɂ��\�zO(1)
// func(u,v,-)�Ƃ�max�ɂ��S�̍X�VO(log Q)�i�ς��j
// ��_�擾O(log Q)
template <typename U , typename V , typename X , typename FUNC>
class VirtualMaxTwoAryHierarchy :
  virtual public VirtualTwoAryHierarchyIntersection<U,V,X>
{

protected:
  FUNC m_func;
  X m_x_min;
  X m_x_max;
  // m_uvx[�X��u] = { y�ؕ�v , �ő�l������ԍ��[��x���W } �Ƃ��ĊǗ��B
  map<U,pair<V,X> > m_uvx;
  // m_xu[�ő�l������ԍ��[��x���W] = �X��u �Ƃ��ĊǗ��B
  map<X,U> m_xu;

public:
  // vector<U>,vector<V>�ŏ��������s���Ɖ��z�p�����ꂽIntersection���Ăяo���̂�RE�ƂȂ�B
  inline VirtualMaxTwoAryHierarchy( FUNC func , const X& x_min , const X& x_max , const U& dummy1 , const V& dummy2 );

  void SetMax( const U& u , const V& v );
  // {�ő�l,�X��u�i2����ꍇ�͑傫�����j,y�ؕ�v}��Ԃ��B
  // u�̏����������K�v�ȏꍇ��(6),(7)�𖞂����悤��U,V,X�S�Ă�Reversed�ɒu��������B
  tuple<ret_t<FUNC,const U&,const V&,const X&>,U,V> Get( const X& x );

};

template <typename U , typename V , typename X , typename FUNC>
class ReversedTwoAryHierarchy :
  public FUNC
{

public:
  inline ReversedTwoAryHierarchy( FUNC&& func );
  
  inline Reversed<ret_t<FUNC,const U&,const V&,const X&>> operator()( const Reversed<U>& u , const Reversed<V>& v , const X& x );

};

template <typename U , typename V , typename X , typename FUNC>
class VirtualMinTwoAryHierarchy :
  public VirtualMaxTwoAryHierarchy<Reversed<U>,Reversed<V>,X,ReversedTwoAryHierarchy<U,V,X,FUNC>>
{

public:
  inline VirtualMinTwoAryHierarchy( FUNC func , const X& x_min , const X& x_max , const U& dummy1 , const V& dummy2 );

  inline void SetMin( const U& u , const V& v );
  // {�ŏ��l,�X��u�i2����ꍇ�͏��������j,y�ؕ�v}��Ԃ��B
  // u�̑傫�������K�v�ȏꍇ��(6),(7)�𖞂����悤��U,V,X�S�Ă�Reversed�ɒu��������B
  inline tuple<ret_t<FUNC,const U&,const V&,const X&>,U,V> Get( const X& x );

};

template <typename U , typename V , typename X , typename INTERSECTION>
class AbstractTwoAryHierarchyIntersection :
  virtual public VirtualTwoAryHierarchyIntersection<U,V,X>
{

private:
  INTERSECTION m_intersection;

public:
  inline AbstractTwoAryHierarchyIntersection( INTERSECTION intersection );

protected:
  inline X Intersection( const U& u0 , const V& v0 , const U& u1 , const V& v1 );

};

template <typename U , typename V , typename X , typename FUNC , typename INTERSECTION>
class AbstractMaxTwoAryHierarchy :
  public VirtualMaxTwoAryHierarchy<U,V,X,FUNC> ,
  public AbstractTwoAryHierarchyIntersection<U,V,X,INTERSECTION>
{

public:
  inline AbstractMaxTwoAryHierarchy( FUNC func , const X& x_min , const X& x_max , const U& dummy1 , const V& dummy2 , INTERSECTION intersection );

};

template <typename U , typename V , typename X , typename FUNC , typename INTERSECTION>
class AbstractMinTwoAryHierarchy :
  public VirtualMinTwoAryHierarchy<U,V,X,FUNC> ,
  public AbstractTwoAryHierarchyIntersection<U,V,X,INTERSECTION>
{

public:
  inline AbstractMinTwoAryHierarchy( FUNC func , const X& x_min , const X& x_max , const U& dummy1 , const V& dummy2 , INTERSECTION intersection );
  
};

