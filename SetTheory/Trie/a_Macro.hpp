// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Trie/a_Macro.hpp

#pragma once

#define DEFINITION_OF_SEARCH_IN_TRIE_TREE( NEW_EDGE , UPDATE_COUNT_IS , UPDATE_COUNT ) \
  int node = 0;                                                         \
  UPDATE_COUNT_IS;                                                      \
                                                                        \
  for( auto& i : ToArray( v ) ){                                        \
                                                                        \
    assert( i >= 0 );                                                   \
    auto& edge = m_edge[node];                                          \
                                                                        \
    if( edge.count( i ) == 0 ){                                         \
                                                                        \
      NEW_EDGE;                                                         \
                                                                        \
    } else {                                                            \
                                                                        \
      node = edge[i];                                                   \
                                                                        \
    }                                                                   \
                                                                        \
    UPDATE_COUNT_IS;                                                    \
                                                                        \
  }                                                                     \
                                                                        \
  UPDATE_COUNT;                                                         \

