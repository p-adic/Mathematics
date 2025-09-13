// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/RootingDP/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/957397�iRootingDP�j
// https://yukicoder.me/submissions/957399�iRerootingDP�j
// https://yukicoder.me/submissions/957400�iRerootingDP�j

#include "../a.hpp"

// U�͓K���Ȍ^�AF�͎ʑ�f:(U^{< \omega}�̉E�Ӓl) \times N -> U�ɑ�������^�B
// �^���_�̂��߂�f�̓f�t�H���g�����ŌĂяo���\�Ƃ���B
// ���͈͓͂̔��ŗv��
// (1) �C�ӂ̔񕉐���n,i��T�̗v�f�݂̂���Ȃ�C�ӂ̒���n�̔C�ӂ̗�(u1,...,un)��
//     ���̕��ъ���(v1,...,vn)�ɑ΂�f((u1,...,un),i)=f((v1,...,vn),i)�ł���B
// �𖞂����ꍇ�̂݃T�|�[�g�B
// dp[j] = f(j�̎q�m�[�hk��n��dp[k]�̗�,j)
// �𖞂����z��dp�̍��ł̒ldp[root]��O(|V_T|)�ŋ��߂�B
template <typename DFST , typename F> ret_t<F> RootingDP( DFST& dfst , F& f );
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
// ���̃����o���g��Ȃ��̂ł���΁A�萔�{�̌y���ċA��
// Recursion/a_Body.hpp
// �̎g�p����������B
  
  
// U�͓K���Ȍ^�AF�͎ʑ�f:U \times N ->U�ɑ�������^�A
// G�͎ʑ�g:U \times \{0,1\} \times N^2 -> U�ɑ�������^�B
// ���͈͓͂̔��ŗv��
// (1) M��U�̃��m�C�h�\���ł���B�i�ȉ����Z��*�ƒu���j
// �𖞂����ꍇ�̂݃T�|�[�g�B
// dp[i][j] =
// f(i�����Ƃ݂Ȃ�������j�̎q�m�[�hk��ord(i,j)���ł킽�点��g(dp[i][k],���̖؍\����j��i�̎q��,k,j)��M�Ɋւ��ĉE�Ɋ|���Ă�����,j)
// �𖞂�����d�z��dp�̑Ίp����dp[i][i]��O(|V_T|)�ŋ��߂�answer[i]�Ɋi�[����B
// ������ord(i,j)��i�����Ƃ�������j�̎q�m�[�hk�̏����Â��ŁA
// - ���̖؍\����j�̐e�ƂȂ���̂��ŏ���
// - �����łȂ����̂�ChildrenNumber()�Ɋւ��ď�����
// �Ƃ��Ē�`����B
template <typename DFST , typename MONOID , typename F , typename G> vector<inner_t<MONOID>> RerootingDP( DFST& dfst , MONOID M , F& f , G& g );
// f�̓m�[�hj���Ƃ̃f�[�^�i�O���t�\���Ɉˑ����Ȃ��j
// g�͗L����is_child?(j,k):(k,j)���Ƃ̃f�[�^�i�O���t�\���A�Ⴆ��k���t���ۂ��Ɉˑ��ł���j
// �ɑΉ��B
// -�u�p�X�̐��v�����߂�ꍇ�F
//   AdditiveMonoid<int> M{};
//   auto f = [&]( const int& u , const int& i ){ return u + 1; };
//   auto g = [&]( cost int& u , const bool& is_child , const int& k , const int& j ){ return u; };
// -�u�p�X�̒����̍ő�l�v�����߂�ꍇ�F
//   MaxSemilattive<int> M{ -1 };
//   auto f = [&]( const int& u , const int& i ){ return u + 1; };
//   auto g = [&]( cost int& u , const bool& is_child , const int& k , const int& j ){ return u; };
// - �m�[�hi��U�^�̒lA[i]����܂��Ă���^U�̉����m�C�h�\��M���^�����i�����Ƃ��ăm�[�hj�̎q�m�[�hk���킽����(i�����Ƃ���k���t?A[k]:dp[i][k])�̑��a��dp[i][j]�Ɋi�[����ꍇ�F
//   auto f = [&]( const U& u , const int& i ){ return u; };
//   auto g = [&]( cost U& u , const bool& is_child , const int& k , const int& j ) { return dfst.IsLeaf( i , k ) ? A[k] : u; };
// - �m�[�hi��U�^�̒lA[i]����܂��Ă���^U�̉����m�C�h�\��M���^�����i�����Ƃ���(�m�[�hj���t?A[j]:j�̎q�m�[�hk���킽��dp[i][k]�̑��a)��dp[i][j]�Ɋi�[����ꍇ�́Adp[i][i]=(size=1?A[i]:��̃P�[�X��dp[i][i])�ŏ����\
// - ���ъ����s�ςȊ֐�h:U^{< omega} -> U���^�����Ă���h(i�����Ƃ�������j�̎q�m�[�hk���킽��dp][i][k]����)��dp[i][j]�Ɋi�[����ꍇ�F
//   auto concate = [&]( vector<U> v0 ,  const vector<U>& v1 ) {
//     RUN( v1 , u ){
//       v0 <<= u;
//     }
//     return move( v0 );
//   }
//   vector<U> empty{}:
//   AbstractMonoid M{ concat , empty };
//   auto f = [&]( const vector<U>& v , const int& i ){ return vector<U>{ h( v ) }; };
//   auto g = [&]( cost vector<U>& v , const bool& is_child , const int& k , const int& j ) -> const vector<U>& { return v; };
