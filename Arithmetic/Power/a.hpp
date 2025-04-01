// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Power/\a.hpp

#pragma once

// base‚Ìã°æ‚ğƒƒ‚‰»‚·‚éB
template <typename INT>
class PowerMemoriser
{

private:
  vector<INT> m_base;
  vector<vector<INT>> m_val;

public:
  template <typename VEC> inline PowerMemoriser( const VEC& base );
  inline INT Get( const int& i , const int& j ) noexcept;

};

// ƒƒ‚‰»‚µ‚È‚¢ŒJ‚è•Ô‚µ“ñæ–@‚Í
// ../IteratedArithmetic/
// ‚ÉÀ‘•B
