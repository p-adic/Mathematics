// c:/Users/user/Documents/Programming/Mathematics/Utility/String/Expand/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1130768
// https://yukicoder.me/submissions/1130767
// https://yukicoder.me/submissions/1130766

// �ȉ�S.size()��N�AS�̐����̕����񒷂̑��a��L�AS��trans�̍����̕����񒷂̍ő�l��L'�A
// source.size()��M�Aquery.size()��Q�ƒu���B
// query�̊e����{j,t,k}��k�̍ő�l��K�A�W�J�Œ�����K�𒴂���񐔂̍ő�l��T�ƒu���B
// - ��W�J�����̓W�J����W�J���𕡐��܂ނȂ��T��O(log_2 K)
// - �����łȂ��Ȃ��T��O(K/1�����̓W�J�ɂ�钷���̑���)

// ����
// (1) source�͊e�������قȂ�B
// (2) �C�ӂ�q<Q�ɑ΂��Aquery[q]={i,t,k}�Ƃ���S[i]��t��ϊ����{���ē����镶�����
//     ������k�ȏ�ł���B
// (3) �C�ӂ�q<Q�ɑ΂��Aquery[q]={i,t,k}�Ƃ���S[i]��source�ƕ��������L���A���̂悤�ȕ�����
//     S[i]�ł̍ō��̏o��������source[j]�Ƃ���ƁAS[trans[j]]��source�ƕ��������L���A
//     ���̂悤�ȕ�����S[trans[j]]�ł̍ō��̏o��������source[j]�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// source[j]��S[trans[j]]�ɒu��������ϊ����l����B
// �eq<Q�ɑ΂��Aquery[q]={i,t,k}�Ƃ���S[i]�ɕϊ���t��{���ē����镶�����k�����ځi1-indexed�j��
// answer[q]�ɋL�^����B(O(N+(L+T(L'+M^2))M+QM^2(log_2 L + T log_2 L')))
template <template <typename...> typename TUPLE> string ExpandRandomAccess( const vector<string>& S , const string& source , const vector<int>& trans , vector<TUPLE<int,ll,ll>> query );
// query[q]�̑�1������0�ɌŒ肵���o�[�W�����B
template <template <typename...> typename PAIR> inline string ExpandRandomAccess( const vector<string>& S , const string& source , const vector<int>& trans , const vector<PAIR<ll,ll>>& query );
