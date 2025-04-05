// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Group/DirectProduct/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../DirectProduct/a.hpp"

template <typename GROUP0 , typename GROUP1 , typename TYPE> inline DirectProductGroup<GROUP0,GROUP1,TYPE>::DirectProductGroup( GROUP0 G0 , GROUP1 G1 ) : DirectProductMonoid<GROUP0,GROUP1>( move( G0 ) , move( G1 ) ) { static_assert( is_same_v<TYPE,pair<typename GROUP0::type,typename GROUP1::type>> ); }

template <typename GROUP0 , typename GROUP1 , typename TYPE> inline TYPE DirectProductGroup<GROUP0,GROUP1,TYPE>::Transfer( const TYPE& t ) { return { this->m_M0.Transfer( t.first ) , this->m_MG1.Transfer( t.first ) }; }
