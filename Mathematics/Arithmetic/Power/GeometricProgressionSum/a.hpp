// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Power/GeometricProgressionSum/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1015838 (GeometricProgressionLinearCombinationSum)

// ���͈͓͂̔��ŗv��
// (1) T��operator+,operator-,operator*�Ɋւ��ĒP�ʓI���Ȃ��B
// (2) exponent_max >= 0�ł���B
// (3) rate - 1��0�łȂ��Ȃ��(1)�̒P�ʓI�\���Ɋւ��ĉt�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B�iT{}��GeometricProgressionLinearCombinationSum�́j

// ���䐔��init,init*rate,...,init*rate^exponent_max�̑��a��
// O((log exponent_max)+�t���v�Z��)�ŋ��߂�B
template <typename T , typename UINT> inline T GeometricProgressionSum( T rate , UINT exponent_max , const T& init = 1 );
// ���䐔��̐��`�a�̑��a��P�ɓ��䐔��̑��a�̐��`�a�Ƃ��ċ��߂�B
template <typename T , typename UINT>
T GeometricProgressionLinearCombinationSum( vector<T> rate , vector<UINT> exponent_max , const vector<T>& init );
