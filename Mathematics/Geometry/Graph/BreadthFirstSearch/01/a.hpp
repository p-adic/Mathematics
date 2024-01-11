// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/01/a.hpp

#pragma once
#include "../a.hpp"

// verify: https://yukicoder.me/submissions/942784

template <typename E>
class ZeroOneBreadthFirstSearch
{

protected:
  int m_V;
  E m_e;
  int m_init;
  list<int> m_next;

  // 0:���ڑ��A1:�O�ɐڑ��A2:���ɐڑ��A3:�T���ς�
  vector<int> m_found;
  vector<int> m_prev;
  vector<int> m_weight;
  
public:
  inline ZeroOneBreadthFirstSearch( const int& V , E e );
  inline ZeroOneBreadthFirstSearch( const int& V , E e , const int& init );

  // m_found��m_prev��m_weight��������
  inline void Reset( const int& init );
  // m_found��m_prev��m_weight��񏉊���
  inline void Shift( const int& init );

  inline const int& size() const;
  inline const int& init() const;
  inline int& found( const int& i );
  inline const int& prev( const int& i ) const;
  inline const int& weight( const int& i ) const;

  int Next();

  // Next()�̔�����m_init���瓞�B�\�Ȓ��_��S�T���B
  // �v�Z��O((m_init�̘A������)+(m_init�̘A�������ɂ�����E�̃T�C�Y�̍��v))
  inline void SetWeight();

  // Next()�̔�����init����goal�܂ł̍ŒZ�o�H��T���B
  // �v�Z��O((init�̘A������)+(m_init�̘A�������ɂ�����E�̃T�C�Y�̍��v))
  inline const int& Solve( const int& init , const int& goal );

};
