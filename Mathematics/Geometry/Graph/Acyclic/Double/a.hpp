// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Acyclic/Double/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/961435�iGetDistance�j

// ���͈͓͂̔��ŗv��
// (1) G1����T1->(T1 \times ...)^{< \omega}�������H�������Ȃ��L���O���t�ł���B
// (2) G2����T1 \times T2->(T1 \times T2 \times U \times ...)^{< \omega}������
//     �L���O���t�ł���B
// (3) vertex�͎ʑ�T1->T2^{<\omega}�ł���A�C�ӂ�t1 \in T1�ɑ΂�vertex( t1 )��
//     V_{t1}:={t2 \in T2|(t1,t2) \in V_{G2}}�̖����ł���B
// (4) �C�ӂ�(s1,t1) \in V_{G_1}^2�ɑ΂��ȉ������l�ł���F
//     (a) G1���L����s1->t1�����B
//     (b) ����(s2,t2) \in T2^2�����݂���G2���L����(s1,s2)->(t1,t2)�����B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
template <typename T1 , typename ACYCLIC_GRAPH , typename T2 , typename U , typename GRAPH , typename VERTEX>
class AcyclicDoubleGraph
{

private:
  ACYCLIC_GRAPH& m_G1;
  GRAPH& m_G2;
  VERTEX m_vertex;
  vector<T1> m_top_sort;

public:
  inline AcyclicDoubleGraph( ACYCLIC_GRAPH& G1 , GRAPH& G2 , VERTEX& vertex );
  inline AcyclicDoubleGraph( ACYCLIC_GRAPH& G1 , GRAPH& G2 , VERTEX& vertex  , vector<T1> top_sort );

  inline const vector<T1>& GetTopologicalSort() const noexcept;

  // ���͈͓͂̔��ŗv��
  // (2) M��operator<(const U&,const U&)�Ɋւ���U�̏��������m�C�h�\���ł���B
  // �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
  // t_starts�̓_���n�_�Ƃ���ŒZ�o�H����
  // O(min(\sum_{t1} |V_{t1)|^2,\sum_{t1} (|V_{t1}|+|E_{t1}|)log_2|E_{t2}|))
  // �Ōv�Z����B
  template <typename COMM_MONOID> vector<U> GetDistance( const vector<pair<T1,T2>>& t_starts , COMM_MONOID M , const U& infty , const bool& many_edges = true );

};
template <typename ACYCLIC_GRAPH , typename GRAPH , typename VERTEX , typename...Args> AcyclicDoubleGraph( ACYCLIC_GRAPH& G1 , GRAPH& G2 , VERTEX& vertex , Args&&... ) -> AcyclicDoubleGraph<inner_t<ACYCLIC_GRAPH>,ACYCLIC_GRAPH,decldecay_t( declval<inner_t<GRAPH>>().second ),decldecay_t( declval<GRAPH>().Edge( declval<inner_t<GRAPH>>() ).front().second ),GRAPH,VERTEX>;
