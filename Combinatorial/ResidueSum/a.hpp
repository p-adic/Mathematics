// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/ResidueSum/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/1010485 (ResidueSum)
// https://yukicoder.me/submissions/1010491 (TotalResidueSum)

// RET��MP�Ȃǂł��B
// sum( int j = 1 ; j <= m ; j++ ){ n % j }��O(��n)�ŋ��߂�B
template <typename INT , typename RET> RET ResidueSum( const INT& n , const INT& m );

// (sum( int j = 1 ; j <= m ; j++ ){ i % j })_{i=1}^{n}��O(n log n)�ŋ��߂�B
template <typename INT , typename RET> vector<RET> TotalResidueSum( const INT& n , const INT& m );
