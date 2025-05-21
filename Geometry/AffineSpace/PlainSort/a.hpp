// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/PlainSort/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1087002 (ArgumentSort)

// �ی����v�Z����B�iO(1)�j
// ���������_��0�Ax����������1�Ay����������2�Ax����������3�Ay����������4�Ƃ���B
template <typename INT , template <typename...> typename PAIR> inline int Quadrant( const PAIR<INT,INT>& xy );

// centre���S��{�ی�,�Ίp,����,�Y���ԍ�}�Ń\�[�g����B
template <typename INT , template <typename...> typename PAIR> vector<int> ArgumentSort( const vector<PAIR<INT,INT>>& xy , const PAIR<INT,INT>& centre );

// xy_mid�����s������2L�͈̔͂̕��ʓ��̓_�Q���ċA�I��4�������ă\�[�g����B�iO(size log L)�j
template <typename INT , template <typename...> typename PAIR> vector<int> RecursiveDivisionSort( const vector<PAIR<INT,INT>>& xy , const PAIR<INT,INT>& xy_mid , const INT& L );
