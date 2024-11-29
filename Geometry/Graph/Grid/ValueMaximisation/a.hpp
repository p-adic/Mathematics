// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Grid/ValueMaximisation/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/1028604 (GridValueMaximisation)
// https://yukicoder.me/submissions/1028601 (CompressedGridValueMaximisation)

// ���͈͓͂̔���
// (1) U��M��operator<�Ɋւ��đS�������m�C�h���Ȃ��B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// H�~W�̃O���b�h���v�Ɋi�[���ꂽ�e(i,j,w)���Ƃ�(i,j)�ɉ��lw���^�����Ă���Ƃ��A
// (0,0)���琳�����Ɉړ�����ۂɒʂ钸�_�̉��l�́AM�̉��Z�Ɋւ��鑍��̍ő�l��
// O(H log W)�ŋ��߂�B
template <typename INT , typename U , typename MONOID> U AbstractGridValueMaximisation( MONOID M , const INT& W , const vector<tuple<INT,INT,U>>& v , const bool& skippable = true , const U& min_U = U() );
template <typename INT , typename U> inline U GridValueMaximisation( const INT& W , const vector<tuple<INT,INT,U>>& v , const bool& skippable = true , const U& min_U = U() );
template <typename INT , typename U> inline U CompressedGridValueMaximisation( const vector<tuple<INT,INT,U>>& v , const bool& skippable = true , const U& min_U = U() );

