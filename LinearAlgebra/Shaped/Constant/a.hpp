// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Shaped/Constant/a.hpp

#pragma once
#include "../../../Utility/Tuple/Wrap/a.hpp"

template <typename T , int NUM> class ShapedMatrix;

template <typename T , int NUM>
class ConstantsForShapedMatrix
{

  friend class ShapedMatrix<T,NUM>;

private:
  static int g_Y;
  // 0とは限らない列の添字区間[l,r]を行ごとに管理する。
  static vector<int> g_l;
  static vector<int> g_r;
  // r-l+1を管理する。
  static vector<int> g_d;
  // 乗算時に走査する添字の3つ組を管理する。
  static vector<T3<int>> g_mult;
  static T g_zero;

  ConstantsForShapedMatrix() = delete;
  
};

