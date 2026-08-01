// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/MaxIntervalSum/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1174681 (PointedIntervalSumMax)

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
  // m_mis[i]に[0,i]を含む始切片和の最大値を格納する。
  vector<T> m_mis;
  // m_mfs[i]に[i,m_size)を含む終切片和の最大値を格納する。
  vector<T> m_mfs;

public:
  inline MaxIntervalSum( const vector<T>& A );

  inline const int& size() const noexcept;

  // [0,r]での始切片和を参照で返す。
  inline const T& InitialSegmentSum( const int& r ) const;
  // [l,m_size)での終切片和の最大値を参照で返す。
  inline const T& FinalSegmentSum( const int& l ) const;
  // [l,r]での区間和を返す。
  inline T IntervalSum( const int& l , const int& r ) const;

  // [0,i]を含む始切片和の最大値を参照で返す。
  inline const T& InitialSegmentSumMax( const int& i ) const;
  // [i,m_size)を含む終切片和の最大値を参照で返す。
  inline const T& FinalSegmentSumMax( const int& i ) const;
  // iを含む区間和の最大値を返す。
  inline T PointedIntervalSumMax( const int& i ) const;
  // 非空区間和の最大値を返す。
  inline T IntervalSumMax() const;
  
};
