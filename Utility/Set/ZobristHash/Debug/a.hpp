// c:/Users/user/Documents/Programming/Mathematics/Utility/Set/ZobristHash/Debug/a.hpp

#pragma once
#include "../a_Macro.hpp"

#include "../../Map/a.hpp"
#include "../a_Alias.hpp"

// デバッグ用にハッシュ値の型をSet<T>に変えたバージョン。

template <typename T>
class ZobristHashBody
{

protected:
  ull m_r;
  ull m_s;

public:
  inline ZobristHashBody();
  inline ZobristHashBody( const ull& r , const ull& s );

  Set<T> Encode( const Set<T>& S );
  template <template <typename...> typename V> inline Set<T> Encode( const V<T>& S , const bool& non_overlapping = false );

  // 集合の対称差
  inline Set<T> SymmetricDifference( Set<T> code0 , const Set<T>& code1 );
  // 要素追加（Sはcodeに対応する集合）
  inline Set<T> Add( Set<T>& S , Set<T> code , const T& t );
  // 要素削除（Sはcodeに対応する集合）
  inline Set<T> Erase( Set<T>& S , Set<T> code , const T& t );
  // 要素がある時は削除、ない時は追加
  inline Set<T> AddErase( Set<T> code , const T& t );
  
private:
  template <template <typename...> typename V> Set<T> OverlappingEncode( const V<T>& S );
  template <template <typename...> typename V> Set<T> NonOverlappingEncode( const V<T>& S );

};

// ullの集合のコーディング。

// 集合のコードO(要素数)
// リストの像のコードO(要素数 log 要素数)（無重複保証畤はO(要素数)）
// 配列の像のコードO(要素数 log 要素数)（無重複保証畤はO(要素数)）

// 集合の対称差O(1)
// 要素追加O(log要素数)
// 要素削除O(log要素数)
// 要素がある場合は削除、ない場合は追加O(1)
class ZobristHash :
  public ZobristHashBody<ull>
{

public:
  template <typename...Args> inline ZobristHash( Args&&... args );
  
};

// Tの集合のメモ化によるコーディング。

// 集合のコードO(要素数 log_size)
// リストの像のコードO(要素数(log 要素数)(log size))（無重複保証畤はO(要素数 log size)）
// 配列の像のコードO(要素数(log 要素数)(log size))（無重複保証畤はO(要素数 log size)）

// 集合の対称差O(1)
// 要素追加O((log要素数)(log size))
// 要素削除O((log要素数)(log size))
// 要素がある場合は削除、ない場合は追加O(log size)
template <typename T>
class MemorisationZobristHash :
  public ZobristHashBody<T>
{
 
public:
  template <typename...Args> inline MemorisationZobristHash( Args&&... args );
  
};

// Tの集合の数え上げによるコーディング。

// 集合のコードO(要素数)
// リストの像のコードO(要素数 log 要素数)（無重複保証畤はO(要素数)）
// 配列の像のコードO(要素数 log 要素数)（無重複保証畤はO(要素数)）

// 集合の対称差O(1)
// 要素追加O(log要素数)
// 要素削除O(log要素数)
// 要素がある場合は削除、ない場合は追加O(1)
template <typename T , int enum_T_inv(const T&)>
class EnumerationZobristHash :
  public ZobristHashBody<T>
{

public:
  template <typename...Args> inline EnumerationZobristHash( Args&&... args );

};

template <typename T> DECLARATION_OF_HASH( unordered_set<T> );
template <typename T> DECLARATION_OF_HASH( set<T> );
