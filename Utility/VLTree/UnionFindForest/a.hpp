// c:/Users/user/Documents/Programming/Utility/VLTree/UnionFindForest/a.hpp

#pragma once
#include "Entry/a.hpp"
#include "../../LinkedVector/a.hpp"

template <typename T>
class UnionFindForest :
  public LinkedVector<EntryOfUnionFindForest<T> >
{

public:
  // EntryOfUnionFindForest<T>::m_node��VLSubTree<T>�^�ł���|�C���^�������o�Ɏ�����
  // �\�ߍő�v�f�����Œ肵�Ȃ��Ƃ����Ȃ��B
  inline UnionFindForest( const uint& max_size );

  // num�Ԗڂ�Node��Root�Ƃ��镔���؂��\�z����B
  inline const VLSubTree<T>& GetSubTree( const uint& num ) const;
  // num�Ԗڂ�Node��Predecessor Node��Ԃ��B
  inline const uint& GetPredecessorNode( const uint& num ) const;
  // num�Ԗڂ�Node��Root���v�Z���ĕԂ��B
  const uint& GetRootOfNode( const uint& num );
  // num�Ԗڂ�Root��Ԃ��B
  uint GetRoot( const uint& num ) const;

  // num�Ԗڂ�Node�Ɋi�[���ꂽ�l�ւ̎Q�Ƃ�Ԃ��B
  inline const T& operator[]( const uint& num ) const;
  inline T& operator[]( const uint& num );
  
  inline const uint& GetSizeOfNode() const noexcept;
  inline const uint& GetSizeOfRoot() const noexcept;

  // �ŏ��Ɏw�肵��max_size���GetSizeOfNode()���傫���ꍇ�̓T�|�[�g�O
  inline void push_RightMost();
  void push_RightMost( const T& t );
  template <typename... ARGS> inline void push_RightMost( const T& t , const ARGS&... args );

  inline void push_back() = delete;
  template <typename U> void push_back( const U& u ) = delete;
  template <typename U , typename... ARGS> inline void push_back( const U& u , const ARGS&... args ) = delete;
  inline void SetPreviousLink( const uint& i , const uint& j ) = delete;
  inline void SetNexttLink( const uint& i , const uint& j ) = delete;
  inline const uint& GetPreviousLinkIndex( const uint& i ) const = delete;
  inline const uint& GetNexttLinkIndex( const uint& i ) const = delete;
  const uint& DeLink( const uint& i ) = delete;
  void ReLink( const uint& i ) = delete;
  
  void Graft( const uint& num0 , const uint& num1 );
  
};
