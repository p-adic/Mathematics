// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/PlainCoordinate/PlainSort/Order/a.hpp

#pragma once

template <typename INT>
class ArgumentSortOrder
{

private:
  INT m_x;
  INT m_y;

public:
  inline ArgumentSortOrder( INT x , INT y );
  // (x,y)‚ğ‹«ŠE‚ÉŠÜ‚Ş‰½‚ç‚©‚Ì”¼•½–Ê‚É‘®‚·“_‚ğ(x,y)’†S‚Ì{•ÎŠp,‹——£}‚Å”äŠr‚·‚éB
  template <typename PAIR> bool operator()( const PAIR& v0 , const PAIR& v1 ) const;
  
};

