// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/AdicExpansion/DynamicBitSet/a_Macro.hpp

#pragma once

#define DECLARATION_OF_OPR_FOR_BITSET( OPR )                            \
  inline DynamicBitSet& operator OPR ## =( const DynamicBitSet& S ); \
  inline DynamicBitSet operator OPR( DynamicBitSet S ) const; \
  
#define DEFINITION_OF_OPR_FOR_BITSET( OPR )                             \
  inline DynamicBitSet& DynamicBitSet::operator OPR ## =( const DynamicBitSet& S ) { assert( m_size == S.m_size ); for( int d = 0 ; d < m_d ; d++ ){ m_S[d] OPR ## = S.m_S[d]; } return *this; } \
  inline DynamicBitSet DynamicBitSet::operator OPR( DynamicBitSet S ) const { return move( S OPR ## = *this ); } \
  
