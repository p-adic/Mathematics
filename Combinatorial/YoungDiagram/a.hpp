// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/YoungDiagram/a.hpp

#pragma once

// O(|type|)�Ńt�b�N�������ɂ��^type�̃����O�}�`�̌��𐔂��グ��B
template <typename INT1 , typename INT2 , template <typename...> typename V> void SetCountingYoundDiagram( INT1& answer , const V<INT2>& type );
