// c:/Users/user/Documents/Programming/Mathematics/Function/MaxTwoAryHierarchy/BinarySearch/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/995705�i�ꎟ�֐��j
// https://yukicoder.me/submissions/995704�i��������Ƃ̍��̐�Βl�j

// X=INT�ɂ����ē񕪒T�����s�����߁AX�𔽓]�����鎞��Reversed<X>�łȂ�operator-()���g�����ƁB

template <typename U , typename V , typename INT , typename FUNC>
class TwoAryHierarchyBinarySearchIntersection :
  virtual public VirtualTwoAryHierarchyIntersection<U,V,INT>
{

private:
  FUNC* m_p_func;
  const INT* m_p_x_min;
  const INT* m_p_x_max;

public:
  inline TwoAryHierarchyBinarySearchIntersection( FUNC& func , const INT& x_min , const INT& x_max );

protected:
  INT Intersection( const U& u0 , const V& v0 , const U& u1 , const V& v1 );

};

// �\�zO(N log N)
// func(u,v,-)�Ƃ�max�ɂ��S�̍X�VO(log(N + Q))�i�ς��j
// ��_�擾O(log(N + Q))
template <typename U , typename V , typename INT , typename FUNC>
class MaxTwoAryHierarchyBinarySearch :
  public VirtualMaxTwoAryHierarchy<U,V,INT,FUNC> ,
  public TwoAryHierarchyBinarySearchIntersection<U,V,INT,FUNC>
{

public:
  inline MaxTwoAryHierarchyBinarySearch( FUNC func , const INT& x_min , const INT& x_max , const U& dummy1 , const V& dummy2 );

};

template <typename U , typename V , typename INT , typename FUNC>
class MinTwoAryHierarchyBinarySearch :
  public VirtualMinTwoAryHierarchy<U,V,INT,FUNC> ,
  public TwoAryHierarchyBinarySearchIntersection<Reversed<U>,Reversed<V>,INT,ReversedTwoAryHierarchy<U,V,INT,FUNC>>
{

public:
  inline MinTwoAryHierarchyBinarySearch( FUNC func , const INT& x_min , const INT& x_max , const U& dummy1 , const V& dummy2 );
  
};

