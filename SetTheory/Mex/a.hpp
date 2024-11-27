// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Mex/a.hpp

#pragma once

// �\�zO(QuerySize)
// �v�f�ǉ�O(1)
// mex�擾�N�G�����vO(QuerySize)

// QuerySize�͕�W���̏������ɂ̂ݕK�v�B�N�G����ǂ݂͕s�v�B
// �v�f�ǉ�O(1)���������邽�߂�QuerySize�ȊO�̗v�f�𖳎�����̂�
// count��in�͎����Ȃ��B����炪�K�v�ȏꍇ��ReversibleMexSet���g���B

class MexSet
{

private:
  int m_QuerySize;
  vector<bool> m_in;
  int m_mex;

public:
  inline MexSet( const int& QuerySize );

  inline void insert( const int& i );

  inline const int& mex() const noexcept;

};
