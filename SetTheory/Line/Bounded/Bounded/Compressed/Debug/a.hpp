// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Compressed/Debug/a.hpp

#pragma once

#include "../../Debug/a.hpp"
#include "../../../../../../Utility/Set/Map/a.hpp"

template <typename INT1 , typename INT2 , template <typename...> typename DATA_STR>
class AbstractCompressedSortedSet :
  virtual public VirtualBoundedLineSubset<INT1,INT2,const int&,const INT1&,DATA_STR>
{

protected:
  vector<INT1> m_sorted_coord;
  map<INT1,int> m_sorted_coord_inv;

public:
  inline AbstractCompressedSortedSet( const vector<INT>& query , const bool& output_mode = true );

private:
  inline bool InRange( const INT1& i );
  inline constexpr const int& Normalise( const INT1& i );
  inline constexpr const INT1& Denormalise( const int& d );

};

#include "../a_Alias.hpp"
