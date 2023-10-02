// c:/Users/user/Documents/Programming/Utility/Set/Mex/Reversible/a.hpp

#pragma once


// �\�zO(QuerySize log QuerySize)
// �v�f����O(log QuerySize)
// �v�f�ǉ�O(log QuerySize)
// �v�f�폜O(log QuerySize)
// mex�擾O(1)
class ReversibleMexSet
{

private:
  int m_QuerySize;
  set<int> m_comp;
  set<int> m_over;

public:
  inline ReversibleMexSet( const int& QuerySize );

  inline bool in( const int& i ) const;
  inline void insert( const int& i );
  inline void erase( const int& i );
  inline const int& Get() const;

};

