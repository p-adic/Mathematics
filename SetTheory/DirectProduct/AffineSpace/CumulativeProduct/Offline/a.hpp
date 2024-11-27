// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/CumulativeProduct/Offline/a.hpp

#pragma once

// ARRAY�͎ʑ�a:int->U1�ɑ�������^�B
// HOM�͎ʑ�U1->U2�̑�h:T \times U1 -> U2�ɑ�������^�B
// query�̃T�C�Y��Q�ƒu���B

// ���͈͓͂̔��ŗv��
// (1) M1��U1�̃��m�C�h�\���ł���B
// (2) M2��U2�̌Q�\���ł���B
// (3) �et in T�ɑ΂�h(t,-)���Q�����^�ł���B
// (4) Q�����̊eq�ɑ΂�query[q]=(l_q,r_q,t_q)�ƒu����0 <= l_q <= r_q + 1�ł���B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B

// Q�����̊eq�ɑ΂���h(t_q,a(l_q))*...*h(t_q,a(r_q))���I�t���C�������ŋ��߂�B
// ���E���������̗ݐϐς��Ǘ����邱�Ƃ��\�����������팸�̂��߂ɉE�����݈̂����B


// ������O(1)

// �E��Ԑϑ��擾O(max_q r_q + Q log Q)
template <typename U1 , typename MONOID , typename U2 , typename GROUP , typename ARRAY , typename HOM , typename T>
class OfflineCumulativeProduct
{

private:
  MONOID m_M1;
  GROUP m_M2;
  ARRAY m_a;
  HOM& m_h;

public:
  inline OfflineCumulativeProduct( MONOID M1 , GROUP M2 , ARRAY a , HOM& h , const T& dummy );

  inline vector<U2> TotalIntervalProduct( const vector<tuple<int,int,T>>& query );
  
};
template <typename MONOID , typename GROUP , typename ARRAY , typename HOM , typename T> OfflineCumulativeProduct( MONOID M1 , GROUP M2 , ARRAY a , HOM& h , const T& dummy ) -> OfflineCumulativeProduct<inner_t<MONOID>,MONOID,inner_t<GROUP>,GROUP,ARRAY,HOM,T>;
