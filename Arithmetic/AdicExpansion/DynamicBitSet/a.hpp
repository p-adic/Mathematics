// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/AdicExpansion/DynamicBitSet/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1184934 (Set, Get, |=, <<)

#include "a_Macro.hpp"

class DynamicBitSet
{

private:
  int m_size;
  int m_d;
  // ullÇ≈ä«óùÇµÇ»Ç¢Ç∆>>Ç≈è„à bitÇ…ó]åvÇ»1Ç™ì¸ÇÈÇ±Ç∆Ç…íçà”ÅB
  ull m_mask;
  vector<ull> m_S;

public:
  inline DynamicBitSet( const int& size , const ull& S = 0 );

  inline void Set( const int& i , const bool& b );
  inline bool Get( const int& i ) const;

  DECLARATION_OF_OPR_FOR_BITSET( & );
  DECLARATION_OF_OPR_FOR_BITSET( | );
  DECLARATION_OF_OPR_FOR_BITSET( ^ );
  inline DynamicBitSet& operator<<=( const int& i );
  inline DynamicBitSet& operator>>=( const int& i );

  inline DynamicBitSet operator<<( const int& i ) const;
  inline DynamicBitSet operator>>( const int& i ) const;
  inline DynamicBitSet operator!() const;

  inline int Maximum() const;
  inline int Minimum() const;
  
};
