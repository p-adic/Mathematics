// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/DynamicModulo/Constant/a.hpp

#pragma once

template <int NUM> class DynamicMods;

template <int NUM>
class ConstantsForDynamicMods
{

  friend class DynamicMods<NUM>;
  
private:
  ConstantsForDynamicMods() = delete;
  static uint g_M;
  static constexpr const uint g_memory_bound = 2e6;
  static uint g_memory_length;
  static uint g_M_minus;
  static int g_order;
  static int g_order_minus;
  static bool g_M_is_prime;

};
