// c:/Users/user/Documents/Programming/Mathematics/Graph/Algorithm/HeldKarp/a.hpp

#pragma once

// �e�ӂ̏d�݂�path_E�ł��鏄�񐢁[���X�}�����ɂ�����
// ���_k_start���璸�_k_goal�܂ł�s��2�i�@�őΉ����钸�_�W���݂̂��o�R����ꍇ��
// �i�v�d�l�m�F�j
template <int NM , int P> const ll& HeldKarp( const int& k_start , const int& k_goal , const int& s , const int (&k_valid)[P] , const int& P_valid , const ll (&path_E)[NM][NM] , const int (&near)[P][P][2] , const ll (&E_min)[P][P] , int (&k_mid)[P] );
