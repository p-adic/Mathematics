// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/ZetaTransform/Divisor/a.hpp

#pragma once
#include "a_Macro.hpp"
#include "../../../Arithmetic/Prime/Constexpr/a.hpp"

// �ÓT�I�ȂP�ϐ����r�E�X�֐��i../../Arithmetic/Prime/Divisor/a_Body.hpp�j�̂Q�ϐ����B
// �ŏ��̂�O(val_lim log val_lim)�Ō��O(1)�B
// �����p����mu(const int&,const int&)��
// - t0 <= t1��t1 % t0 == 0�ŗ^������ꍇ�͂��̂܂�prime��n���B
// - t0 <= t1��t0 % t1 == 0�ŗ^������ꍇ�͕ϐ��𔽑΂ɂ���prime��n���B
// �ƒ�`����ZetaTansformBody��Get<mu>�ɓn���B
template <typename INT , INT val_limit , int length_max> int TwoAryMoeviusFunction( const PrimeEnumeration<INT,val_limit,length_max>& prime , const int& t0 , const int& t1 );

template <typename INT , INT val_limit , int length_max> inline list<int> DivisorEdgeForZetaTransform( const PrimeEnumeration<INT,val_limit,length_max>& prime , const int& t_max , const int& t );
inline list<int> MultipleEdgeForZetaTransform( const int& t_max , const int& t );
