// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Mex/Reversible/a.hpp

#pragma once

// �\�zO(QuerySize log QuerySize)
// �v�f����O(log QuerySize)
// �v�f�ǉ�O(log QuerySize)
// �v�f�폜O(log QuerySize)
// mex�擾O(1)

// QuerySize�͕�W���̏������ɂ̂ݕK�v�B�N�G����ǂ݂͕s�v�B

class ReversibleMexSet
{

private:
  int m_QuerySize;
  set<int> m_comp;
  set<int> m_over;

public:
  inline ReversibleMexSet( const int& QuerySize );

  inline int count( const int& i ) const;
  inline bool in( const int& i ) const;

  inline void insert( const int& i );
  inline void erase( const int& i );
  inline const int& mex() const;

};

