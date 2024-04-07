// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Divisor/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/970583�iCountDivisor�j


// PE��PrimeEnumeration����ꉻ���ē�����^�B

// O(��n)
template <typename INT> INT CountDivisor( const INT& n ) noexcept;
// sqrt( n )�ȉ��̍ő�̑f�� < val_limit �̎��̂݃T�|�[�g�B
// O(��n/(log n))
template <typename INT , typename PE> INT CountDivisor( const PE& pe , INT n ) noexcept;

// O(size log log size)
template <typename INT> vector<INT> GetLeastDivisor( const INT& size ) noexcept;

// O(��n)
template <typename INT> vector<int> EnumerateDivisor( INT n ) noexcept;
// sqrt( n )�ȉ��̍ő�̑f�� < val_limit �̎��̂݃T�|�[�g�B
// O(��n/(log n))
template <typename INT , typename PE> vector<INT> EnumerateDivisor( const PE& pe , INT n ) noexcept;
// O(d(n)) = O(log n / log log n)
template <typename INT1 , typename INT2> vector<INT2> EnumerateDivisor( const vector<INT1>& least_divisor , INT2 n ) noexcept;

// O(size log size)
template <typename INT> vector<vector<INT>> TotalEnumerateDivisor( const INT& size ) noexcept;

// O(��n)
template <typename INT> int MoeviusFunction( const INT& n ) noexcept;
// sqrt( n )�ȉ��̍ő�̑f�� < val_limit �̎��̂݃T�|�[�g�B
// O(��n/(log n))
template <typename PE> int MoeviusFunction( const PE& pe , INT n ) noexcept;
