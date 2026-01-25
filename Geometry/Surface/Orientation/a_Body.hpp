// c:/Users/user/Documents/Programming/Mathematics/Geometry/Surface/Orientation/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Graph/Algorithm/UnionFindForest/Potentialised/a_Body.hpp"
#include "../../../Utility/Tuple/Wrap/a_Body.hpp"
#include "../../../Utility/Vector/a_Body.hpp"

template <typename T>
pair<vector<vector<T>>,vector<bool>> Orientability( const vector<vector<T>>& faces )
{

  const int M = faces.size();
  Map<T2<int>,int> edge_num{};
  using path = Pair<int,bool>;
  // 面を頂点とし面の隣接関係を辺とし表裏をポテンシャルとするグラフを構築する。
  // vertex[k]に辺kを辺に持つ面たちの{面番号,面の向きから定まる辺の向き}を格納。
  vector<vector<path>> vertex{};
  // edge[m]に面mと接する面たちの{面番号,面の向きから定まる辺の向きが等しいか否か}を格納。
  vector<vector<path>> edge( M );

  for( int m = 0 ; m < M ; m++ ){

    assert( faces[m].size() == 3 );

    for( int i = 0 ; i < 2 ; i++ ){
      
      for( int j = i + 1 ; j < 3 ; j++ ){

        const T2<int> e{faces[m][i],faces[m][j]};

        if( In( e , edge_num ) ){

          auto& v = vertex[edge_num[e]];
          v <<= path{m,j-i<2};
          assert( v.size() <= 2 );

          for( int n = 0 ; n < 2 ; n++ ){

            edge[v[n][O]] <<= path{v[1-n][O],v[0][I]==v[1][I]};

          }
          
        } else {

          const int size = edge_num.size();
          edge_num[e] = size;
          vertex <<= vector{ path{m,j-i<2} };

        }
        
      }
      
    }
    
  }
  
  auto Edge = Get( edge );
  Graph graph{ M , Edge };
  auto neq = []( bool b0 , const bool& b1 ){ return move( b0 ^= b1 ); };
  bool unit = false;
  auto inverse = []( const bool& b ){ return b; };
  AbstractGroup Mod2{ neq , unit , inverse };
  AbstractPotentialisedUnionFindForest uff{ graph , Mod2 };
  return uff.Solvability();

}
