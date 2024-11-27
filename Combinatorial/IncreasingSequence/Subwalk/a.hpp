// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/IncreasingSequence/Subwalk/a.hpp

#pragma once
#include "a_macro.hpp"

// GRAPH�͗L����T->(T \times ...)^{<\omega}�����O���t�ɑ�������^�B
// a[i]���n�_�Ƃ���ӂ̖{���̑��a��E_a�ƒu���B

// O(E_a log size)��a�̘A���Ƃ͌���Ȃ���󕔕���ł����ĔC�ӂ̗אڂQ������E_G�̒�߂�L���ӂ�
// �t�����̗L���ӂŌ��΂����̂𐔂��グ��B
template <typename T , typename GRAPH , typename INT> INT CountSubwalk( GRAPH& G , const vector<T>& a , const INT& dummy );

// O((size + E_a) log size)��a�̘A���Ƃ͌���Ȃ���󕔕���ł����ĔC�ӂ̗אڂQ������
// E_G�̒�߂�L���ӂ̋t�����̗L���ӂŌ��΂����̂̒����̍ő�l��Ԃ��B
template <typename T , typename GRAPH> int LongestSubwalk( GRAPH& G , const vector<T>& a );

// �Ⴆ�΋��`�P�����啔��������������ꍇ��x<y��x<-y�����l�ɂȂ�悤�ɃO���t���\�z����B
// �O���t���t�ɂ���Γ������Ƃ��\�����A��E��艺�E�����Ȃ��󋵁ix<y <=>  x|y�Ȃǁj��
// �v�Z�ʂ��ǂ��Ȃ�B
