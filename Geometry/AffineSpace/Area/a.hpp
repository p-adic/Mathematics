// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Area/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/1066871 (凸多角形)
// https://yukicoder.me/submissions/1087031 (ヘロンの公式)

// xy平面内の３点がなす三角形の符号つき面積の2倍(平行四辺形の符号つき面積)
template <typename INT> inline INT Area( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 , const INT& x2 , const INT& y2 );
template <typename RET , typename INT , template <typename...> typename PAIR> inline RET Area( const PAIR<INT,INT>& v0 , const PAIR<INT,INT>& v1 , const PAIR<INT,INT>& v2 );

// xy平面内の３点がなす三角形の符号なし面積を辺長からヘロンの公式で求める。
inline double Area( const double& l0 , const double& l1 , const double& l2 );

// xy平面内の凸多角形の符号つき面積の２倍（反時計回りが正方向）
template <typename RET , typename INT , template <typename...> typename PAIR> inline RET Area( const vector<PAIR<INT,INT>>& v );
