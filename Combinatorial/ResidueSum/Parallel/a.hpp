// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/ResidueSum/Parallel/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1123309 (NumeratorParallelResidueSum)

// N=A.size(),M=B.size()�ƒu���B
// N=num.size(),M=den.size()�ƒu���B
// ���͈͓͂̔��Ő���
// (1) N�����̂����Ȃ�񕉐���i�ɑ΂��Ă�num[i]>=0
// (2) M�����̂����Ȃ�񕉐���j�ɑ΂��Ă�den[j]>0
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// (sum(int j=0;j<M;j++){num[i]%den[j]})_{i=0}^{N-1}��
// O(min(N + M + max(num) log M , M log M + sum_i(sqrt(num[i] log M))))�ŋ��߂�B
template <typename INT1 , typename INT2> vector<ll> NumeratorParallelResidueSum( const vector<INT1>& num , const vector<INT2>& den );

// (sum(int i=0;i<N;i++){num[i]%den[j]})_{j=0}^{M-1}��
// O(M log M + sum_i(sqrt(num[i] log M))))�ŋ��߂�B
template <typename INT1 , typename INT2> vector<ll> DenominatorParallelResidueSum( const vector<INT1>& num , const vector<INT2>& den );
