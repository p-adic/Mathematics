// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/SubSequence/ABCSubsequenceCounter/a_Body.hpp

#pragma once
#include "a.hpp"

template <int n , int AltB , int BltC>
ABCCount ABCSubsequenceCounterOperator<n,AltB,BltC>::Product( ABCCount v0 , const ABCCount& v1 )
{

  static_assert( n > 1 );
  auto& [v0A,v0AB,v0ABC] = v0;
  
  if( v0A.empty() ){

    return v1;

  }

  auto& [v1A,v1AB,v1ABC] = v1;

  if( v1A.empty() ){

    return move( v1 );

  }

  if( v0A.size() == 1 ){

    const int i = v0A[0];
    v0A = vector<int>( n );
    v0A[i]++;
    v0AB = vector( n , vector<ll>( n ) );

  }

  if( v1A.size() == 1 ){

    auto& k = v1A[0];

    for( int i = 0 ; i < n ; i++ ){

      const ll v0Ai = v0A[i];
      auto& v0ABi = v0AB[i];
      int j_min = 0 , j_ulim = n;

      if constexpr( AltB == 1 ){
        
        // A<BÇâ€Ç∑èÍçá
        j_min = i + 1;

      } else if constexpr( AltB == -1 ){
        
        // A>BÇâ€Ç∑èÍçá
        j_ulim = i;

      }
      
      for( int j = j_min ; j < j_ulim ; j++ ){

        if( j == i ){

          continue;

        }
        
        int k_min = 0 , k_ulim = n;

        if constexpr( BltC == 1 ){
        
          // B<CÇâ€Ç∑èÍçá
          k_min = j + 1;

        } else if constexpr( BltC == -1 ){
        
          // B>CÇâ€Ç∑èÍçá
          k_ulim = j;

        }

        if( k_min <= k && k < k_ulim && k != j ){

          v0ABC += v0ABi[j];

        }
      
      }

      if( j_min <= k && k < j_ulim && k != i ){

        v0ABi[k] += v0Ai;

      }

    }

    v0A[k]++;

  } else {

    v0ABC += v1ABC;
  
    for( int i = 0 ; i < n ; i++ ){

      const ll v0Ai = v0A[i];
      auto& v0ABi = v0AB[i];
      auto& v1ABi = v1AB[i];
      int j_min = 0 , j_ulim = n;

      if constexpr( AltB == 1 ){
        
        // A<BÇâ€Ç∑èÍçá
        j_min = i + 1;

      } else if constexpr( AltB == -1 ){
        
        // A>BÇâ€Ç∑èÍçá
        j_ulim = i;

      }

      for( int j = j_min ; j < j_ulim ; j++ ){

        if( j == i ){

          continue;

        }
        
        auto& v0ABij = v0ABi[j];
        auto& v1ABj = v1AB[j];
        int k_min = 0 , k_ulim = n;

        if constexpr( BltC == 1 ){
        
          // B<CÇâ€Ç∑èÍçá
          k_min = j + 1;

        } else if constexpr( BltC == -1 ){
        
          // B>CÇâ€Ç∑èÍçá
          k_ulim = j;

        }

        for( int k = k_min ; k < j ; k++ ){

          v0ABC += v0Ai * v1ABj[k] + v0ABij * v1A[k];

        }
      
        for( int k = j + 1 ; k < k_ulim ; k++ ){

          v0ABC += v0Ai * v1ABj[k] + v0ABij * v1A[k];

        }
      
      }

      if constexpr( AltB == 1 && BltC == 1 ){

        // A < B < CÇâ€Ç∑èÍçá
        j_min = i + 1 , j_ulim = n;
      
      } else if constexpr( AltB == -1 && BltC == -1 ){

        // A > B > CÇâ€Ç∑èÍçá
        j_min = 0 , j_ulim = i;

      } else {

        j_min = 0 , j_ulim = n;

      }

      for( int j = j_min ; j < i ; j++ ){

        v0ABi[j] += v1ABi[j] + v0Ai * v1A[j];
      
      }

      for( int j = i + 1 ; j < j_ulim ; j++ ){

        v0ABi[j] += v1ABi[j] + v0Ai * v1A[j];
      
      }

      v0A[i] += v1A[i];

    }

  }

  return move( v0 );

}

template <int n , int AltB , int BltC> inline ABCSubsequenceCounter<n,AltB,BltC>::ABCSubsequenceCounter() : AbstractMonoid<ABCCount,ABCCount(*)(ABCCount,const ABCCount&)>( ABCSubsequenceCounterOperator<n,AltB,BltC>::Product , ABCCount{} ) {}

template <int n> inline ABCCount ToABCCount( const int& c ) { return { { c } , {} , 0 }; }
template <int n> inline ABCCount ToABCCount( const char& c ) { return ToABCCount<n>( CharToInt( c ) ); }

template <int n , int AltB , template <typename...> typename VEC , typename INT>
ABCCount ToABCCount( const VEC<INT>& S )
{

  ABCSubsequenceCounter<n,AltB> M{};
  ABCCount answer{};

  for( auto& c : S ){
    
    answer = M.Product( move( answer ) , ToABCCount<n>( c ) );

  }
  
  return answer;

}
