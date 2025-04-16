// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Trie/a.hpp

#pragma once
#include "a_Macro.hpp"

// �ȉ������̎�ސ���S�A�����̏����L�A�v�f����N�ƒu���B

// �\�zO(1)

// �S�v�f���擾O(1)

// �v�f�}��O(L log S)
// �v�f�폜O(L log S)
// ����̒l�ɓ������v�f���^����̒l���n�ؕЂɎ��v�f���擾O(L log S)

// �v�f�̃C���N�������g�A�ς�O(L)
// �v�f�̃f�B�N�������g�A�ς�O(L)

// �ő�v�f�擾�A�ς�O(L log S)
// �ŏ��v�f�擾�A�ς�O(L log S)
// �����̈�������l

template <typename INT = int>
class TrieTree
{

private:
  vector<pair<INT,INT>> m_count;
  vector<map<int,int>> m_edge;

public:
  inline TrieTree();

  template <typename V> void insert( const V& v , const INT& count = 1 );
  template <typename V> inline void erase( const V& v );
  template <typename V> void erase( const V& v , const INT& count );
  inline void clear();

  inline bool empty() const noexcept;
  inline const INT& size() const noexcept;
  // {v�Ɠ������v�f�̌�,v���n�ؕЂɎ��v�f�̌�}
  template <typename V> pair<INT,INT> count( const V& v );

  void Increment( vector<int>& v ) const;
  void Decrement( vector<int>& v ) const;

  inline vector<int> Maximum();
  inline vector<int> Minimum();

  template <typename V> vector<int> MaximumLeq( const V& v );
  template <typename V> vector<int> MinimumGeq( const V& v );

  template <typename V> inline vector<int> MaximumLt( const V& v );
  template <typename V> inline vector<int> MinimumGt( const V& v );

  // v[i]=true�̎��Ai���ڂ̏����𔽓]����B
  vector<int> ReversedMaximum( const vector<bool>& v );
  inline vector<int> ReversedMinimum( vector<bool> v );

  static vector<int> ToArray( ll v , const int& M );
  static vector<int> ToArray( ll v , const int& M , const int& L );

private:
  static const vector<int>& ToArray( const vector<int>& v );
  static inline vector<int> ToArray( const char* const& v );
  template <typename V> static vector<int> ToArray( const V& v );

  template <typename RANGE> void SetNextNode( const map<int,int>& edge , vector<int>& answer , int& node , RANGE range ) const;

  template <typename SEARCH , typename RANGE> void SetMaximum_Body( vector<int>& answer , int& node , SEARCH search , RANGE range ) const;
  inline void SetMaximum( vector<int>& answer , int& node ) const;
  inline void SetMinimum( vector<int>& answer , int& node ) const;

  template <typename RANGE> void SetMaximumLeq_Body( const vector<int>& v , vector<int>& answer , int& node , bool& lt , RANGE range ) const;

};
