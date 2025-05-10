// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Trie/a.hpp

#pragma once
#include "a_Macro.hpp"

// ���͈͓͂̔��ŗv��
// - M��U�̉��Q�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

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

template <typename U , typename ABEL_GROUP>
class TrieTree
{

private:
  ABEL_GROUP m_M;
  // m_count[node]��node�ԖڂɈ�����key��v�Ƃ���{v�ł̒l,v���n�ؕЂɎ���key�ł̒l�̑��a}���i�[�B
  vector<pair<U,U>> m_count;
  // m_edge[node][i]��node�ԖڂɈ�����key�̖�����i��}������key�����ԖڂɈ����������i�[�B
  vector<map<int,int>> m_edge;

public:
  inline TrieTree( ABEL_GROUP M );

  // v��key�Ƃ���u�����Z����B
  template <typename V> void insert( const V& v , const U& u );
  // v��key�Ƃ���l���폜����iM�̒P�ʌ��ɒu��������j�B
  template <typename V> inline void erase( const V& v );
  // v��key�Ƃ���u�����Z����B
  template <typename V> inline void erase( const V& v , const U& u );
  inline void clear();

  // �S�Ă�key���킽��l�̑��a��M�̒P�ʌ��ł��邩�̐^�U���擾����B
  inline bool empty() const noexcept;
  // �S�Ă�key���킽��l�̑��a���擾����B
  inline const U& size() const noexcept;
  // {v��key�Ƃ���l,v���n�ؕЂɎ���key�ł̒l�̑��a}
  template <typename V> pair<U,U> count( const V& v );

  // ��������M��operator<(const U&,const U&)�Ɋւ���S�������Q�\���ł���ꍇ�̂݃T�|�[�g�B

  // v���傫���l��M�̒P�ʌ��łȂ��ŏ���key�ɒu��������B
  void Increment( vector<int>& v ) const;
  // v��菬�����l��M�̒P�ʌ��łȂ��ŏ���key�ɒu��������B
  void Decrement( vector<int>& v ) const;

  // �l��M�̒P�ʌ��łȂ��ő��key���擾����B
  inline vector<int> Maximum();
  // �l��M�̒P�ʌ��łȂ��ŏ���key���擾����B
  inline vector<int> Minimum();

  // v�ȉ��Œl��M�̒P�ʌ��łȂ��ő��key��Ԃ��B
  template <typename V> vector<int> MaximumLeq( const V& v );
  // v�ȏ�Œl��M�̒P�ʌ��łȂ��ŏ���key��Ԃ��B
  template <typename V> vector<int> MinimumGeq( const V& v );

  // v��菬�����l��M�̒P�ʌ��łȂ��ő��key��Ԃ��B
  template <typename V> inline vector<int> MaximumLt( const V& v );
  // v���傫���l��M�̒P�ʌ��łȂ��ŏ���key��Ԃ��B
  template <typename V> inline vector<int> MinimumGt( const V& v );

  // v[i]=true�̎�i���ڂ̏����𔽓]������ŁA�l��M�̒P�ʌ��łȂ��ő��key���擾����B
  vector<int> ReversedMaximum( const vector<bool>& v );
  // v[i]=true�̎�i���ڂ̏����𔽓]������ŁA�l��M�̒P�ʌ��łȂ��ŏ���key���擾����B
  inline vector<int> ReversedMinimum( vector<bool> v );

  // �����܂�M��operator<(const U&,const U&)�Ɋւ���S�������Q�\���ł���ꍇ�̂݃T�|�[�g�B


  // �ekey�̎n�ؕ�v0��v1�ɁAv1��v0�ɒu��������B
  template <typename V> void swap( const V& v0 , const V& v1 );
  
  // v��M�i�@�ŗ�ɕϊ�����B
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
template <typename ABEL_GROUP> TrieTree( ABEL_GROUP ) -> TrieTree<inner_t<ABEL_GROUP>,ABEL_GROUP>;

// - �v�f�����Ǘ��������ꍇ
//   TrieTree trie( AdditiveGroup<int>() );
//   trie.insert( v , 1 );
//   trie.erase( v , 1 );
// - ���a���Ǘ��������ꍇ
//   TrieTree trie( AdditiveGroup<ll>() );
//   trie.insert( v , v );
//   trie.erase( v , v );
// - �v�f���Ƒ��a���Ǘ��������ꍇ
//   TrieTree trie( AdditiveGroup<Pair<int,ll>>() );
//   trie.insert( v , {1,v}} );
//   trie.erase( v , {1,v} );

