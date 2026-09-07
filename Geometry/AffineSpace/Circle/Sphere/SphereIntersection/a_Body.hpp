// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Circle/Sphere/SphereIntersection/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../SphereCap/a_Body.hpp"
#include "../../../Polytope/Triangle/Perpendicular/a_Body.hpp"

template <typename DOUBLE>
double SphereIntersectionVolume( const DOUBLE& R0 , const DOUBLE& R1 , const DOUBLE& R2 )
{

  if( R2 >= R0 + R1 ){

    return 0;
    
  }
  
  if( R1 >= R2 + R0 ){

    return SphereVolume( R0 );

  }
  
  if( R0 >= R1 + R2 ){

    return SphereVolume( R1 );
    
  }

  auto [r0,r1,r2] = PerpendicularPartition( R0 , R1 , R2 );
  auto [V00,V01] = SphereCapVolumeHeight( R0 , R0 - ( R2 - r2 ) );
  auto [V10,V11] = SphereCapVolumeHeight( R1 , R1 - r2 );
  return V00 + V10;

}

