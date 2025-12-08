// c:/Users/user/Documents/Programming/Utility/String/Palindrome/a.hpp

#pragma once

// reversed=falseの時はS[0,r]（0<=r<N）が回文か否かをanswer[r]に、
// reversed=trueの時はS[l,N-1]（0<=l<N）が回文か否かをanswer[l]に
// O(N)で格納。（確率的判定）
template <typename STR> vector<bool> Palindrome( const STR& S , const bool& reversed = false );
