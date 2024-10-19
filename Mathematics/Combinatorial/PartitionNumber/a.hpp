// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/PartitionNumber/a.hpp

#pragma once
// verify:
// PartitionNumber��python�� (https://yukicoder.me/submissions/1021227)
// UpperBoundedPartitionNumber (https://yukicoder.me/submissions/1021223)


// n�ȉ��̔񕉐���i�𐳐����̏����a�ɕ����������answer[i]�Ɋi�[����B�iO(n^2)�j
template <typename INT> vector<INT> PartitionNumber( const int& n );
// n�ȉ��̔񕉐���i��j�ȏ�̐������̏����a�ɕ����������answer[i][j]�Ɋi�[����B�iO(n^2)�j
template <typename INT> vector<vector<INT>> LowerBoundedPartitionNumber( const int& n );
// n�ȉ��̔񕉐���i��j�ȉ��̐������̏����a�ɕ����������answer.first[i][j]�Ɋi�[����B�iO(n^2)�j
template <typename INT> vector<vector<INT>> UpperBoundedPartitionNumber( const int& n );
// n�ȉ��̔񕉐���i��񕉐���j�̏����a�ɕ����������
// n�ȉ��̔񕉐���i�𐳐���j�ȉ��̏����a�ɕ���������Ƃ��������B

