// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/ANN/Randomised/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename Dist2 , typename INT>
vector<vector<int>> TwoDimensionalAllNearestNeighbourRandomised( const Dist2& d2 , const vector<pair<INT,INT>>& S , const vector<pair<INT,INT>>& T , const int& bucket_size , const int& success_count_bound )
{

  DEFINITION_OF_RANDOMISED_ANN( int success_count = 0 , success_count++ < success_count_bound , success_count = 0 );

}

template <typename Dist2 , typename INT>
vector<vector<int>> TwoDimensionalAllNearestNeighbourRandomised( const Dist2& d2 , const vector<pair<INT,INT>>& S , const vector<pair<INT,INT>>& T , const int& bucket_size , const double& time )
{

  DEFINITION_OF_RANDOMISED_ANN( chrono::system_clock::time_point watch = chrono::system_clock::now() , static_cast<double>( chrono::duration_cast<chrono::microseconds>( chrono::system_clock::now() - watch ).count() / 1000.0 ) < time , );

}
