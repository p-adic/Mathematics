// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/CRT/a.hpp

#pragma once

// b_0��b_1��

// gcd(b_0,b_1)��Ԃ��Au_0,u_1��u_0*b_0+u_1*b_1==gcd(b_0,b_1)�𖞂����l���i�[����B
template <typename INT>
INT PartitionOfUnity( const INT& b_0 , const INT& b_1 , INT& u_0 ,  INT& u_1 );

// (x-c_0)%b_0==0����(x-c_1)%b_1==0�𖞂����񕉐���x�����݂���΂��̂悤��x��Ԃ��A
// ���݂��Ȃ��Ȃ��-1��Ԃ��B
template <typename INT>
INT ChineseRemainderTheorem( const INT& b_0 , const INT& c_0 , const INT& b_1 , const INT& c_1 );
