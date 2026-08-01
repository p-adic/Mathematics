// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/MaxIntervalSum/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1174752 (PointedIntervalSumMax)

// 構築O(size)
// 始切片和最大値取得O(1)
// 終切片和最大値取得O(1)
// 基点付き区間和最大値取得O(1)
// 区間和最大値取得O(size)

template <typename T>
class MaxIntervalSum
{

private:
  int m_size;
  // m_is[r]に[0,r)での始切片和を格納する。
  vector<T> m_is;
  // m_fs[l]に[l,m_size)での終切片和を格納する。
  vector<T> m_fs;
  // m_mis[i]に[0,i)を含む始切片和（空でもよい）の最大値を格納する。
  vector<T> m_mis;
  // m_mfs[i]に[i,m_size)を含む終切片和（空でもよい）の最大値を格納する。
  vector<T> m_mfs;

public:
  inline MaxIntervalSum( const vector<T>& A );

  inline const int& size() const noexcept;

  // [0,r]での始切片和を参照で返す。
  inline const T& InitialSegmentSum( const int& r ) const;
  // [l,m_size)での終切片和を参照で返す。
  inline const T& FinalSegmentSum( const int& l ) const;
  // [l,r]での区間和を返す。
  inline T IntervalSum( const int& l , const int& r ) const;

  // [0,r]を含む始切片和（空でもよい）の最大値を参照で返す。
  inline const T& InitialSegmentSumMax( const int& r ) const;
  // [l,m_size)を含む終切片和（空でもよい）の最大値を参照で返す。
  inline const T& FinalSegmentSumMax( const int& l ) const;
  // [0,r]に含まれる始切片和（空でもよい）の最小値を返す。
  inline T InitialSegmentSumMin( const int& r ) const;
  // [l,m_size)に含まれる終切片和（空でもよい）の最小値を返す。
  inline T FinalSegmentSumMin( const int& l ) const;
  // [l,r]の形の非空区間和の最大値を返す。
  inline T RightPointedIntervalSumMax( const int& r ) const;
  inline T LeftPointedIntervalSumMax( const int& l ) const;
  // iを含む区間和の最大値を返す。
  inline T PointedIntervalSumMax( const int& i ) const;
  // answer[i]に、[0,i]に含まれる非空区間和の最大値を格納する。
  inline vector<T> IntervalSumMax() const;
  
};
