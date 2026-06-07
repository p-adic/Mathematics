// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Divisor/GCD/InverseImage/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1168553 (InverseImageGCD)

// O(n * (n‚Ì‘fˆö”‚ÌŒÂ”))‚Åanswer[i]‚Égcd(n,i)‚ğŠi”[‚·‚éB
template <typename INT = int> vector<INT> TotalGCD( const int& n );
// O(n * (n‚Ì‘fˆö”‚ÌŒÂ”))‚Åanswer[i]‚Égcd(n,j)=i‚Æ‚È‚éŠe0<=j<=n‚ğ¸‡‚ÉŠi”[‚·‚éB
template <typename T = int> vector<vector<T>> InverseImageGCD( const int& n );
