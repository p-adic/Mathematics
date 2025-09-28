// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Combination/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1123395 (CombinationFactorialValuative, MOD=443*2253371)
// https://atcoder.jp/contests/abc425/submissions/69702053 (CombinationFactorialValuative, MOD���)
// https://yukicoder.me/submissions/1082026 (CombinationCumulativeProduct, RET=MP)


// ���INT1,INT2,INT��int��ll��z�肵�Ă��邪�A�v���𖞂�����Mod��DynamicMod�Ȃǂł��ǂ��B
// �Ⴆ��CombinationCumulativeProduct��n,m�����Mod::Combination��荂���ɂȂ�B
// - int��ll�̎��̓I�[�o�[�t���[�����邱�Ƃɒ��ӁB
// - Mod�͖@p���f���łȂ���/�̌v�Z������Ȃ����Ƃɒ��ӁB
// - DyamicMod��SetModulo��is_prime=true��n�������̂�/���������ċA��O(1)�Ōv�Z����A
//   ��ʂɂ�/�����[�N���b�h�̌ݏ��@��O(log_2 n)�Ōv�Z����邱�Ƃɒ��ӁB

// �v��
// (1) INT1��[1,min(m,n-m)]�̗v�f�ɂ�鏤�����s�ł���B
// �̂��Ƃŋς�O(1)�in���Ƃɍ��vO(min(m,n-m))�j�ŐςƏ��̔����ɂ��v�Z���������ċA����B
template <typename RET , typename INT1 , typename INT2> inline RET CombinationCumulativeProduct( const INT1& n , INT2 m , const bool& reset = false );

// �v��
// (1) factor�͑��قȂ�f���̗�i������L�ƒu���j�ł���B
// (2) MOD��factor�̐�㰂̐ς�@�Ƃ��鐮���̌^�ł���B
// �̂��Ƃŋς�O(L)�i�O�v�ZO(log n)�An���Ƃɍ��vO(min(m,n-m)log MOD)�j��
// �ςƏ��̔����ɂ��v�Z���������ċA����B
template <typename MOD , typename INT1 , typename INT2 , typename VEC> inline pair<MOD,vector<int>> CombinationCumulativeProductValuative( const INT1& n , INT2 m , const VEC& factor , const bool& reset = false );

// �v��
// (1) INT1��[1,min(m,n-m)]�̗v�f�̊K��ɂ�鏤�����s�ł���B
// (2) INT1��int��uint�Ȃ��n<=12�All��ull�Ȃ��n<=20�ł���B
// �̂��Ƃ�O(1)�i�O�v�ZO(n)�j�ŊK���p���Čv�Z����B
template <typename INT1 , typename INT2> inline INT1 CombinationFactorial( const INT1& n , INT2 m );

// �v��
// (1) factor�͑��قȂ�f���̗�i������L�ƒu���j�ł���B
// (2) MOD��factor�̐�㰂̐ς�@�Ƃ��鐮���̌^�ł���B
// �̂��Ƃő����W����O(L(1+m.size()))�i�O�v�ZO(n log MOD)�j�ŊK���p���Čv�Z����B
template <typename MOD , typename INT1 , typename INT2 , typename VEC> inline pair<MOD,vector<int>> CombinationFactorialValuative( const INT1& n , const vector<INT2> m , const VEC& factor , const int& euler );
template <typename MOD , typename INT1 , typename INT2 , typename VEC> inline pair<MOD,vector<int>> CombinationFactorialValuative( const INT1& n , INT2 m , const VEC& factor , const int& euler );
// valutaive�͈ȉ��ƕ��p����B
// auto [factor,exponent] = PrimeFactorisation( pe , mod );
// �ŏI�I�ȓ����͈ȉ��̂悤�ɎZ�o����B
// auto [a,val] = CombinationFactorialValuative<MOD>( n , m , factor );
// FOR( i , 0 , L ){
//   a *= PowerMemorisation( MOD{ factor[i] } , val[i] );
//   // a *= Power( MOD{ factor[i] } , val[i] );
// }
