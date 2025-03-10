// c:/Users/user/Documents/Programming/Utility/String/Z-Algorithm/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/1019141

// 計算量O(N)で各i<Nに対しSの長さi+jの始切片の長さjの終切片がSの長さjの始切片と一致するような
// j<=iの最大値をanswer[i]に格納。
vector<int> LCP( const string& S );
