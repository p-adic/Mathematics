// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Circle/SphereCap/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Sphere/a_Body.hpp"

inline T2<double> SphereCapVolumeHeight( const double& R , const double& h )
{

  const double V = SphereVolume( R ) , W = min( V , pi / 3 * h * h * ( 3 * R - h ) );
  return { W , V - W };
  
}

inline T2<double> SphereCapVolumeRadius( const double& R , const double& r )
{

  // r‚ªR‚É‹ß‚¢ê‡‚Ì¸“x—‚¿‚ğ–h‚®‚½‚ß‚É·‚Å‚Í‚È‚­¤‚ğæ‚éB
  const double h = r * r / ( R + sqrt( max( R * R - r * r , 0.0 ) ) );
  return SphereCapVolumeHeight( R , h );
  
}

