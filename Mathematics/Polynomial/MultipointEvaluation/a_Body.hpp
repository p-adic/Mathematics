// c:/Users/user/Documents/Programming/Mathematics/Polynomial/MultipointEvaluation/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

// SetMultipointEvaluation�̕⏕�֐��B
// �ꎟ��M�̗񂪂P�i�[���ꂽproduct_tree�ɂ��̐ς̖؂𕪊������Ŋi�[����B�iO(M(log M)^2)�j
// begin�ő���ɃA�N�Z�X�ł���悤�ɂ��邽��V1��push_front�����K�v������B
template <typename T , template <typename...> typename V1 , template <typename...> typename V2 >
void SetProductTree( V1<V2<T> >& product_tree )
{

  V2<T> empty{};
  V2<T> *p_node = &( product_tree.back() );
  
  while( p_node->size() > 1 ){

    product_tree.push_front( empty );
    V2<T>& node_curr = product_tree.front();

    for( auto itr = p_node->begin() , end = p_node->end() ; itr != end ; itr++ ){

      static const T null{};
      node_curr.push_back( null );
      T& f = *itr;
      itr++;

      if( itr == end ){

	node_curr.back() = f;
	break;
	
      } else {
	
	node_curr.back() = f * *itr;

      }

    }

    p_node = &node_curr;

  }

  return;

}

// SetMultipointEvaluation�̕⏕�֐��B
// point�ɑΉ�����ꎟ��M�̐ς̖؂𕪊�������point_tree�Ɋi�[����B�iO(M(log M)^2)�j
// SetProductTree�̗v������V2��push_front�����K�v������B
template <typename T , template <typename...> typename V1 , template <typename...> typename V2 , template <typename...> typename V3>
void SetPointTree( const V1<T>& point , V2<V3<Polynomial<T> > >& point_tree )
{

  static const V3<Polynomial<T> > empty{};
  point_tree.push_front( empty );
  V3<Polynomial<T> >& linear = point_tree.front();

  for( auto itr = point.begin() , end = point.end() ; itr != end ; itr++ ){

    static const Polynomial<T> x{ 1 , Polynomial<T>::c_one() };
    linear.push_back( x );
    linear.back()[0] -= *itr;

  }

  SetProductTree( point_tree );
  return;
  
}

// SetMultipointEvaluation�̕⏕�֐��B
// point_tree�Ɋi�[���ꂽ�������̖؂ō����珇��f�̏�]�����߂�B�iO((D log D)+(M(log M)^2))�j
template <typename T , template <typename...> typename V1 , template <typename...> typename V2 , template <typename...> typename V3>
void SetPointTreeEvaluation( const Polynomial<T>& f , const V1<V2<Polynomial<T> > >& point_tree , V3<T>& answer )
{

  // �]���_�����̏ꍇ��point_tree�͋�łȂ����݂̂𐬕��Ɏ����Ƃɒ��ӁB
  assert( !point_tree.empty() );
  const V2<Polynomial<T> >& prod = point_tree.front();

  if( prod.empty() ){

    return;

  }

  list<Polynomial<T> > residue = {};
  const Polynomial<T>& zero = Polynomial<T>::zero();
  residue.push_back( zero );
  residue.back() = f % top.front();

  auto itr_tree = point_tree.begin() , end_tree = point_tree.end();
  itr_tree++;

  while( itr_tree != end_tree ){

    auto itr_residue = residue.begin() , end_residue = residue.end();
    auto itr_node = itr_tree->begin() , end_node = itr_tree->end();

    while( itr_residue != end_residue ){

      const Polynomial<T>& f = *itr_node;
      itr_node++;

      if( itr_node != end_node ){

	*( residue.insert( itr_residue , zero ) ) = *itr_residue % f;
	*itr_residue %= *itr_node;
	itr_node++;

      }
      
      itr_residue++;
      
    }

    itr_tree++;

  }
  
  for( auto itr_residue = residue.begin() , end_residue = residue.end() ; itr_residue != end_residue ; itr_residue++ ){

    answer.push_back( ( *itr_residue )[0] );

  }

  return;
  
}

template <typename T , template <typename...> typename V1 , template <typename...> typename V2> inline void SetMultipointEvaluation( const Polynomial<T>& f , const V1<T>& point , V2<T>& answer ) { list<list<Polynomial<T> > > pt{}; SetPointTree( point , pt ); SetPointTreeEvaluation( f , pt , answer ); }

template <typename T , template <typename...> typename V1 , template <typename...> typename V2>
void SetDifferenceProduct( const Polynomial<T>& f , const V1<T>& point , V2<T>& answer ){

  list<list<Polynomial<T> > > pt{};
  SetPointTree( point , pt );
  const list<Polynomial<T> >& top = pt.front();

  if( top.empty() ){

    return;

  }

  Polynomial<T> g{ Differential( 1 , top.front() ) };
  SetPointTreeEvaluation( g , pt , answer );
  return;

}

template <typename T , template <typename...> typename V1 , template <typename...> typename V2>
void SetPartialFractionDecomposition( const Polynomial<T>& f , const V1<T>& point , V2<T>& answer )
{

  assert( f.size() <= point.size() );
  list<list<Polynomial<T> > > pt{};
  SetPointTree( point , pt );
  const list<Polynomial<T> >& top = pt.front();

  if( top.empty() ){

    return;

  }

  Polynomial<T> g{ Differential( 1 , top.front() ) };
  list<T> r{};
  SetPointTreeEvaluation( f , pt , answer );
  SetPointTreeEvaluation( g , pt , r );

  auto itr1 = answer.begin() , end1 = answer.end();
  auto itr2 = r.begin();

  while( itr1 != end1 ){

    *( itr1++ ) /= *( itr2++ );

  }

  return;

}

template <typename T , template <typename...> typename V1 , template <typename...> typename V2>
void SetPartialFractionDecomposition( const uint& N , Polynomial<T> f , const V1<T>& point , V2<T>& answer )
{

  list<list<Polynomial<T> > > pt{};
  SetPointTree( point , pt );
  const list<Polynomial<T> >& top = pt.front();

  if( top.empty() ){

    return;

  }

  Polynomial<T> g{ top.front() };
  TruncatedPolynomial<T> fg{ point.size() + 1 , move( f ) };
  fg *= g;
  const Polynomial<T>& h = fg;
  answer.push_back( ( h / g )[0] );
  g = Differential( 1 , g );
  list<T> r{};
  SetPointTreeEvaluation( fg , pt , answer );
  SetPointTreeEvaluation( g , pt , r );

  auto itr1 = answer.begin() , end1 = answer.end();
  itr1++;
  auto itr2 = r.begin();

  while( itr1 != end1 ){

    *( itr1++ ) /= *( itr2++ );

  }

  return;

}

