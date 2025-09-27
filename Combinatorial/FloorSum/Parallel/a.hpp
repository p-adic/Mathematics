// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/FloorSum/Parallel/a.hpp

#pragma once
#include "a_Macro.hpp"
// verify:
// https://yukicoder.me/submissions/1123304

// N=num.size(),M=den.size()�ƒu���B
// ���͈͓͂̔��Ő���
// (1) N�����̂����Ȃ�񕉐���i�ɑ΂��Ă�num[i]>=0
// (2) M�����̂����Ȃ�񕉐���j�ɑ΂��Ă�den[j]>0
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// O(M log_2 M + sum_i sqrt(num[i] log_2 M))��answer[i]��sum_j num[i]/den[j]���i�[����B
template <typename INT1 , typename INT2 , typename RET = ll> vector<RET> NumeratorParallelFloorSum( const vector<INT1>& num , const vector<INT2>& den , vector<RET> coeff = {} );

// O(M log_2 M + sum_i sqrt(num[i] log_2 M))��answer[j]��sum_i num[i]/den[j]���i�[����B
template <typename INT1 , typename INT2> vector<ll> DenominatorParallelFloorSum( const vector<INT1>& num , const vector<INT2>& den );
