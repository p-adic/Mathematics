// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/HarmonicMotion/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Utility/Tuple/Wrap/a_Body.hpp"

static ll HarmonicMotionBody( const ll& n , const ll& x , const ll& L , const ll& R )
{

  ll l = 0;
  
  if( L > 0 && R > 0 && -R <= x && x < L ){

    // x + L * l - R * ( n - l ) < L
    // ( L + R ) * l <= L - 1 - ( x - R * n )
    // l <= floor( ( L - 1 - ( x - R * n ) ) / ( L + R ) )
    l = ( L - 1 - ( x - R * n ) ) / ( L + R );

  } else {

    if( x < 0 ){

      if( x + L * n < 0 ){

        l = n;

      } else {

        // x + L * l >= 0
        // L * l >= -x
        // l >= -x / L
        l = ( -x + L - 1 ) / L;
        l += HarmonicMotionBody( n - l , x + L * l , L , R );
        
      }
      
    } else {

      if( x - R * n < 0 ){

        // x - R * r < 0
        // R * r >= x + 1
        // r >= ( x + 1 ) / R
        ll r = ( x + R ) / R;
        l = HarmonicMotionBody( n - r , x - R * r , L , R );
        
      }
      
    }
    
  }
  
  return l;

}

inline T3<ll> HarmonicMotion( const ll& n , const ll& x , const ll& L , const ll& R , const bool& right ) { ll l = right ? HarmonicMotionBody( n , x , L , R ) : n - HarmonicMotionBody( n , -x , -R , -L ); ll r = n - l; return { l , r , x + L * l - R * r }; }

