// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/957468�iDepth,Heaviness,Ancestor,LCA�j
// https://yukicoder.me/submissions/957397�iRootingDP�j
// https://yukicoder.me/submissions/957399�iRerootingDP�j
// https://yukicoder.me/submissions/957400�iRerootingDP�j

// TREE��Graph<Edge>�ƕ\����A��T=(V_T,E_T)�ɑ�������^�B����V_T�̌^��int�Ɍ�����B
// ������E_T�͕�V_T -> (V_T \times ...)^{< \omega}�ɑ�������֐��I�u�W�F�N�g�B

// ���͈͓͂̔���
// (1) T�������؂ł��邩�Aroot�����Ƃ��t�Ɍ������L���؂ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// �\�zO(|V_T|)

// ������̕ӂ̖{���i�[���j�擾O(|V_T|)�i��x�ڈȍ~��O(1)�j
// �t����̕ӂ̖{���̍ő�^�ŏ��l�i�����j�擾O(|V_T|)�i��x�ڈȍ~��O(1)�j
// �����؂̕ӂ̖{���i�d���j�擾O(|V_T|)�i��x�ڈȍ~��O(1)�j

// �ؓ��I�v��@O(|V_T|)
// �S���ʖؓ��I�v��@O(|V_T|)

// �ȉ��A���͈͓͂̔���
// (2) �e�m�[�h�̗t����̕ӂ̖{�� < 2^digit
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// 2^16 = 65536
// 2^17 = 131072
// 2^18 = 262144
// ��c�擾O(|V_T| digit)�i��x�ڈȍ~��O(digit)�j
// �ŋߐڋ��ʐ�c�擾O(|V_T| digit)�i��x�ڈȍ~��O(digit)�j
template <typename TREE>
class DepthFirstSearchOnTree :
  public DepthFirstSearch<int,TREE> ,
  public PointedSet<int>
{

protected:
  // size()�͑c��N���X��BreadFirstSearch�ɒ�`�B
  
  // �������DFS���Ƀm�[�h�ԍ����i�[�B
  vector<int> m_node_num;

  // �q�m�[�h�̃m�[�h�ԍ����i�[�B
  vector<vector<int>> m_children;
  // �e�m�[�h��j�Ƃ�����m_children[j]�̉��Ԗڂ̐��������i�[�B
  // �������e�m�[�h�����݂��Ȃ�����-1���i�[�B
  vector<int> m_children_num;
  bool m_set_children;

  // ������̋����i�[���j���i�[�B
  vector<int> m_depth;
  bool m_set_depth;

  // �t����̋����i�����j���i�[�B
  vector<int> m_height_max;
  vector<int> m_height_min;
  bool m_set_height;

  // �����؂̕ӂ̖{���i�T�C�Y�j���i�[�B
  vector<int> m_heaviness;
  bool m_set_heaviness;

  int m_digit;
  vector<vector<int>> m_doubling;
  bool m_set_doubling;

public:
  inline DepthFirstSearchOnTree( TREE& T , const int& root = 0 , const int& digit = 0 );
  inline void Initialise() = delete;
  inline void Initialise( const int& init ) = delete;
  inline void Shift( const int& init ) = delete;

  inline const int& Root() const;
  inline const int& Parent( const int& i );
  inline const vector<int>& Children( const int& i );
  inline const int& Depth( const int& i );
  inline const int& Height( const int& i , const bool& maximum = true );
  inline const int& Heaviness( const int& i );
  // �����O���t�Ƃ��Ă̎�����Ԃ��B
  inline int Degree( const int& i );
  // root�����Ƃ������ɗt�ł��邩�ۂ���Ԃ��B������root=-1�͌��݂̍���root��u��������B
  inline bool IsLeaf( const int& i , const int& root = -1 );

  // �������DFS���Ƀm�[�h��ԍ��Â���B
  // reversed = true�̏ꍇ�͋A�肪�����ł͂Ȃ��s���������̋t���ł��邱�Ƃɒ��ӁB
  inline const int& NodeNumber( const int& i , const bool& reversed = false ) const;
  // ���ʂ̐e�����m�[�h�Ԃŏ����ɔԍ��Â���B
  inline const int& ChildrenNumber( const int& i );
  // Ord�͑S�����̑�ord:N \times N^2 -> {0,1}�ɑ�������^�B
  // �e�m�[�hi�̎q�m�[�h�̊i�[����ord( i , - , - )�����ɕύX����B
  template <typename Ord> inline void ReorderChildren( Ord& ord );

  // ���͈͓͂̔��ŗv��
  // (1) �e�m�[�h�̍��� < 2^digit
  // �𖞂����ꍇ�̂݃T�|�[�g�B
  // n�K�̐eParent^n( i )��Ԃ��B
  int Ancestor( int i , int n );

  // ���͈͓͂̔��ŗv��
  // (1) �e�m�[�h�̍��� < 2^digit
  // �𖞂����ꍇ�̂݃T�|�[�g�B
  // i��j�̍ŋߐڋ��ʑc���Ԃ��B
  inline int LCA( int i , int j );
  // LCA����i,j���ɐi�߂�ꍇ�ɐi�񂾐�̒��_�̃��x����i_prev,j_prev�Ɋi�[����B
  int LCA( int i , int j , int& i_prev , int& j_prev );

  // U�͓K���Ȍ^�AF�͎ʑ�f:U^{< \omega} \times N -> U�ɑ�������^�B
  // �^���_�̂��߂�f�̓f�t�H���g�����ŌĂяo���\�Ƃ���B
  // ���͈͓͂̔��ŗv��
  // (2) �C�ӂ̔񕉐���n,i��T�̗v�f�݂̂���Ȃ�C�ӂ̒���n�̔C�ӂ̗�(u1,...,un)��
  //     ���̕��ъ���(v1,...,vn)�ɑ΂�f((u1,...,un),i)=f((v1,...,vn),i)�ł���B
  // �𖞂����ꍇ�̂݃T�|�[�g�B
  // dp[j] = f(j�̎q�m�[�hk��n��dp[k]�̗�,j)
  // �𖞂����z��dp�̍��ł̒ldp[root]��O(|V_T|)�ŋ��߂�B
  template <typename F> ret_t<F> RootingDP( F& f );
  // - �m�[�hi��U�^�̒lA[i]����܂��Ă��肻�̕����ؘa��dp[i]�Ɋi�[����ꍇ�F
  //   auto f = [&]( const vector<U>& u , const int& i ){
  //     U answer = A[i];
  //     for( auto& x : u ){ answer += x; }
  //     return answer;
  //   };
  // - �m�[�hi��U�^�̒lA[i]����܂��Ă���^U�̔�����m�C�h�\��M���^�����m�[�h�ԍ��̑S����ord����`����Ă���i�̎q�m�[�h���킽��m�[�h�ԍ�j��ord������M�Ɋւ���dp[j]�̑����A[i]�ɉE����|�������̂�dp[i]�Ɋi�[����ꍇ�F
  //   auto f = [&]( vector<pair<U,int>>& u , const int& i ){
  //     U answer = A[i];
  //     sort( u.begin() , u.end() , [&]( const pair<U,int>& u0 , const pair<U,int>& u1 ){ return ord( get<1>( u0 ) , get<1>( u1 ) ); } );
  //     for( auto& [x,j] : u ){ answer = M.Product( move( answer ) , x ); }
  //     return pair{ move( answer ) , i };
  //   };
  
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
  template <typename MONOID , typename F , typename G> vector<inner_t<MONOID>> RerootingDP( MONOID M , F& f , G& g );
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

  inline tuple<int,int,int> Diameter();
  
private:
  void SetChildren();
  void SetDepth();
  void SetHeight();
  void SetHeaviness();

  // LCA()���ĂԑO��Ancestor()�o�R�Ŋ��S�Ƀ_�u�����O��ݒ肷��B
  // �x���]�����Ă��܂�
  // ../../../../Function/Iteration/Doubling/
  // �̃_�u�����O�ł͑�p���Ȃ��B
  void SetDoubling();

};
