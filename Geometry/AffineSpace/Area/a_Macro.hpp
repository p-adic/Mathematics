// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/a_Macro.hpp

#pragma once
#define DEFINITION_OF_AREA ( x1 - x0 ) * ( y2 - y0 ) - ( y1 - y0 ) * ( x2 - x0 )
#define CALL_DEFINITION_OF_AREA Area( get<0>( v0 ) , get<1>( v0 ) , get<0>( v1 ) , get<1>( v1 ) , get<0>( v2 ) , get<1>( v2 ) )

