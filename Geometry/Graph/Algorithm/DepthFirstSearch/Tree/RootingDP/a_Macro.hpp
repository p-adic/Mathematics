// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/RootingDP/a_Macro.hpp

#pragma once

#ifndef RET_TYPE
  #define RET_TYPE
  template <typename F , typename...Args> using ret_t = decltype( declval<F>()( declval<Args>()... ) );
#endif


