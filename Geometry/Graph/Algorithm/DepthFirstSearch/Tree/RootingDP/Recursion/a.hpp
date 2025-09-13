// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/RootingDP/Recursion/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1113759 (RecursionRootingDP)
// https://yukicoder.me/submissions/1113760 (BinaryRootingDP)

// �ċA�ɂ���DP�̌y�ʉ��B
// U�͓K���Ȍ^�AF�͎ʑ�f:(U^{< \omega}�̉E�Ӓl) \times N -> U�ɑ�������^�B
// �^���_�̂��߂�f�̓f�t�H���g�����ŌĂяo���\�Ƃ���B
// ���͈͓͂̔��ŗv��
// (1) �C�ӂ̔񕉐���n,i��T�̗v�f�݂̂���Ȃ�C�ӂ̒���n�̔C�ӂ̗�(u1,...,un)��
//     ���̕��ъ���(v1,...,vn)�ɑ΂�f((u1,...,un),i)=f((v1,...,vn),i)�ł���B
// �𖞂����ꍇ�̂݃T�|�[�g�B
// dp[j] = f(j�̎q�m�[�hk��n��dp[k]�̗�,j)
// �𖞂����z��dp�̍��ł̒ldp[root]��O(|V_T|)�ŋ��߂�B
template <typename TREE , typename F> inline ret_t<F> RecursionRootingDP( TREE& T , F& f , const int& root );
// - �m�[�hi��U�^�̒lA[i]����܂��Ă��肻�̕����ؘa��dp[i]�Ɋi�[����ꍇ�F
//   auto f = [&]( vector<U> u , const int& i ){
//     U answer = A[i];
//     for( auto& x : u ){ answer += x; }
//     return answer;
//   };
// - �m�[�hi��U�^�̒lA[i]����܂��Ă���^U�̔�����m�C�h�\��M���^�����m�[�h�ԍ��̑S����ord����`����Ă���i�̎q�m�[�h���킽��m�[�h�ԍ�j��ord������M�Ɋւ���dp[j]�̑����A[i]�ɉE����|�������̂�dp[i]�Ɋi�[����ꍇ�F
//   auto f = [&]( vector<pair<U,int>> u , const int& i ){
//     U answer = A[i];
//     sort( u.begin() , u.end() , [&]( const pair<U,int>& u0 , const pair<U,int>& u1 ){ return ord( get<1>( u0 ) , get<1>( u1 ) ); } );
//     for( auto& [x,j] : u ){ answer = M.Product( move( answer ) , x ); }
//     return pair{ move( answer ) , i };
//   };


// dp[i] = val( i )��prod�ŉE����i�̎q�m�[�hj���킽��dp[j]��ord(i,j)���Ŋ|�����l
// ���v�Z�����DP�̍ċA�ɂ��y�ʉ��B
// U�͓K���Ȍ^�AVAL�͎ʑ�f:N -> U�ɑ�������^�ARIGHT_ACTION�͎ʑ�f(U^2�̉E�Ӓl) -> U�ɑ�������^�B
// ord( i , j )��T.Edge( i )�ɂ�����j�̊i�[���B
template <typename TREE , typename VAL , typename RIGHT_ACTION> inline ret_t<VAL,int> BinaryRootingDP( TREE& T , VAL& val , RIGHT_ACTION& prod , const int& root );
