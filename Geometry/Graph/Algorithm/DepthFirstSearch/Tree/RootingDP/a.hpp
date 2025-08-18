// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/RootingDP/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1113759 (RecursionRootingDP)
// https://yukicoder.me/submissions/1113760 (BinaryRootingDP)

// �ċA�ɂ���DP�̌y�ʉ��B
// �^���_�̂��߂�f�̓f�t�H���g�����ŌĂяo���\�ł���K�v������B
template <typename TREE , typename F> inline ret_t<F> RecursionRootingDP( TREE& T , F& f , const int& root );

// dp[i] = val( i )��prod�ŉE����i�̎q�m�[�hj���킽��dp[j��ord(i,j)���Ŋ|�����l
// ���v�Z�����DP�̍ċA�ɂ��y�ʉ��B
// ord( i , j )��T.Edge( i )�ɂ�����j�̊i�[���B
template <typename TREE , typename VAL , typename RIGHT_ACTION> inline ret_t<VAL,int> BinaryRootingDP( TREE& T , VAL& val , RIGHT_ACTION& prod , const int& root );
