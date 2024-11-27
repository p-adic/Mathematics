// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/UnionFindForest/Kruscal/a.hpp

#pragma once
#include "../../../a.hpp"

// verify:
// https://yukicoder.me/submissions/957499

// GRAPH�͗L���O���tG=(V_G,E_G)�ɑ�������^�B
// ��������E�͎ʑ�T -> ( T \times U \times int \times ... )^{< \omega}�ɑ������A
// ���̒l�̑�3�����͕Ӕԍ���\���B

// ���͈͓͂̔��ŗv��
// (1) U��bool operator<(const U&,const U&)�Ɋւ��đS�����ł���B
// (2) E��E_G�̔ԍ��t���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// O(|E_G|(��(|V_G| + log_2 |E_G|)))��G�̖������́Aanswer�ɑΉ�����ӏW�����܂ޑS��X�̂���
// �d�݁i��<�Ɋւ��đS�������m�C�h���Ȃ������m�C�h�\���Ɋւ��鑍�a�j���ŏ��ȑS��X��
// {�Ӕԍ��̔z��,�A�������̌�}��Ԃ��B
// ���̂悤�ȑS��X�����݂��Ȃ��ianswer���H���܂ށj�ꍇ��{answer,-1}��Ԃ��B
template <typename GRAPH> inline pair<vector<int>,int> Kruscal( GRAPH& G , const vector<pair<int,int>>& E , vector<int> answer = {} );

// On��E_G��{0,1}�ʐFon:int�i�Ӕԍ��j-> {0,1}�ɑ�������^�B

// ���͈͓͂̔��ŗv��
// (1) E_sorted��E_G��U�̏����Ɋւ��ă\�[�g�������̂ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// O(|E_G| ��(|V_G|))��on��1�ɐF�t�������G�̕ӂ݂̂���Ȃ镔���O���t�̖������́A
// answer�ɑΉ�����ӏW�����܂ޑS��X�̂����d�݁i��<�Ɋւ��đS�������m�C�h���Ȃ�
// �����m�C�h�\���Ɋւ��鑍�a�j���ŏ��ȑS��X��{�Ӕԍ��̔z��,�A�������̌�}��Ԃ��B
// ���̂悤�ȑS��X�����݂��Ȃ��ianswer���H���܂ނ�0�ɐF�t�������ӂ��܂ށj�ꍇ��
// {answer,-1}��Ԃ��B
template <typename On> pair<vector<int>,int> Kruscal( const int& V , const vector<pair<int,int>>& E , const list<tuple<int,int,int>>& E_sorted , const On& on , vector<int> answer = {} );
