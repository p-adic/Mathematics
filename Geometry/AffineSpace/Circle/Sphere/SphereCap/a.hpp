// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Circle/SphereCap/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1184874 (SphereCapVolumeHight)

#include "../../../../Tuple/Wrap/a.hpp"

// ”¼ŒaR‚Ì‹…‚ğA’f–Ê‚ª’¼Œa‚ğh:2R-h‚É•ªŠ„‚·‚é‚æ‚¤‚È•½–Ê‚ÅØ‚èo‚µ‚½‚Ì‚Q‚Â‚Ì—§‘Ì‚Ì‘ÌÏ‚ğ
// {h‘¤,2R-h‘¤}‚ÌŒ`®‚Å•Ô‚·B
inline T2<double> SphereCapVolumeHight( const double& R , const double& h );

// ”¼ŒaR‚Ì‹…‚ğA’f–Ê‚ª”¼Œar‚Ì‰~‚Å‚ ‚é‚æ‚¤‚È•½–Ê‚ÅØ‚èo‚µ‚½‚Ì‚Q‚Â‚Ì—§‘Ì‚Ì‘ÌÏ‚ğ
// {¬‚³‚¢•û,‘å‚«‚¢•û}‚ÌŒ`®‚Å•Ô‚·B
inline T2<double> SphereCapVolumeRadius( const double& R , const double& r );
