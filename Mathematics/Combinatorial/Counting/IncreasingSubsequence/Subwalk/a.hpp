// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Counting/IncreasingSubsequence/Subwalk/a.hpp

#pragma once
#include "a_macro.hpp"

// O(|E_inv| log V)��a�̘A���Ƃ͌���Ȃ���󕔕���ł����ĔC�ӂ̗אڂQ������E_inv�̒�߂�L���ӂ�
// �t�����̗L���ӂŌ��΂����̂𐔂��グ��B
template <typename T , list<T> E_inv(const T&) , int V_max> ll CountSubwalk( const T ( &a )[V_max] , const int& V );
template <typename T , list<T> E_inv(const T&) , int V_max> ll CountSubwalk( const T ( &a )[V_max] , const int& V , const ll& mod );


// O((V + |E_inv|) log V)��a�̘A���Ƃ͌���Ȃ���󕔕���ł����ĔC�ӂ̗אڂQ������E_inv�̒�߂�L���ӂ�
// �t�����̗L���ӂŌ��΂����̂̒����̍ő�l��Ԃ��B
template <typename T , list<T> E_inv(const T&) , int V_max> int LongestSubwalk( const T ( &a )[V_max] , const int& V );

