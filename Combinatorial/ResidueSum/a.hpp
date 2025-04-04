// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/ResidueSum/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/1010485 (ResidueSum)
// https://yukicoder.me/submissions/1010491 (TotalResidueSum)

// RETはMPなどでも可。
// sum( int j = 1 ; j <= m ; j++ ){ n % j }をO(√n)で求める。
template <typename INT , typename RET> RET ResidueSum( const INT& n , const INT& m );

// (sum( int j = 1 ; j <= m ; j++ ){ i % j })_{i=1}^{n}をO(n log n)で求める。
template <typename INT , typename RET> vector<RET> TotalResidueSum( const INT& n , const INT& m );
