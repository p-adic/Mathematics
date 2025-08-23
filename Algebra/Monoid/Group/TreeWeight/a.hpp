// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Group/TreeWeight/a.hpp

#pragma once
#include "../a.hpp"

// ���t���؂�{���_��,������̋����̑��a,2�_�W���Ԃ̋����̑��a�i�d���Ȃ��j}���Ǘ��B
template <typename INT0 , typename INT1 , typename INT2 , typename U = Tuple<INT0,INT1,INT2>>
class TreeWeightGroup :
  virtual public VirtualGroup<U> ,
  public PointedSet<U>
{

  public:
    inline TreeWeightGroup( const INT0& zero0 , const INT1& one1 , const INT2& zero2 );

    // ���̌����ɑΉ����鉉�Z�B
    inline U Product( U u0 , const U& u1 );
    inline U Transfer( const U& u );

    // ���̐e�i�ӂ̏d��w�j��ǉ����鑀��ɑΉ����鉉�Z�B
    inline U Extend( U u , const INT2& w = 1 );
    // ���̐e�i�ӂ̏d��w�j��ǉ����鑀��̋t�ɑΉ����鉉�Z�B
    inline U Cut( U u , const INT2& w = 1 );

};
