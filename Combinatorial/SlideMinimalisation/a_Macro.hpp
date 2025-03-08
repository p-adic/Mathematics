// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/SlideMinimalisation/a_Macro.hpp

#pragma once

#define DECLARATION_OF_SLIDE_MIMALISATION( MIN )                        \
  template <typename INT> vector<INT> Slide ## MIN ## imalisation( const vector<INT>& a , const int& interval_size ) \

#define DEFINITION_OF_SLIDE_MIMALISATION( MIN , OPR )                   \
  template <typename INT>                                               \
  vector<INT> Slide ## MIN ## imalisation( const vector<INT>& a , const int& interval_size ) \
  {                                                                     \
                                                                        \
    const int size = a.size();                                          \
    vector<INT> answer( size );                                         \
                                                                        \
    if( 0 < interval_size && interval_size <= size ){                   \
                                                                        \
      list<pair<INT,int>> interval{};                                   \
                                                                        \
      for( int i = 0 ; i < interval_size - 1 ; i++ ){                   \
                                                                        \
        while( !interval.empty() && interval.back().first OPR a[i] ){   \
                                                                        \
          interval.pop_back();                                          \
                                                                        \
        }                                                               \
                                                                        \
        interval.push_back( {a[i],i} );                                 \
                                                                        \
      }                                                                 \
                                                                        \
      for( int i = interval_size - 1 ; i < size ; i++ ){                \
                                                                        \
        while( !interval.empty() && interval.back().first > a[i] ){     \
                                                                        \
          interval.pop_back();                                          \
                                                                        \
        }                                                               \
                                                                        \
        interval.push_back( {a[i],i} );                                 \
        auto& [x,j] = interval.front();                                 \
        answer[i] = x;                                                  \
                                                                        \
        if( j == i - interval_sum + 1 ){                                \
                                                                        \
          interval.pop_front();                                         \
                                                                        \
        }                                                               \
                                                                        \
      }                                                                 \
                                                                        \
    }                                                                   \
                                                                        \
    return answer;                                                      \
                                                                        \
  }                                                                     \
