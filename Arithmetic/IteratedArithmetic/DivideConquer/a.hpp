// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/IteratedArithmetic/DivideConquer/a.hpp

#pragma once

// M��T�̃��m�C�h�\���ł���ꍇ�ɂ̂݃T�|�[�g�B
// T�̗v�f�̗��M�Ɋւ��鑍��𕪊������Ōv�Z���A���̌��ʂ�Ԃ��B
// V<T>��erase�����K�v������B
template <typename T , template <typename...> typename V , typename MONOID> T DivideConquerMonoidalProd( MONOID M , V<T> f );
