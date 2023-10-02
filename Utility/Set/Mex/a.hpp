// c:/Users/user/Documents/Programming/Utility/Set/Mex/a.hpp

#pragma once

// �\�zO(QuerySize)
// �v�f�ǉ�O(1)
// mex�擾�N�G�����vO(QuerySize)
class MexSet
{

private:
  int m_QuerySize;
  vector<bool> m_in;
  int m_mex;

public:
  inline MexSet( const int& QuerySize );
  
  inline void insert( const int& i );
  inline const int& Get() const noexcept;

};

template <typename T , template <typename...> typename V , V<T> E(const T&)>
const int& GrundyNumber( const T& t );
