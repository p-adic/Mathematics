// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Semirng/Ring/Algebra/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../Group/Module/a.hpp"

template <typename R , typename GROUP , typename MONOID , typename U = inner_t<GROUP>>
class VirtualAlgebra :
  virtual public VirtualRSet<R,U> ,
  virtual public VirtualRing<GROUP,MONOID>
{

private:
  inline U Power( U u , const R& r ) = delete;

};  

template <typename R , typename GROUP , typename MONOID , typename O_U , typename U = inner_t<GROUP>>
class AbstractAlgebra :
  virtual public VirtualAlgebra<R,GROUP,MONOID> ,
  public AbstractRing<GROUP,MONOID> ,
  public AbstractRSet<R,U,O_U>
{

private:
  O_U m_o_U;

public:
  // 型推論のために余計な引数dummyが必要
  inline AbstractAlgebra( const R& dummy , GROUP R0 , MONOID R1 , O_U o_U );
  using AbstractRing<GROUP,MONOID>::type;

};

template <typename R , typename U>
class Algebra :
  virtual public VirtualAlgebra<R,AdditiveGroup<U>,MultiplicativeMonoid<U>> ,
  public Ring<U>
{

public:
  // 型推論のために余計な引数dummyが必要
  inline Algebra( const R& dummy , U one );
  using Ring<U>::type;
  
  inline U Action( const R& r , U u );

};
