// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/ANN/a.hpp

#pragma once

// https://www.cs.umd.edu/gvil/papers/jagan_CG07.pdf �̃A�C�f�A���ȗ����B
// �i�u���b�N��locality�͍l�����ɓ_��locality�𒼐ڕ��}����@�Ōv�Z�j

// D2��[0,��)��̍L�`�P�������֐��i2��Ȃǁjf��p����f(|x-z|)+f(|y-w|)�ƕ\����
// �d��d2�ɑ�������^�B

// S�̊e�_s��S-{s}�ɂ�����ŋߓ_���v�Z����B
template <typename Dist2 , typename INT> vector<vector<int>> TwoDimensionalAllNearestNeighbour( const Dist2& d2 , const vector<pair<INT,INT>>& S );

// S�̊e�_s��T�ɂ�����ŋߓ_���v�Z����B
template <typename Dist2 , typename INT> vector<vector<int>> TwoDimensionalAllNearestNeighbour( const Dist2& d2 , const vector<pair<INT,INT>>& S , const vector<pair<INT,INT>>& T );
