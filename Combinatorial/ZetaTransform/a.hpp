// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/ZetaTransform/a.hpp

#pragma once

// ���͈͓͂̔��ŗv��
// (1) G��T�̓����t���������\��<=�̃O���t�is<=t <=> s <- t�j�ł���B
// (2) G_inv��G�̕ӂ��t�ɂ����O���t�ł���B
// (3) R��U�́i�P�ʓI�łȂ��Ă��ǂ��jZ�㐔�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// ������
// - �S�̉��Z���_�擾���s��Ȃ��Ȃ��R�̓_�~�[��Z��p������P�ʓI�ł��ǂ��B
// - �S�̏�Z���ݍ��ݏ�@���s��Ȃ��Ȃ��R�̓_�~�[�̐ς�����Z���Q�ł��ǂ��B

// T��̊֐�f(t)��{-��}��T��̗אڑ㐔�̌�F(s,t)=s==-��?f(t):0�ɑΉ������ă[�[�^�ϊ�����B
// �Ⴆ��<=���{���֌W�Ȃ�Δ{���S�̂ł̑��a�A�񐔊֌W�Ȃ�Ζ񐔑S�̂ł̑��a�����B

// R.Zero()�ɂ�鏉����O(size)
// �[�[�^�ϊ��O�̔z��ɂ�鏉����O(size+�n�ؕЂ̃T�C�Y�̑��a)�i�����@���m�C�h�����g���j
// �[�[�^�ϊ���̔z��ɂ�鏉����O(1)

// ��_���ZO(�I�ؕ�[t,��)�̃T�C�Y)�im_G_inv�Ɖ����@���m�C�h�����g���j
// �S�̉��ZO(size)�i�����@���m�C�h�������ł������ł��邪�������̂��߂ɔ�P�ʓIZ�㐔�����g���j
// ���@O(size)�im_G.Edge����Q�ƂȂ��O(size + |m_G.Edge|)�A�����@���m�C�h�����g���j

// �S�̏�ZO(size)�i�������g���j
// (T,<)��join�����ł���ꍇ�̏�ݍ��ݏ�@O(size)�i�������g���j

// ��_�擾O(�n�ؕ�(-��,t]�̃T�C�Y * ���r�E�X�֐��̌v�Z��)�i��P�ʓIZ�㐔�����g���j
// �n�ؕИa�擾O(1)�i�����@���m�C�h�����g���j

// �t���a�擾O(�n�ؕ�(-��,r_max]�̃T�C�Y * ���r�E�X�֐��̌v�Z��)�i��P�ʓIZ�㐔�����g���j
// �n�ؕЋt���a�擾O(1)�i�����@���m�C�h�����g���j
template <typename T , typename GRAPH , typename GRAPH_INV , typename U , typename Z_ALG>
class VirtualZetaTransform
{

protected:
  GRAPH m_G;
  GRAPH_INV m_G_inv;
  Z_ALG m_R;
  // T�̊e�v�ft�ɑ΂��At�ȉ��̗v�f��n�鑍�a��m_val[m_G.Enumeration_inv( t )]�ɊǗ��B
  vector<U> m_val;

public:
  inline VirtualZetaTransform( GRAPH G , GRAPH_INV G_inv , Z_ALG R );
  inline VirtualZetaTransform( GRAPH G , GRAPH_INV G_inv , Z_ALG R , vector<U> a , const bool& transformed = false );

  template <typename...Args> inline void Initialise( Args&&... args );

  inline void Add( const T& t , const U& u );
  inline void TotalAdd( const U& u );
  inline VirtualZetaTransform<T,GRAPH,GRAPH_INV,U,Z_ALG>& operator+=( const VirtualZetaTransform<T,GRAPH,GRAPH_INV,U,Z_ALG>& a );
  
  inline void TotalMultiply( const U& u );
  inline VirtualZetaTransform<T,GRAPH,GRAPH_INV,U,Z_ALG>& operator*=( const VirtualZetaTransform<T,GRAPH,GRAPH_INV,U,Z_ALG>& a );

  // �������ɕt�����郁�r�E�X�֐��̃f�t�H���g�̍ċA�����g�����߁A
  // �ċA�[�x���󂢏ꍇ�ɂ����g���Ȃ��B
  U operator[]( const T& t );
  inline U Get( const T& t );
  inline const U& InitialSegmentSum( const T& t );

  // �����ʑ�f_inv_max:T->T�Ǝʑ�range:T->T^{<��}�ƈ����ł���S�̗v�fs���v��
  // (1) f_inv_max�͒�`���range(s)���܂�
  // (2) range(s)�͏d���������Ȃ��B�i�����S�̕����W���Ƃ݂Ȃ��j
  // (3) s��range(s)�̍ő匳�ł���B
  // �𖞂����A���v��
  // (4) f_inv_max(s)����E�Ɏ���T�̗v�f�S��R_s�ւ�f�̐���f_s�͏����ۑ��ʑ�R_s->range(s)�ł���B
  // (5) range(s)�̔C�ӂ̗v�fs'�ɑ΂�f_inv_max(s')���t��f_s^{-1}(s')�̍ő匳�ł���B
  //    �i�]���ē���f_s�͑S�ˁj
  // �𖞂����ʑ�f:T->T�����݂���ꍇ�ɂ݈̂ȉ��̂Q���T�|�[�g�B

