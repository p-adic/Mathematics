// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/PartitionNumber/a.hpp

#pragma once

// n�ȉ��̔񕉐���i�𐳐����̏����a�ɕ���������@���i�����Ɋi�[����B�iO(n^2)�j
vector<int> PartitionNumber( const int& n );
// n�ȉ��̔񕉐���i��񕉐���l�̏����a�ɕ���������@���i�����Ɋi�[����B�iO(ln^2)�j
vector<int> NonNegativePartitionNumber( const int& n , const int& l );
