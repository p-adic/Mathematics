// c:/Users/user/Documents/Programming/Mathematics/Polynomial/MultipointEvaluation/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/937654�i���_�]���j

// �ȉ��A������D�Ƃ��A�����ł��؂�]���_�̌���M�Ƃ���B

// SetPartialFractionDecomposition�ŋ�łȂ���������ɑ��_�]���̒l��push_back����̂�
// SetMultipointEvaluation��vector<T>��Ԃ��֐��ɂ��Ȃ��B

// point�̊e����p�ɑ΂���f(p)�̒l��answer�Ɋi�[����B�iO((D log D)+(M(log M)^2))�j
template <typename T , template <typename...> typename V1 , template <typename...> typename V2> inline void SetMultipointEvaluation( const Polynomial<T>& f , const V1<T>& point , V2<T>& answer );

// �ep�ɑ΂���i�����Ȃ��j���σ�_{p' in point-{p}}(p-p')���v�Z����B�iO(M(log M)^2)�j
template <typename T , template <typename...> typename V1 , template <typename...> typename V2> void SetDifferenceProduct( const V1<T>& point , V2<T>& answer );

// point�ɏd�����Ȃ�����D<M�ł���ꍇ��f(x)/��(x-p)�̕�������������1/(x-p)�̌W����
// answer�Ɋi�[����B�iO((D log D)+(M(log M)^2)) = O(M(log M)^2)�j
template <typename T , template <typename...> typename V1 , template <typename...> typename V2> void SetPartialFractionDecomposition( const Polynomial<T>& f , const V1<T>& point , V2<T>& answer );
// point�ɏd�����Ȃ��ꍇ��f(x) �� h(x)/��(x-p) mod x^{M+1}����deg(h(x)) <= M�𖞂����B���
// ������h(x)�ɑ΂���h(x)/��(x-p)�̕������������̒萔����1/(x-p)�̌W����answer�Ɋi�[����B
// �iO(D + M(log M)^2)�j
template <typename T , template <typename...> typename V1 , template <typename...> typename V2> void SetPartialFractionDecomposition( const uint& N , Polynomial<T> f , const V1<T>& point , V2<T>& answer );
