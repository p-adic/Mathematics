// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Polytope/Triangle/Angle/a.hpp

#pragma once

// •Ó’·‚Ì‚Qæ‚ªl02,l12,l22‚ÌOŠpŒ`‚ÌAŠe•Ó‚Ì‘ÎŠp‚ª‰sŠp‚©”Û‚©‚ğ•Ô‚·Bi1:‰sŠp,0:’¼Šp,-1:“İŠpj
template <typename INT> inline T3<int> AccuteAngle2( const INT& l02 , const INT& l12 , const INT& l22 );
// •Ó’·‚ªl0,l1,l2‚ÌOŠpŒ`‚ÌAŠe•Ó‚Ì‘ÎŠp‚ª‰sŠp‚©”Û‚©‚ğ•Ô‚·Bi1:‰sŠp,0:’¼Šp,-1:“İŠpj
inline T3<int> AccuteAngle( const double& l0 , const double& l1 , const double& l2 );
// ‚R’¸“_‚ªv0,v1,v2‚ÌOŠpŒ`‚ÌAŠe’¸“_‚ÌŠp‚ª‰sŠp‚©”Û‚©‚ğ•Ô‚·Bi1:‰sŠp,0:’¼Šp,-1:“İŠpj
template <template <typename...> typename PAIR , typename INT> inline T3<int> AccuteAngle( const PAIR<INT,INT>& v0 , const PAIR<INT,INT>& v1 , const PAIR<INT,INT>& v2 );

