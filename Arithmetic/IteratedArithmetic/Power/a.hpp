// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/IteratedArithmetic/Power/a.hpp

#pragma once

// base‚Ìã°æ‚ğƒƒ‚‰»‚·‚éB
template <typename INT>
class PowerMemoriser
{

private:
  INT m_base;
  vector<INT> m_val;

public:
  inline PowerMemoriser( const INT& base = 0 );
  inline INT operator[]( const int& exponent ) noexcept;

};

// ƒƒ‚‰»‚µ‚È‚¢ŒJ‚è•Ô‚µ“ñæ–@‚Í
// ../IteratedArithmetic/
// ‚ÉÀ‘•B
