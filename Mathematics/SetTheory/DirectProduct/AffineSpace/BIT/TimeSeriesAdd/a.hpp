// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/TimeSeriesAdd/a.hpp

#pragma once
#include "../../../../../Algebra/Monoid/Group/Module/Interval/a_Body.hpp"

// verify:
// https://yukicoder.me/submissions/977887�i�z�񏉊����ASet�j

// ���͈͓͂̔��ŗv��
// (1) R�͑S�����W���ł���BR�̒�߂錗��C�ƒu���B
// (2) M��U��C��p�t�����Q�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// �z��̊e�������w�肵���X���i�P�ʎ��ԓ�����̕ω��ʁj�ŕω�����������
// �X����y�ؕЂ��Ǘ�����f�[�^�\���B

// �z��̃T�C�Y��N�A�X���ύX�C�x���g�̌���E�A��Ԙa�擾�N�G���̌���Q�ƒu���B

// �돉����O(1)
// �z�񏉊���O(N + E log E)

// �X���ύX�C�x���g�ǉ�O(log E)

// ��Ԙa�擾�N�G���I�����C������O((E+Q)log N + (sorted?1:Q log Q))
template <typename R , typename U , typename C_MODULE>
class AbstractTimeSeriesAddBIT
{

private:
  C_MODULE m_M;
  // �����������i�[
  R m_init;

  int m_N;
  // �����l���i�[
  vector<U> m_a;
  // {�X���ύX����,�ύX�Ώۂ�index,�X��}���i�[
  // �i�X���ύX�������傤�ǂ͕ύX��̌X���̊�^��0�ł��邱�Ƃɒ��Ӂj
  map<pair<R,int>,U> m_event;

public:
  inline AbstractTimeSeriesAddBIT( C_MODULE M , R init , const int& N = 0 );
  inline AbstractTimeSeriesAddBIT( C_MODULE M , R init , vector<U> a , const vector<tuple<R,int,U>>& event = {} );

  template <typename...Args> inline void Initialise( Args&&... args );

  // �����Ɋւ���a[i]�̃O���t�̌X��������t����du�ɕύX����B
  // �i���X�̌X����0�łȂ��ꍇ�͎���t���傤�ǂ܂ł̉��Z���s���邱�Ƃɒ��Ӂj
  inline void Set( const R& t , const int& i , const U& du );

  // �e{t,l,r}���ƂɁA����t�ɂ�������[l,r]�ł̑��a���擾�B
  template <typename INT> vector<U> IntervalSum( const vector<tuple<R,INT,INT>>& query , const bool& sorted = false );

};
template <typename R , typename C_MODULE , typename...Args> AbstractTimeSeriesAddBIT( C_MODULE , R , Args&&... ) -> AbstractTimeSeriesAddBIT<R,inner_t<C_MODULE>,Args...>;

template <typename U>
class TimeSeriesAddBIT :
  public AbstractTimeSeriesAddBIT<ll,U,IntervalModule<ll,U>>
{

public:
  inline TimeSeriesAddBIT( const int& N = 0 );
  template <typename...Args> inline TimeSeriesAddBIT( vector<U> a , Args&&... args );

};
