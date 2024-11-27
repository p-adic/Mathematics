// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Grid/ValueMaximisation/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/1015057 (CompressedGridValueMaximisation)

// DATA_STR��DualSqrtDecomposition�ȂǁB

// ���͈͓͂̔���
// (1) U��M��operator<�Ɋւ��đS�������m�C�h���Ȃ��B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// H�~W�̃O���b�h���v�Ɋi�[���ꂽ�e(i,j,w)���Ƃ�(i,j)�ɉ��lw���^�����Ă���Ƃ��A
// (0,0)����E����Ɉړ�����ۂɒʂ钸�_�̉��l�́AM�̉��Z�ϊւ��鑍��̍ő�l��
// O(H��W)��O(H log W)�ŋ��߂�B
template <typename INT , typename U , typename MONOID , template <typename...> typename DATA_STR> U AbstractGridValueMaximisation( MONOID M , const INT& W , const vector<tuple<INT,INT,U>>& v , const bool& skippable = false );
// ���a�̍ő�l��O(H��W)�ŋ��߂�B
template <typename INT , typename U> inline U GridValueMaximisation( const INT& W , const vector<tuple<INT,INT,U>>& v , const bool& skippable = false );
// ���a�̍ő�l��O(N log N + H��N)�ŋ��߂�B
template <typename INT , typename U> inline U CompressedGridValueMaximisation( const vector<tuple<INT,INT,U>>& v , const bool& skippable = false );