  // f(t)=s�𖞂���R_s�̗v�ft�S�̂�n��m_val[t]�̑��a�擾�B
  // �������ɕt�����郁�r�E�X�֐��̃f�t�H���g�̍ċA�����g�����߁A
  // �ċA�[�x���󂢏ꍇ�ɂ����g���Ȃ��B
  template <typename F_INV_MAX , typename RANGE> U InverseImageSum( F_INV_MAX&& f_inv_max , RANGE&& range , const T& s );
  // ��P�FT=int�A<=:�C�ӂ̓�����������
  //      f=�e�_�̋t�����u��󂩂�ɗL�E�v�𖞂����P�������ʑ��A
  //      f_inv_max=f�̋t���̍ő�l�Arange(x)=[1,x]
  //      -> f^{-1}({f(s)})�̊e�_t���킽��m_val[t]�̑��a�擾�B
  // ��Q�FT=[1,size)�As <= t: s��t�̖� 
  //      f=gcd(lcm(a,-),b)�ia,b��a��b�̖񐔂ł���萔in S�j�Af_inv_max=id_S�As=b�A
  //      range=a�̔{���ł���b�̖񐔑S�̂̏W����Ԃ��萔�֐�
  //      -> lcm(a,t)��b�̔{���ł���size�����̊e������t���킽��m_val[t]�̑��a�擾�B
  // ��R�FT=[1,size)�As <= t: s��t�̔{��
  //      f=gcd(a,-)�ia�͒萔in S�j�Af_inv_max=id_S�As=1�A
  //      range=a�̖񐔑S�̂̏W����Ԃ��萔�֐�
  //      -> a�ƌ݂��ɑf��size�����̊e������t���킽��m_val[t]�̑��a�擾�B
  
  // f(t) <= s�𖞂���R_s�̗v�ft�S�̂�n��m_val[t]�̑��a�擾�B
  //�i���ʓI��range�͎g��Ȃ����v�����range�̑��݂��K�v�j 
  template <typename F_INV_MAX> inline const U& InitialSegmentInverseImageSum( F_INV_MAX&& f_inv_max , const T& s );
 
private:
  virtual int Moevius( const T& t0 , const T& t1 );

};
template <typename GRAPH , typename GRAPH_INV , typename Z_ALG> VirtualZetaTransform( GRAPH& , GRAPH_INV& , Z_ALG ) -> VirtualZetaTransform<inner_t<GRAPH>,GRAPH,GRAPH_INV,inner_t<Z_ALG>,Z_ALG>;

// ���͈͓͂̔��ŗv��
// (1) G��T�̓����t���������\��<=�̃O���t�is<=t <=> s <- t�j�ł���B
// (2) G_inv��G�̕ӂ��t�ɂ����O���t�ł���B
// (3) R��U�̔�P�ʓIZ�㐔�\���ł���B
// (4) mu��(T,<=)�̃��r�E�X�֐��ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B��_�擾�Ƌt���a�擾�ɂ̂�mu���g���B
// �������S�̉��Z���_�擾���s��Ȃ��Ȃ��R�̓_�~�[��Z��p������P�ʓI�ł��ǂ��B

// R.Zero()�ɂ�鏉����O(size)
// �[�[�^�ϊ��O�̔z��ɂ�鏉����O(�n�ؕЂ̃T�C�Y�̑��a)
// �[�[�^�ϊ���̔z��ɂ�鏉����O(1)

// ��_���ZO(�I�ؕ�[t,��)�̃T�C�Y)
// �S�̉��ZO(size)
// �e�_���@O(size)�im_G_inv��p����j
// �S�̏�ZO(size)
// (int,<=)��join�����ł���ꍇ�̏�ݍ��ݏ�@O(size)

// ��_�擾O(�n�ؕ�(-��,t]�̃T�C�Y)
// �n�ؕИa�擾O(1)

// �t���a�擾O(�n�ؕ�(-��,f_inv_max(r_max)]�̃T�C�Y)
// �n�ؕЋt���a�擾O(1)
template <typename T , typename GRAPH , typename GRAPH_INV , typename U , typename Z_ALG , typename MU>
class AbstractZetaTransform :
  // �R���X�g���N�^���񎩖��Ȃ̂ŉ��z�p���������B
  public VirtualZetaTransform<T,GRAPH,GRAPH_INV,U,Z_ALG>
{

private:
  MU m_mu;
  
public:
  template <typename...Args> inline AbstractZetaTransform( GRAPH G , GRAPH_INV G_inv , Z_ALG R , MU mu , Args&&... args );
  
private:
  inline int Moevius( const T& t0 , const T& t1 );

};
template <typename GRAPH , typename GRAPH_INV , typename Z_ALG , typename MU> AbstractZetaTransform( GRAPH& , GRAPH_INV& , Z_ALG , MU ) -> AbstractZetaTransform<inner_t<GRAPH>,GRAPH,GRAPH_INV,inner_t<Z_ALG>,Z_ALG,MU>;
