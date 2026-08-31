See https://github.com/p-adic/p-adic.github.io/blob/master/_posts/projects/programming/0000-00-00-codes.md for licensing.

Only "Utility/Random" is not public. Manually add
- Utility/Random/a.hpp with a declaration of <code>ll GetRand( const ll& Rand_min , const ll& Rand_max )</code>
- Utility/Random/a_Body.hpp with a definition of <code>ll GetRand( const ll& Rand_min , const ll& Rand_max )</code>
to use <code>GetRand(Rand_min,Rand_max)</code> returning a random value in the interval [Rand_min,Rand_max].
