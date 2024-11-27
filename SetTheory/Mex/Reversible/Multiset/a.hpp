// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Mex/Reversible/Multiset/a.hpp

#pragma once

// �\�zO(QuerySize log QuerySize)
// �v�f����O(log QuerySize)
// �v�f�ǉ�O(log QuerySize)
// �v�f�폜O(log QuerySize)
// mex�擾O(1)

// QuerySize�͕�W���̏������ɂ̂ݕK�v�B�N�G����ǂ݂͕s�v�B

class ReversibleMexMultiset
{

private:
  int m_QuerySize;
  set<int> m_comp;
  map<int,int> m_mult;

public:
  inline ReversibleMexMultiset( const int& QuerySize );

  inline int count( const int& i ) const;
  inline bool in( const int& i ) const;

  inline void insert( const int& i );
  inline void erase( const int& i );
  inline const int& mex() const;

};

