// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/TimeSeriesSetMax/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../../../Algebra/Monoid/Group/Module/a.hpp"

// verify:
// https://atcoder.jp/contests/abc351/submissions/52928503�iMaxIntervalSum+AbstractBIT�j

// ���͈͓͂̔��ŗv��
// (1) bool operator<(const R&,const R&)�͑S�����ł���B
// (2) bool operator<(const U&,const U&)�͑S�����ł���B
// (3) M��U��Z���Q�\���ł���B�i<�Ɛ����I�ł���K�v�͂Ȃ��j
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// ������ABSTRACT_BIT�Ƃ���AbstractMonoidBIT��AbstractSegtree���g���ꍇ��(2)�̑����
// (3)' M��U��N���Q�\���ł���B
// �𖞂����Ηǂ��B

// �z��̊e������S��max�X�V���������ɍX�V�ς݂��ۂ����Ǘ�����f�[�^�\���B

// �z��̃T�C�Y��N�A�S��max�X�V�C�x���g�̌���E�A��Ԙa�擾�N�G���̌���Q�ƒu���B

// �돉����O(1)
// �z�񏉊���O(N + E log E)

// �S��max�X�V�C�x���g�ǉ�O(log E)

// ��Ԙa�擾�N�G���I�����C������O((N+Q)log N + E + (sorted?1:Q log Q))
template <typename R , typename U , typename Z_MODULE>
class AbstractTimeSeriesSetMaxBIT
{

private:
  Z_MODULE m_M;

  int m_N;
  // �����l���i�[
  vector<U> m_a;
  // {�S��max�X�V����,�X�V�l}���i�[
  map<R,U> m_event;

public:
  inline AbstractTimeSeriesSetMaxBIT( Z_MODULE M , const R& dummy , const int& N = 0 );
  inline AbstractTimeSeriesSetMaxBIT( Z_MODULE M , const R& dummy ,  vector<U> a , const vector<pair<R,U>>& event = {} );

  template <typename...Args> inline void Initialise( Args&&... args );

  // ����t��u�ł̑S��max�X�V���s���B
  inline void Set( const R& t , const U& u );

  // �e�N�G��{t,l,r}���ƂɁA����t�i�S��max�X�V��j�ɂ�������[l,r]�ł̑��a���擾�B
  template <typename INT , typename ABSTRACT_BIT = AbstractBIT<U,Z_MODULE>> vector<U> IntervalSum( const vector<tuple<R,INT,INT>>& query , const bool& sorted = false );

};
template <typename R , typename Z_MODULE , typename...Args> AbstractTimeSeriesSetMaxBIT( Z_MODULE , R , Args&&... ) -> AbstractTimeSeriesSetMaxBIT<R,inner_t<Z_MODULE>,Args...>;

template <typename U>
class TimeSeriesSetMaxBIT :
  public AbstractTimeSeriesSetMaxBIT<ll,U,Module<ll,U>>
{

public:
  inline TimeSeriesSetMaxBIT( const int& N = 0 );
  template <typename...Args> inline TimeSeriesSetMaxBIT( vector<U> a , Args&&... args );

};

// ���͈͓͂̔��ŗv��
// (1) bool operator<(const U&,const U&)�͑S�����ł���B
// (2) M��U��Z���Q�\���ł���B�i<�Ɛ����I�ł���K�v�͂Ȃ��j
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// ������ABSTRACT_BIT�Ƃ���AbstractMonoidBIT��AbstractSegtree���g���ꍇ��(2)�̑����
// (2)' M��U��N���Q�\���ł���B
// �𖞂����Ηǂ��B

// �e�N�G��{u,l,r}���ƂɁAmax(a[-],u)�̋��[l,r]�ł̑��a���擾�B�iO((N+Q)log N + Q log Q)�j
template <typename U , typename Z_MODULE , typename INT , typename ABSTRACT_BIT = AbstractBIT<U,Z_MODULE>> vector<U> AbstractMaxIntervalSum( Z_MODULE M , vector<U> a , const vector<tuple<U,INT,INT>>& query , const bool& sorted = false );
template <typename U , typename INT , typename ABSTRACT_BIT = AbstractBIT<U,Module<int,U>>> inline vector<U> MaxIntervalSum( vector<U> a , const vector<tuple<U,INT,INT>>& query , const bool& sorted = false );
