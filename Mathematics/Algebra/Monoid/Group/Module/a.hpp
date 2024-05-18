// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Group/Module/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/961725�iRegularRSet�j
// https://yukicoder.me/submissions/961537�iAbstractRSet�j
// https://yukicoder.me/submissions/950182�iModule�j

template <typename R , typename U>
class VirtualRSet :
  virtual public UnderlyingSet<U>
{

public:
  virtual U Action( const R& r , U u ) = 0;
  inline U Power( U u , const R& r );
  inline U ScalarProduct( const R& r , U u );

};

template <typename U , typename MAGMA>
class RegularRSet :
  virtual public VirtualRSet<U,U> ,
  public MAGMA
{

public:
  inline RegularRSet( MAGMA magma );
  inline U Action( const U& r , U u );

};
template <typename MAGMA> RegularRSet( MAGMA magma ) -> RegularRSet<inner_t<MAGMA>,MAGMA>;


template <typename R , typename U , typename O_U>
class AbstractRSet :
  virtual public VirtualRSet<R,U>
{

private:
  O_U m_o_U;
  
public:
  // �^���_�̂��߂ɗ]�v�Ȉ���dummy0,dummy1���K�v
  inline AbstractRSet( const R& dummy0 , const U& dummy1 , O_U o_U );
  inline AbstractRSet<R,U,O_U>& operator=( const AbstractRSet<R,U,O_U>& ) noexcept;
  inline U Action( const R& r , U u );

};

template <typename R , typename U , typename O_U , typename GROUP>
class AbstractModule :
  public AbstractRSet<R,U,O_U> ,
  public GROUP
{

public:
  // �^���_�̂��߂ɗ]�v�Ȉ���dummy���K�v
  inline AbstractModule( const R& dummy , O_U o_U , GROUP M );

};
template <typename R , typename O_U , typename GROUP> AbstractModule( const R& dummy , O_U o_U , GROUP M ) -> AbstractModule<R,inner_t<GROUP>,O_U,GROUP>;

template <typename R , typename U>
class Module :
  virtual public VirtualRSet<R,U> ,
  public AdditiveGroup<U>
{

public:
  inline U Action( const R& r , U u );
  
};
