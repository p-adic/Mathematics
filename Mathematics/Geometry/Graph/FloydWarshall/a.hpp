// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/FloydWarshall/a.hpp

#pragma once

// verify: https://yukicoder.me/submissions/920482

// ���͈͓͂̔��ŗv��
// (1) (T,A_T:T^2->T)��meet�����i��㰓����Q�j�ł���B
//     �i�ȉ�A_T�̒�߂铙������������<=�ƒu���j
// (2) (T,m_T:T^2->T)�����Q�ł���B
// (3) m_T��A_T�㕪�z�I�A�܂�
//     - T�̔C�ӂ̗v�fs,t,u�ɑ΂�
//       - m_T(u,A_T(s,t)) = A_T(m_T(u,s),m_T(u,t)) 
//       - m_T(A_T(s,t),u) = A_T(m_T(s,u),m_T(t,u))
//     �ł���B
// (4) infty�łȂ�d�̒l���������镔�����Q��non-negative�A�܂�
//     - T�̔C�ӂ̗v�fs��infty�łȂ�d�̔C�ӂ̒lt�ɑ΂�
//       - s<=m_T(s,t) 
//       - s<=m_T(t,s)
//     �ł���B
// (5) infty�łȂ�d�̒lsize_max�ȉ���m_T�Ɋւ���ς�infty���\���Ȃ��B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B

// ������<=���������S�����ł���ꍇ�A(3)��
// (3)' m_T��<=�Ɋւ��锼�������Q���Z�A�܂�
//     - T�̔C�ӂ̗v�fs,t,u�ɑ΂�s<=t�Ȃ��
//       - m_T(u,s) <= m_T(u,t) 
//       - m_T(s,u) <= m_T(t,u)
//     �ł���B
// �Ɠ��l�ł��邱�Ƃɒ��ӁB

// O(size_max^3)�őS�o�H�̏d�݁iedge���Ƃ̏d�݂�m_T�Ɋւ���ρj��
// A_T�Ɋւ��鉺���i���ϐ�������A_T�ւ̓K�p�l�j���v�Z�B
template <typename T , T m_T(const T&,const T&) , T A_T(const T&,const T&) , int size_max>
void FloydWarshall( const T ( &d )[size_max][size_max] , T ( &weight )[size_max][size_max] , const int& size , const T& infty );


// ���͈͓͂̔��ŗv��
// (1)' bool operator<(const T&,const T&)���S�����ł���B
//     �i�ȉ�<�̒�߂铙�����S������<=�ƒu���j
// (2) (T,m_T:T^2->T)�����Q�ł���B
// (3)' m_T��<=�Ɋւ��锼�������Q���Z�A�܂�
//     - T�̔C�ӂ̗v�fs,t,u�ɑ΂�s<=t�Ȃ��
//       - m_T(u,s) <= m_T(u,t) 
//       - m_T(s,u) <= m_T(t,u)
//     �ł���B
// (4) infty�łȂ�d�̒l���������镔�����Q��non-negative�A�܂�
//     - T�̔C�ӂ̗v�fs��infty�łȂ�d�̔C�ӂ̒lt�ɑ΂�
//       - s<=m_T(s,t) 
//       - s<=m_T(t,s)
//     �ł���B
// (5) infty�łȂ�d�̒lsize_max�ȉ���m_T�Ɋւ���ς�infty���\���Ȃ��B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B

// O(size_max^3)�Ŋe�Q�_�Ԃ̍ŒZ�o�H���P���v�Z�Bpath[i][j]�ɂ́A
// �Œ肵���ŒZ�o�Hi->j�Ōo�R����P�_������΂��̒l�A�Ȃ����-1���i�[�B
template <typename T , T m_T(const T&,const T&) , int size_max>
void FloydWarshall( const T ( &d )[size_max][size_max] , T ( &weight )[size_max][size_max] , const int& size , const T& infty , int ( &path )[size_max][size_max] );

