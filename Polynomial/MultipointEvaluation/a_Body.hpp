// c:/Users/user/Documents/Programming/Mathematics/Polynomial/MultipointEvaluation/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

// SetMultipointEvaluationの補助関数。
// 一次式M個の列が１つ格納されたproduct_treeにその積の木を分割統治で格納する。（O(M(log M)^2)）
// beginで総乗にアクセスできるようにするためV1はpush_frontを持つ必要がある。
template <typename T , template <typename...> typename V1 , template <typename...> typename V2>
void SetProductTree( V1<V2<T> >& product_tree )
{

  V2<T> *p_node = &( product_tree.back() );
  
  while( p_node->size() > 1 ){

    V2<T> node{};

    for( auto itr = p_node->begin() , end = p_node->end() ; itr != end ; itr++ ){

      node.push_back( T{} );
      T& f = *itr;
      itr++;

      if( itr == end ){

	node.back() = f;
	break;
	
      } else {
	
	node.back() = f * *itr;

      }

    }

    product_tree.push_front( move( node ) );
    p_node = &( product_tree.front() );

  }

  return;

}

// SetMultipointEvaluationの補助関数。
// pointに対応する一次式M個の積の木を分割統治でpoint_treeに格納する。（O(M(log M)^2)）
// SetProductTreeの要件からV2はpush_frontを持つ必要がある。
template <typename T , template <typename...> typename V1 , template <typename...> typename V2 , template <typename...> typename V3>
void SetPointTree( const V1<T>& point , V2<V3<Polynomial<T> > >& point_tree )
{

  const Polynomial<T>& x = Polynomial<T>::x();
  V3<Polynomial<T> > linear{};

  for( auto& p : point ){

    linear.push_back( x - Polynomial<T>( p ) );

  }

  point_tree.push_front( move( linear ) );
  SetProductTree( point_tree );
  return;
  
}

// SetMultipointEvaluationの補助関数。
// point_treeに格納された多項式の木で根から順にfの剰余を求める。（O((D log D)+(M(log M)^2))）
template <typename T , template <typename...> typename V1 , template <typename...> typename V2 , template <typename...> typename V3>
void SetPointTreeEvaluation( const Polynomial<T>& f , const V1<V2<Polynomial<T> > >& point_tree , V3<T>& answer )
{

  // 評価点が空列の場合もpoint_treeは空でなく空列のみを成分に持つことに注意。
  assert( !point_tree.empty() );
  const V2<Polynomial<T> >& prod = point_tree.front();

  if( prod.empty() ){

    return;

  }

  const Polynomial<T>& zero = Polynomial<T>::zero();
  auto itr_tree = point_tree.begin() , end_tree = point_tree.end();
  list<Polynomial<T> > residue = { f % itr_tree->front() };
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
  
  for( auto& f : residue ){

    answer.push_back( f[0] );

  }

  return;
  
}

template <typename T , template <typename...> typename V1 , template <typename...> typename V2> inline void SetMultipointEvaluation( const Polynomial<T>& f , const V1<T>& point , V2<T>& answer ) { list<list<Polynomial<T> > > pt{}; SetPointTree( point , pt ); SetPointTreeEvaluation( f , pt , answer ); }

template <typename T , template <typename...> typename V1 , template <typename...> typename V2>
void SetDifferenceProduct( const V1<T>& point , V2<T>& answer )
{

  list<vector<Polynomial<T> > > pt{};
  SetPointTree( point , pt );
  const vector<Polynomial<T> >& top = pt.front();

  if( top.empty() ){

    return;

  }

  Polynomial<T> g{ Differential( 1 , top.front() ) };
  SetPointTreeEvaluation( g , pt , answer );
  return;

}

template <typename T , template <typename...> typename V1 , template <typename...> typename V2>
void SetQuotientPartialFractionDecomposition( const Polynomial<T>& f , const V1<T>& point , V2<T>& answer )
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
void SetRationalPartialFractionDecomposition( const int& N , Polynomial<T> f , const V1<T>& point , V2<T>& answer )
{

  list<list<Polynomial<T> > > pt{};
  SetPointTree( point , pt );
  const list<Polynomial<T> >& top = pt.front();

  if( top.empty() ){

    return;

  }

  Polynomial<T> g{ top.front() };
  FormalPowerSeries<T> fg{ point.size() + 1 , move( f ) };
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
