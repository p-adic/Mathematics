// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Circle/TangentLine/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1134016 (FromPointToCircle,FromCircleToCircle)

// ’†ScentreA”¼Œaradius‚Ì‰~‚ÆÚ‚·‚éApoint‚ğ’Ê‚é’¼ü‚Ì•û’ö®ax+by+c=0‚ÌŒW”{a,b,c}‚ğ‚Q‚Â•Ô‚·B
template <typename PAIR> vector<T3<double>> TangentLineFromPointToCircle( const PAIR& point , const PAIR& centre , const double& radius );

// 2‰~‚ÌÚü‚Ì•û’ö®ax+by+c=0‚ÌŒW”{a,b,c}‚ğ‚S‚Â•Ô‚·B
template <typename PAIR> vector<T3<double>> TangentLineFromCircleToCircle( const PAIR& centre0 , const double& radius0 , const PAIR& centre1 , const double& radius1 );

