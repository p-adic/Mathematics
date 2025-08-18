// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/RootingDP/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1113759 (RecursionRootingDP)
// https://yukicoder.me/submissions/1113760 (BinaryRootingDP)

// 再帰による木DPの軽量化。
// 型推論のためにfはデフォルト引数で呼び出し可能である必要がある。
template <typename TREE , typename F> inline ret_t<F> RecursionRootingDP( TREE& T , F& f , const int& root );

// dp[i] = val( i )にprodで右からiの子ノードjをわたるdp[jをord(i,j)順で掛けた値
// を計算する木DPの再帰による軽量化。
// ord( i , j )はT.Edge( i )におけるjの格納順。
template <typename TREE , typename VAL , typename RIGHT_ACTION> inline ret_t<VAL,int> BinaryRootingDP( TREE& T , VAL& val , RIGHT_ACTION& prod , const int& root );
