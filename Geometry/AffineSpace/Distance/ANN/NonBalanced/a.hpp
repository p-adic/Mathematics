// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/ANN/NonBalanced/a.hpp

#pragma once

// D2��[0,��)��̍L�`�P�������֐��i2��Ȃǁjf��p����f(|x-z|)+f(|y-w|)�ƕ\����
// �d��d2�ɑ�������^�B

// S�̊e�_s��T�ɂ�����ŋߓ_���v�Z����B
template <typename Dist2 , typename INT>
vector<vector<int>> TwoDimensionalAllNearestNeighbourNonBalanced( const Dist2& d2 , const vector<pair<INT,INT>>& S , const vector<pair<INT,INT>>& T );
