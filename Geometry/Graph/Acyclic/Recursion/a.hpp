// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Acyclic/Recursion/a.hpp

#pragma once
// verify;
// https://yukicoder.me/submissions/1135067

// EDGE‚ÍDAG‚Ì•Ó‚ð—^‚¦‚éŽÊ‘œedge:T -> T^{< \omega}‚É‘Š“–‚·‚éŒ^B
// F0,G1‚Ívoid f0,g1(const T&)‚É‘Š“–‚·‚éŒ^AF1,G0‚Ívoid f1,g0(const T&,const T&)‚É‘Š“–‚·‚éŒ^B

// [‚³—Dæ’Tõ‚Åƒm[ƒht–K–âŽžAs‚«Š|‚¯‚Éf0(t)‚Æf1(t,Žq)‚ðA•Ô‚èŠ|‚¯‚Ég0(t,Žq)‚Æg1(t)‚ð“K—p‚·‚éB
template <typename EDGE , typename T , typename F0 , typename F1 , typename G0 , typename G1> void RecursionOnDAG( EDGE& edge , const T& t_start , F0 f0 , F1 f1 , G0 g0 , G1 g1 );
