// c:/Users/user/Documents/Programming/Mathematics/Polynomial/LagrangeInterpolation/a.hpp

#pragma once
#include "../a.hpp"

// T���̂ł���ꍇ�̂݃T�|�[�g�B
// arg��val�̃T�C�Y��M�Ƃ��āAO(M^2 log M)�Ń��O�����W����Ԃ��v�Z����B
template <typename T> Polynomial<T> LagrangeInterpolation( const vector<T>& arg , const vector<T>& val );

