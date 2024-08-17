// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/1002400

// �\�zO(1)
// ��_�}��O(log Q)
// ��_�폜O(log Q)
// ��_�A������O(log Q)
// ��_�A�������擾O(log Q)

template <typename INT>
class LineSubset
{

private:
  // ���[l,r]���Ƃ�m_l[r] = l�Ƃ��Ē����̕����W�����Ǘ�����B
  map<INT,INT> m_l;

public:
  void insert( const INT& i ) noexcept;
  void erase( const INT& i ) noexcept;

  inline int count( const INT& i ) const noexcept;
  bool find( const INT& i ) const noexcept;

  // i���܂ޘA��������Ԃ��B���݂��Ȃ��ꍇ��[1+1,i-1]��Ԃ��B
  pair<INT,INT> ConnectedComponentOf( const INT& i ) const noexcept;

  inline const map<INT,INT>& GetConnectedComponent() const noexcept;
  
};
