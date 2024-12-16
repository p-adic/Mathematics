// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/WalshHadamardTransform/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/1031817 (InverseWalshHadamardTransform,AbstractTwistedWalshHadamardTransform)

// �ȉ�f.size()��size�ƒu���B

// f[i]��{a_i,b_i,c_i}�ƒu���A�Q��T[Z/order Z]�ɂ�����sum_{j in [0,order)} 1[j]��tr�ƒu���A
// prod_{i<size} (a_i * tr + b_i * [c_i])��O(size)�ŋ��߂�B
template <typename T , typename INT> tuple<T,T,INT> AffineTraceProduct( const vector<tuple<T,T,INT>>& f , const INT& order );

// f[i]��{a_i,b_i,c_i}�ƒu���A
// (prod_{i<size}(2^digit*a_i+(-1)^{popcount(c_i&j)}b_i))_{j<2^digit}
// ��O(size+2^digit)�ŋ��߂�B
template <typename T> vector<T> AffineShiftProduct( const vector<tuple<T,T,int>>& f , const int digit );

// size <= 2^digit�Ƃ���Bf��Walsh-Hadamard�ϊ�
// (sum_{i<size} (-1)^{popcount(i&j)} f[i])_{j<2^digit}
// ��O(digit 2^{digit})�Ōv�Z����B
template <typename T> vector<T> WalshHadamardTransform( vector<T> f , const int& digit );
template <typename T> vector<T> InverseWalshHadamardTransform( vector<T> f , const int& digit );

// size <= 2^digit�Ƃ��Af[i]��(a_i,b_i)�ƒu���Bf�̏�@�IWalsh-Hadamard�ϊ�
// ((prod_{i<size}(popcount(i&j)&1==b?a[i]:b[i]))_{b<2)_{j<2^digit}
// ��O(digit 2^{digit})�Ōv�Z����B
template <typename COMM_SEMIGRP , typename T> vector<pair<T,T>> AbstractWalshHadamardTransform( COMM_SEMIGRP M , vector<pair<T,T>> f , const int& digit );

// f[i]��{a_i,b_i,c_i}�ƒu���A0<=c_i<2^digit�Ƃ��A
// ((prod_{i<size}(popcount(c_i&j)&1==b?a[i]:b[i]))_{b<2)_{j<2^digit}
// ��O(size+digit 2^{digit})�Ōv�Z����B
template <typename COMM_SEMIGRP , typename T> vector<pair<T,T>> AbstractTwistedWalshHadamardTransform( COMM_SEMIGRP M , vector<tuple<T,T,int>> f , const int& digit );
