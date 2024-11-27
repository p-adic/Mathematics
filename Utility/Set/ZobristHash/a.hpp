// c:/Users/user/Documents/Programming/Utility/Set/ZobristHash/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/942404�i�Ώ̍��j

#include "../Mathematics/Function/Map/a.hpp"
#include "a_Alias.hpp"

template <typename T>
class ZobristHashBody
{

protected:
  ull m_hash;

public:
  inline ZobristHashBody( const ull& hash );

  ull Encode( const set<T>& S );
  template <template <typename...> typename V> inline ull Encode( const V<T>& S , const bool& non_overlapping = false );

  inline ull SymmetricDifference( const ull& code0 , const ull& code1 );
  inline ull Add( set<T>& S , const ull& code , const T& t );
  inline ull Erase( set<T>& S , const ull& code , const T& t );
  inline ull AddErase( const ull& code , const T& t );
  
private:
  template <template <typename...> typename V> ull OverlappingEncode( const V<T>& S );
  template <template <typename...> typename V> ull NonOverlappingEncode( const V<T>& S );
  virtual ull Hash( const T& t ) = 0;

};

// �W���̃R�[�hO(�v�f��)
// ���X�g�̑��̃R�[�hO(�v�f�� log �v�f��)�i���d���ۏ��^��O(�v�f��)�j
// �z��̑��̃R�[�hO(�v�f�� log �v�f��)�i���d���ۏ��^��O(�v�f��)�j

// �W���̑Ώ̍�O(1)
// �v�f�ǉ�O(log�v�f��)
// �v�f�폜O(log�v�f��)
// �v�f������ꍇ�͍폜�A�Ȃ��ꍇ�͒ǉ�O(1)
class ZobristHash :
  public ZobristHashBody<ull>
{

public:
  inline ZobristHash( const ull& hash = 14177381365537266759ULL );
  
private:
  inline ull Hash( const ull& t );

};

// �W���̃R�[�hO(�v�f�� log_size)
// ���X�g�̑��̃R�[�hO(�v�f��(log �v�f��)(log size))�i���d���ۏ��^��O(�v�f�� log size)�j
// �z��̑��̃R�[�hO(�v�f��(log �v�f��)(log size))�i���d���ۏ��^��O(�v�f�� log size)�j

// �W���̑Ώ̍�O(1)
// �v�f�ǉ�O((log�v�f��)(log size))
// �v�f�폜O((log�v�f��)(log size))
// �v�f������ꍇ�͍폜�A�Ȃ��ꍇ�͒ǉ�O(log size)
template <typename T>
class MemorisationZobristHash :
  public ZobristHashBody<T>
{

private:
  Map<T,ull> m_f;
  
public:
  inline MemorisationZobristHash( const ull& hash = 14177381365537266759ULL );
  
private:
  inline ull Hash( const T& t );

};

// �W���̃R�[�hO(�v�f��)
// ���X�g�̑��̃R�[�hO(�v�f�� log �v�f��)�i���d���ۏ��^��O(�v�f��)�j
// �z��̑��̃R�[�hO(�v�f�� log �v�f��)�i���d���ۏ��^��O(�v�f��)�j

// �W���̑Ώ̍�O(1)
// �v�f�ǉ�O(log�v�f��)
// �v�f�폜O(log�v�f��)
// �v�f������ꍇ�͍폜�A�Ȃ��ꍇ�͒ǉ�O(1)
template <typename T , int enum_T_inv(const T&)>
class EnumerationZobristHash :
  public ZobristHashBody<T>
{

public:
  inline EnumerationZobristHash( const ull& hash = 14177381365537266759ULL );
  
private:
  inline ull Hash( const T& t );

};

