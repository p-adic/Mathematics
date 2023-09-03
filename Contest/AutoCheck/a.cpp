// c:/Users/user/Documents/Programming/Contest/AutoCheck/a.cpp

#include "../Header.hpp"
#include "a_Body.hpp"

void AutoCheck( bool& auto_checked )
{
  int num = 0;
  int num_temp = 0;
  string reply{};
  vector<string> problems{};
  int problems_size = 0;
  ASK_NUMBER(
	     "提出用ファイルを実行する。" ,
	     "提出済みファイルをデバッグする。" ,
	     "ライブラリーを探索する。"
	     );
  if( num == num_temp++ ){
    auto_checked = false;
    CERR( "提出用ファイルを実行します。" );
  } else if( num == num_temp++ ){
    CALL_AC( DebugHint );
  } else if( num == num_temp++ ){
    CALL_AC( LibrarySearch );
  }
  CERR( "" );
}
AC( DebugHint )
{
  ASK_NUMBER(
	     "WAのデバッグ" ,
	     "REのデバッグ" ,
	     "TLEのデバッグ" ,
	     "MLEのデバッグ"
	     );
  if( num == num_temp++ ){
    CERR( "- operator<<()をint型に適用していませんか？" );
    CERR( "- イベント管理にsetを使っていませんか？" );
    CERR( "  - keyに狭義全順序を用いる場合、" );
    CERR( "    - 同一keyの処理を同時に行うならばmapを検討しましょう。" );
    CERR( "    - 同一keyの処理を同時に行わないならばmultisetを検討しましょう。" );
    CERR( "  - keyに狭義全順序の積順序を用いる場合、mapの入れ子を検討しましょう。" );
    CERR( "- 動的計画法においてindexのswapやmodを用いてメモリ削減を行う場合、" );
    CERR( "  各ループの最初にdpテーブルの初期化をし忘れていませんか？" );
    CERR( "- 番兵の設定忘れか設定ミスをしていませんか？" );
    CERR( "- マルチテストケースで配列にstaticをつけて値が持ち越されていませんか？" );
    CERR( "- cLay使用畤にsetmod以前に10^9+7より大きい値を代入していませんか？" );
    CERR( "" );
    CERR( "原因に心当たりがない場合はランダムテストを検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "- 制約を間違えてassertしていませんか？" );
    CERR( "- 配列外参照していませんか？" );
    CERR( "  - 座標圧縮畤に圧縮前の添字操作と圧縮後の添字操作を混同していませんか？" );
    CERR( "  - グラフや座標圧縮の操作で存在しない座標-1の場合分けを忘れていませんか？" );
    CERR( "- 二分探索マクロで探索値が存在しない場合を回避し忘れていませんか？" );
    CERR( "- イテレータを範囲外まで--/++していませんか？" );
    CERR( "- 0で割っていませんか？" );
  } else if( num == num_temp++ ){
    CERR( "- マルチテストケースでデータ構造の初期化が反復されていませんか？" );
    CERR( "- whileループで添字等の更新忘れによる無限ループはありませんか？" );
    CERR( "- 重過ぎる定数倍を考慮し忘れてませんか？" );
    CERR( "  - bool値の処理はbit演算による並列化を検討しましょう。" );
    CERR( "  - 変数の和や積に上限があるグリッド問題は動的配列を検討しましょう。" );
    CERR( "- リアクティブ問題でflushと改行をし忘れていませんか？" );
  } else if( num == num_temp++ ){
    CERR( "- グラフで辺を持ち過ぎていませんか？" );
    CERR( "- （多重）配列でサイズが10^6を大幅に上回ってませんか？" );
    CERR( "  - データ構造は座標圧縮を検討しましょう。" );
    CERR( "  - 動的計画法は初期化忘れに注意して添字のswapやmodを検討しましょう。" );
    CERR( "- Python使用畤に変数名の重複による型エラーが起きてませんか？" );
    CERR( "  - rangeのRと[L,R)のRの重複は後者に[l,r)を用いて解消しましょう。" );
    CERR( "  - 素数のPと順列のPの重複は後者にAやQを用いて解消しましょう。" );
    CERR( "- Python使用畤に桁数が大きくなり過ぎていませんか？" );
  }
  CERR( "" );
  CERR( "提出済みファイルのデバッグは以上です。終了します。" );
}
AC( LibrarySearch )
{
  ASK_NUMBER(
	     "明示式の計算問題" ,
	     "最大／最小化問題" ,
	     "数え上げ問題" ,
	     "求解問題" ,
	     "クエリ処理問題" ,
	     "真偽判定問題" ,
	     "構築問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( ExplicitExpression );
  } else if( num == num_temp++ ){
    CALL_AC( Maximisation );
  } else if( num == num_temp++ ){
    CALL_AC( Counting );
  } else if( num == num_temp++ ){
    CALL_AC( Solving );
  } else if( num == num_temp++ ){
    CALL_AC( Query );
  } else if( num == num_temp++ ){
    CALL_AC( Decision );
  } else if( num == num_temp++ ){
    CALL_AC( Construction );
  }
  ASK_YES_NO( "マルチテストケースですか？" );
  if( reply == "y" ){
    CERR( "テストケースを跨ぐ前計算が可能か否かを優先的に考察しましょう。" );
    CERR( "" );
    CERR( "テストケース全体でのNの総和に直接上限が与えられている問題では、" );
    CERR( "ライブラリーの使用時は配列の初期化が各テストケースに必要となる場合に" );
    CERR( "TLEとなる可能性が高いです。" );
    CERR( "- 動的配列への置き換え" );
    CERR( "- 座標圧縮" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\CoordinateCompress" );
    CERR( "を検討しましょう。" );
    CERR( "" );
  }
  CERR( "ライブラリー探索は以上です。終了します。" );
}
AC( ExplicitExpression )
{
  ASK_NUMBER(
	     "１変数関数／数列の計算問題" ,
	     "配列上の関数の総和の計算問題" ,
	     "順列上の関数の計算問題" ,
	     "木上の関数の総和の計算問題" ,
	     "木以外のグラフ上の関数の計算問題" ,
	     "序数の計算問題" ,
	     "確率／期待値の計算問題" ,
	     "その他の明示式の計算問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionUnary );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionArraySum );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionFunctionOnPermutation );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionFunctionOnTree );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionFunctionOnNonTreeGraph );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionOrder );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionProbability );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionOther );
  }
}
AC( ExplicitExpressionUnary )
{
  ASK_NUMBER(
	     "線形漸化式の問題" ,
	     "１変数関数の反復合成の問題" ,
	     "その他の１変数関数の計算問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionUnaryLinearRecursion );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionUnaryIteration );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionUnaryOther );
  }
  CERR( "を検討しましょう。" );
}
AC( ExplicitExpressionUnaryLinearRecursion )
{
  CERR( "L項間線形漸化式a_n=sum(i,0,L){c_i a_{n-L+i}}が与えられているとします。" );
  CERR( "" );
  CERR( "適宜Z/B Zの型" );
  CERR( "\\Mathematics\\Arithmetic\\Mod\\ConstexprModulo" );
  CERR( "\\Mathematics\\Arithmetic\\Mod\\QuotientRing" );
  CERR( "を用いて" );
  CERR( "- O(LN)が間に合いそうならば直近L+1項をメモ化する動的計画法" );
  CERR( "- O(L^2 log N)が間に合いそうならば行列累乗" );
  CERR( "  \\Mathematics\\LinearAlgebra" );
  CERR( "- 係数列(c_i)_iが定数列でO(N log N)が間に合いそうならば区間加算BIT" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\IntervalAddo" );
  CERR( "- 係数列(c_i)_iが単調でD階差分が定数列でO((N+L)D)が間に合いそうならば" );
  CERR( "  「係数列のd階Δ^d(c_i)_i差分と(a_i)_{i=n-L+d+1}^{n}の内積dp[n][d]」" );
  CERR( "  を管理する動的計画法" );
}
AC( ExplicitExpressionUnaryIteration )
{
  CERR( "定義域の要素数N、テストケース数T、反復回数の上限Kとします。" );
  CERR( "- O((N + T)log_2 K)が通りそうならばダブリング" );
  CERR( "  \\Mathematics\\Function\\Iteration\\Doubling" );
  CERR( "- O(TN)が通りそうならばループ検出" );
  CERR( "  \\Mathematics\\Function\\Iteration\\LoopDetection" );
  CERR( "- O(N)すら通らなさそうならば関数の規則性を見付けるための実験" );
}
AC( ExplicitExpressionUnaryOther )
{
  CERR( "まずは小さい入力の場合を愚直に計算し、OEISで検索しましょう。" );
  CERR( "https://oeis.org/?language=japanese" );
  CERR( "" );
  CERR( "次に出力の定義と等価な式を考察しましょう。" );
  CERR( "- 単調ならば、冪乗や階乗" );
  CERR( "- 定義にp進法が使われていれば、各種探索アルゴリズム" );
  CERR( "- 入力が素数に近い場合に規則性があれば、p進付値、p進法、" );
  CERR( "  オイラー関数、約数の個数など" );
  CERR( "を検討しましょう。" );
  CERR( "" );
  CERR( "前計算の候補としては" );
  CERR( "- 素数列挙" );
  CERR( "- １つまたは複数の整数の約数列挙" );
  CERR( "- オイラー関数の値の列挙" );
  CERR( "- サブゴールとなる関係式を満たす解の列挙" );
}
AC( ExplicitExpressionArraySum )
{
  ASK_NUMBER(
	     "成分を受け取る関数の総和の計算問題" ,
	     "部分列を受け取る関数の総和の計算問題"
	     );
  if( num == num_temp++ ){
    CERR( "成分を受け取る関数fが与えられているとします。" );
    CERR( "fが一次式の場合、実質内積と定数の和となります。" );
    CERR( "内積は片方の添え字を反転させることで畳み込みに帰着させることができます。" );
    CERR( "配列への操作がシフトである場合は繰り返し内積を求めることになるので、" );
    CERR( "適当な法での高速フーリエ変換" );
    CERR( "\\Mathematics\\Arithmetic\\Mod" );
    CERR( "\\Mathematics\\Polynoial" );
    CERR( "を検討しましょう。" );
  } else if( num == num_temp++ ){
    ASK_NUMBER(
	       "連続部分列への分割に関する関数の総和の計算問題" ,
	       "連続とは限らない部分列への分割に関する関数の総和の計算問題"
	       );
    if( num == num_temp++ ){
      CERR( "配列の添字集合は全順序集合なので、木の分割の問題に一般化されます。" );
      CALL_AC( ExplicitExpressionFunctionOnTree );
      CERR( "" );
      CERR( "更にfが部分列の長さに関する再帰的な構造を持つ場合、全ての連続部分列に" );
      CERR( "対しfの値を前計算することを検討しましょう。" );
    } else if( num == num_temp++ ){
      CERR( "配列の並び換えによって答えが変わらないので、適切にソートしてから" );
      CERR( "計算することを検討しましょう。" );
    }
  }
  CERR( "" );
  CERR( "入力が大きい場合と小さい場合で解法を変える考察を忘れないようにしましょう。" );
}
AC( ExplicitExpressionFunctionOnPermutation )
{
  CERR( "- 符号そのものの計算問題は" );
  CERR( "  - O(N log_2 N)やO(N^2)が間に合いそうなら転倒数の計算" );
  CERR( "  - O(N log_2 N)が間に合わなさそうなら互換表示（O(N)）" );
  CERR( "- 符号と何かの積の和は行列式に帰着させ、" );
  CERR( "  - 行列式そのものなら行基本変形（O(N^3)）" );
  CERR( "  - 余因子展開の途中の値が必要ならメモ化再帰（O(N 2^N)）" );
  CERR( "を検討しましょう。" );
  CERR( "" );
  CERR( "１つの順列の転倒数は、" );
  CERR( "- O(N^2)が通りそうならば愚直な二重ループ" );
  CERR( "- O(N log_2 N)が通りそうならば可換群BIT" );
  CERR( "  \\Mathematics\\Combinatorial\\Permutation" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT" );
  CERR( "で計算しましょう。" );
  CERR( "" );
  CERR( "条件を満たす順列全体をわたる転倒数の総和／期待値は、" );
  CERR( "各i<jごとにそこで転倒が生じる順列の個数を計算し、その総和／期待値を" );
  CERR( "取りましょう。条件が良ければ、転倒が生じる順列の個数は転倒が生じるとは" );
  CERR( "限らない順列の個数の半分となります。" );
}
AC( ExplicitExpressionFunctionOnTree )
{
  CALL_AC( FunctionOnTree );
  CERR( "" );
  CERR( "部分木に関する良い遷移関係を探し、（全方位）木DP" );
  CERR( "\\Mathematics\\Geometry\\Graph\\DepthFirstSearch\\Tree" );
  CERR( "を検討しましょう。" );
  ASK_YES_NO( "fがbit演算である問題ですか？" );
  if( reply == "y" ){
    CERR( "「Tの各ノードvを根とする部分木でのj桁目のbit状態sの個数dp[v][s][j]」" );
    CERR( "を管理するv,s,jに関する動的計画法を検討しましょう。" );
    CERR( "これはTが全順序集合でbit演算が1種類なら" );
    CERR( "「第i成分で切った部分列でのj桁目のbitがs（=0,1）である個数dp[i][s][j]」" );
    CERR( "を管理することに他なりません。" );
  }
}
AC( FunctionOnTree )
{
  CERR( "木を受け取る関数fが与えられているとします。" );
  CERR( "" );
  CERR( "木Tの分割Pに対し、Pの各成分pを渡るf(p)の総和をF(P)と置きます。" );
  CERR( "Tに根を固定し、深さ優先探索でTの頂点にラベルづけをします。" );
  CERR( "" );
  CERR( "Pの各成分pに対しpの各頂点のラベルの最小値をD(p)と置き、" );
  CERR( "Dについて昇順にPを並べます。" );
  CERR( "" );
  CERR( "Pの末尾成分pを削除した分割P'が元の木からpを削除した木の分割であり" );
  CERR( "F(P)=F(P')+f(p)と表せることに注意しましょう。" );
}
AC( ExplicitExpressionFunctionOnNonTreeGraph )
{
  CERR( "- 部分集合上の関数の計算問題は" );
  CERR( "  - O(N 2^N)が間に合いそうなら高速ゼータ変換／メビウス変換" );
  CERR( "    \\Mathematics\\Combinatorial\\ZetaTransform" );
  CERR( "  - O(N^2)が間に合いそうで要素数にのみ依存するならマーラー変換" );
  CERR( "    \\Mathematics\\Combinatorial\\ZetaTransform\\MahlerTransform" );
  CERR( "- その他の順序集合上の関数の計算問題はゼータ変換／メビウス変換" );
  CERR( "  \\Mathematics\\Combinatorial\\ZetaTransform" );
  CERR( "を検討しましょう。" );
}
AC( ExplicitExpressionOrder )
{
  CERR( "集合Sを何らかの順序でソートした配列aに関する問題で、" );
  CERR( "- 与えられた要素sが下から何番目かを答える場合は、" );
  CERR( "  - 各iごとにa[i]が求められるならば、iに関する二分探索" );
  CERR( "  - そうでないならば、s未満の項の数え上げ" );
  CERR( "- 与えられたiに対するa[i]を答える場合は、" );
  CERR( "  Sの各要素sごとにs未満の項を数え上げてsに関する二分探索" );
  CERR( "を検討しましょう。" );
  CERR( "" );
  CERR( "辞書式順序でs未満の項の数え上げをする際は、" );
  CERR( "「sとd文字目で初めてズレるl文字の項の総数count[d][l]」" );
  CERR( "のdとlをわたる総和を求めましょう。" );
}
AC( ExplicitExpressionProbability )
{
  CERR( "- 確率計算は" );
  CERR( "  - 余事象や包除原理（高速ゼータ変換／メビウス変換）" );;
  CERR( "    \\Mathematics\\Combinatorial\\ZetaTransform" );
  CERR( "  - 同様に確からしい事象の特定" );
  CERR( "  - ベイズの定理" );
  CERR( "- 期待値計算は" );
  CERR( "  - 上記方法での確率計算" );
  CERR( "  - 対象を独立な和で表して線形性" );
  CERR( "を検討しましょう。" );
}
AC( ExplicitExpressionOther )
{
  CERR( "- 出力の定義と等価な式への変形" );
  CERR( "  - 和の順序交換" );
  CERR( "  - 同じ値になる項の纏め上げ" );
  CERR( "  - 二項展開や積の和典型などの組み合わせ論的解釈" );
  CERR( "    https://ei1333.hateblo.jp/entry/2021/07/30/144201" );
  CERR( "- 和の動く範囲の差分に注目した動的計画法" );
  CERR( "を検討しましょう。" );
}
AC( Maximisation )
{
  ASK_NUMBER(
	     "低次元アフィン空間上の関数の最大／最小化問題" ,
	     "配列上の関数の最大／最小化問題" ,
	     "配列の隣接成分間関係式を満たす部分列の最長化問題" ,
	     "木上の関数の最大／最小化問題" ,
	     "移動コスト最小化問題" ,
	     "文字列のマッチングに関する最大／最長化問題" ,
	     "最大二部マッチング問題" ,
	     "確率／期待値の最大化問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( MaximisationFunctionOnAffineSpace );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationFunctionOnArray );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationArrayLength );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationFunctionOnTree );
  } else if( num == num_temp++ ){
    CALL_AC( MinimisationMovingCost );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationStringMatching );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationBipartiteMatching );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationProbability );
  }
}
AC( MaximisationFunctionOnAffineSpace )
{
  ASK_NUMBER(
	     "凸関数の最小／最大化問題" ,
	     "可微分関数の最小／最大化問題" ,
	     "絶対値の最小／最大化問題"
	     );
  if( num == num_temp++ ){
    CERR( "三分探索を検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "ニュートン法を検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "符号を用いて絶対値を外しましょう。" );
    CERR( "- 単調な式に帰着できる場合、二分探索" );
    CERR( "- 最大化問題の場合、符号パターンの全探策" );
    CERR( "- マンハッタン距離などは一次変換" );
    CERR( "を検討しましょう。" );
  }
  CERR( "" );
  CERR( "複数のパラメータを決定すべき場合は、サブゴールの式の値を決め打ちましょう。" );
}
AC( MaximisationFunctionOnArray )
{
  ASK_NUMBER(
	     "問題文または入力で与えられる１つの配列に関する問題" ,
	     "条件を満たす任意の配列に関する問題"
	     );
  if( num == num_temp++ ){
    ASK_NUMBER(
	       "成分を受け取る関数の部分和の最大化問題" ,
	       "配列の変更と配列を受け取る関数の合成の最大化問題"
	       );
    if( num == num_temp++ ){
      CALL_AC( MaximisationSubArraySum );
    } else if( num == num_temp++ ){
      CALL_AC( MaximisationArrayFunction );
    }
  } else if( num == num_temp++ ){
    CERR( "- 取り得る値が少なく関数が長さに関して再帰的構造を持つ場合は、" );
    CERR( "  「長さiの時に可能な値全体または一部の集合dp[i]」" );
    CERR( "  を管理するiに関する動的計画法" );
    CERR( "- 「v以上の値を取り得るか否か」が判定可能である時は" );
    CERR( "  vに関する二分探索" );
    CERR( "を検討しましょう。" );
  }
}
AC( MaximisationSubArraySum )
{
  CERR( "項数N、選択回数上限M、価値（和を取る値）上限Vとします。" );
  ASK_NUMBER(
	     "各選択のコスト上限が存在しないか一定の問題" ,
	     "選択ごとにコストの上限が異なる問題"
	     );
  if( num == num_temp++ ){
    CERR( "各選択のコスト上限が存在する場合、その上限以下の項だけを考えましょう。" );
    CERR( "コストの総和上限Cとします。C=∞ならば通常のナップサック問題と" );
    CERR( "同様の動的計画法で良いので、以下C<∞の場合を考えます。" );
    CERR( "- O(2^N)が通りそうならば愚直に全探策" );
    CERR( "- O(N 2^{N/2})が通りそうならば半分全列挙" );
    CERR( "- コストと価値が等しくO(NV)が通りそうならば[C-V,C+V]での実現可能性を" );
    CERR( "  遷移する動的計画法" );
    CERR( "  https://stackoverflow.com/a/18949218" );
    CERR( "- コストと価値が等しくO((N+C)log_2 C)が通りそうならば" );
    CERR( "  適当な法での畳み込み（確率的解法）" );
    CERR( "  \\Mathematics\\Polynomial" );
    CERR( "- コストと価値が等しくなくO(C^2)が通りそうならば" );
    CERR( "  「コストcの項の価値の最大値v[c]」" );
    CERR( "  を前計算し" );
    CERR( "  「コストの総和がc以下の時の価値の最大値dp[c]」" );
    CERR( "  を管理するcに関する動的計画法" );
    CERR( "を検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "コストの次元をK<=2、n項目のコストをC_nとし、" );
    CERR( "m選択目ではC_n[k_m]<=D_mを満たす項nを選べるとします。" );
    CERR( "" );
    CERR( "項{C_n,n}と選択{k_m,D_m}をそれぞれ辞書式順序でソートし、" );
    CERR( "以下の手順で選択を昇順に決定していきましょう。" );
    CERR( "- K=1の場合、各選択では可能な選択の中で最大のものを採用しましょう。" );
    CERR( "- K=2の場合、各選択では可能な選択の{第2成分,項番号}をsetで管理しつつ" );
    CERR( "  その中で最大のものを採用しましょう。" );
  }
}
AC( MaximisationArrayFunction )
{
  CERR( "配列を受け取る関数Fが与えられているとします。与えられた配列Aに" );
  CERR( "何らかの処理をして得られる配列Bに対するF(B)の最大化問題は、" );
  CERR( "最大化すべき式のサブゴールfに表れる項xのうち決め打ちやすいものを探しましょう。" );
  CERR( "- 配列の長さをiで打ち切った時のxの候補数をX(i)" );
  CERR( "- 配列の長さをiで打ち切ってxを決め打った時の配列の長さi+1でのxの候補数をdX(i)" );
  CERR( "と置きます。" );
  CERR( "- O(sum_i X(i) dX(i))が通りそうでfがxからO(1)で計算できるならば、" );
  CERR( "  iとxに関する動的計画法" );
  CERR( "- O(N log_2 X(N))が通りそうで" );
  CERR( "  - fがxからO(N)で計算できxに関して単調ならば、xの二分探索" );
  CERR( "  - fがxからO(N/x)で計算できるならば、xの全探索" );
  CERR( "- O(N log_2 N)が通りそうでxを並び替えるとfがxからO(log_2 N)で計算できるならば、" );
  CERR( "  優先度つきキューなどでのxの管理" );
  CERR( "を検討しましょう。" );
}
AC( MaximisationArrayLength )
{
  CERR( "全順序か疎な半順序かで効率的な実装が違います。" );
  CERR( "- 全順序ならば、条件を満たす部分列の長さの最大値をインデックスに持つ" );
  CERR( "  配列を用いて、それらの部分列の末尾である項を記録すること" );
  CERR( "  \\Mathematics\\Combinatorial\\Counting\\IncreasingSubsequence" );
  CERR( "- 疎な半順序ならば、条件を満たす部分列の末尾をインデックスに持つ" );
  CERR( "  連想配列を用いて、それら部分列の長さの最大値を記録すること" );
  CERR( "  \\Mathematics\\Combinatorial\\Counting\\IncreasingSubsequence\\Subwalk" );
  CERR( "を検討しましょう。" );
}
AC( MaximisationFunctionOnTree )
{
  CALL_AC( FunctionOnTree );
  CERR( "「第i頂点までで切った時のF(P)たちの最大値dp[i]」" );
  CERR( "を管理するiに関する動的計画法（O(N^2×fの計算量)）" );
  CERR( "を検討しましょう。" );
}
AC( MinimisationMovingCost )
{
  ASK_NUMBER(
	     "２点最小コスト移動（迷路）問題" ,
	     "多点最小コスト移動（スタンプラリー）問題"
	     );
  if( num == num_temp++ ){
    CERR( "特定の経路を進むと思い込んで考察漏れをする可能性があります。" );
    CERR( "なるべく全ての経路を許した探索アルゴリズムを適用した方が無難です。" );
    CERR( "- 特定の２点のみを考える場合、BFSやDijkstra" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\BreadthFirst" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Dijkstra" );
    CERR( "- 全ての２点の組み合わせを考える場合、" );
    CERR( "  - 一般のモノイド演算を考えておりO(V^3)が通りそうならば、FloydWarshall" );
    CERR( "    \\Mathematics\\Geometry\\Graph\\FloydWarshall" );
    CERR( "  - max演算を考えておりO(E(log_2 E + α(V)))が通りそうならば、UnionFind" );
    CERR( "    \\Utility\\VLTree\\UnionFindForest" );
    CERR( "を検討しましょう。" );
    CERR( "" );
    CERR( "点の座標と最小化すべきコスト以外の数値変化がある場合、最小コスト移動における" );
    CERR( "その数値の動く範囲を絞って点の座標との組を頂点とするグラフを検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "HeldKarpや、移動方法を分類するパラメータの全探策などを検討しましょう。" );
  }
}
AC( MaximisationStringMatching )
{
  CERR( "基本的には丁寧にループを回して解きましょう。" );
  CERR( "- 比較対象が少ない場合、前または後ろから順に探索（貪欲法／動的計画法）" );
  CERR( "- ワイルドカードを含む場合、" );
  CERR( "  - 前または後ろから順に場合分けをしてO(N)で処理できるか" );
  CERR( "  - 可能な代入方法を絞り込んでO(N)種類に落せるか" );
  CERR( "- 比較回数が多い場合、ローリングハッシュ" );
  CERR( "  \\Utility\\String\\RollingHash" );
  CERR( "- 部分回文の最長化をする場合、尺取り法による前計算" );
  CERR( "  \\Utility\\String\\Palindrome" );
  CERR( "- マッチングする部分文字列の最長化をする場合、Zアルゴリズム" );
  CERR( "  \\Utility\\String\\Z-Algorithm" );
  CERR( "- マッチングする文字数の最大化をする場合、文字の種類分の{0,1}値配列に" );
  CERR( "  分けて内積の最大化（添え字を反転させて適当な法での畳み込み）" );
  CERR( "  \\Mathematics\\Arithmetic\\Mod" );
  CERR( "  \\Mathematics\\Polynomial" );
  CERR( "を検討しましょう。" );
}
AC( MaximisationBipartiteMatching )
{
  CERR( "HopcroftKarpや最大流" );
  CERR( "\\Mathematics\\Geometry\\Graph\\HopcroftKarp" );
  CERR( "を検討しましょう。" );
}
AC( MaximisationProbability )
{
  CERR( "操作／戦略を選んで確率／期待値を最大化する場合、" );
  CERR( "被操作対象や可能な操作／戦略のデータなどを状態として定式化し、" );
  CERR( "「sを経由する場合の確率／期待値の最大値dp[s]」" );
  CERR( "を管理するsに関する動的計画法を検討しましょう。" );
}
AC( Counting )
{
  ASK_NUMBER(
	     "固定長変数関数で与えられる明示式の数え上げ問題" ,
	     "配列に関する数え上げ問題" ,
	     "分割に関する数え上げ問題" ,
	     "文字列の数え上げ問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( CountingExplicitExpression );
  } else if( num == num_temp++ ){
    CALL_AC( CountingArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingPartitionOfTree );
  } else if( num == num_temp++ ){
    CALL_AC( CountingString );
  }
}
AC( CountingExplicitExpression )
{
  CERR( "- 変数の対称性があれば大小関係を制限した全探策" );
  CERR( "- 何らかの約数となるなど動く範囲が狭い変数があればそれらを決め打った全探策" );
  CERR( "- 多変数の合成関数で表せる場合は半分全列挙" );
  CERR( "を検討しましょう。" );
}
AC( CountingArray )
{
  ASK_NUMBER(
	     "問題文または入力で与えられる１つの配列に関する問題" ,
	     "条件を満たす任意の配列に関する問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( CountingSubArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingArbitraryArray );
  }
}
AC( CountingSubArray )
{
  ASK_NUMBER(
	     "配列の成分を受け取る関数の部分和を固定した部分列の数え上げ問題" ,
	     "配列の隣接成分間関係式を満たす部分列の数え上げ問題" ,
	     "配列の部分列から取得位置情報を落とした配列の数え上げ問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( CountingSumFixedSubArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingRestrctedSubArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingSubArrayImage );
  }
}
AC( CountingSumFixedSubArray )
{
  CERR( "項数N、コストの総和の上限Cとします。" );
  CERR( "- コストと価値が異なりO(2^N)が通りそうならば愚直な２変数多項式乗算" );
  CERR( "- コストと価値が等しくO(2^N)が通りそうならば愚直な１変数多項式乗算" );
  CERR( "- コストと価値が等しくO(2^{N/2}N)が通りそうならば半分ずつ多項式乗算を" );
  CERR( "  して最後にそれらの積の１係数のみの計算" );
  CERR( "- コストと価値が等しくCが10^5オーダーで法が与えられていてO((N+C)log_2 C)が" );
  CERR( "  通りそうならば適当な法での高速フーリエ変換" );
  CERR( "  \\Mathematics\\Arithmetic\\Mod" );
  CERR( "  \\Mathematics\\Polynomial" );
  CERR( "を検討しましょう。" );
}
AC( CountingRestrctedSubArray )
{
  ASK_NUMBER(
	     "連続部分列の数え上げ問題" ,
	     "連続とは限らない部分列の数え上げ問題" ,
	     "部分順列（部分列の並び換え）の数え上げ問題"
	     );
  CERR( "長さNの配列Aと、L+n<=N+1を満たす整数n,Lと" );
  CERR( "- 整数iに関する条件Q(i)" );
  CERR( "- 各0<=l<Lに対するn-tuple(b_0,...,b_{n-1})に関する条件R_l(b_0,...,b_{n-1})" );
  CERR( "が与えられているとし、配列Bの条件P(B)を" );
  CERR( "「Bの長さ|B|がQ(|B|)かつ|B|<L+nを満たし、かつ任意の0<=l<=|B|-nに対し" );
  CERR( "　R_l(B_l,...,B_{l+n-1})が成り立つ。」" );
  CERR( "の論理積として定めます。" );
  CERR( "" );
  CERR( "例えば山型の部分列の数え上げ問題ではN>=3かつ(n,L)=(2,2)で" );
  CERR( "- Q(i)=「i=3」" );
  CERR( "- R_0(b_0,b_1)=「b_0<b_1」" );
  CERR( "- R_1(b_0,b_1)=「b_0>b_1」" );
  CERR( "と表されます。" );
  CERR( "" );
  if( num == num_temp++ ){
    CALL_AC( CountingRestrctedContinuousSubArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingRestrctedDiscontinuousSubArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingRestrctedSubPermutation );
  }
  CERR( "を検討しましょう。" );
  CERR( "" );
  CERR( "特にR_l(B)たちがgcdやmaxなどの羃等演算に関する等式で与えられる場合は、" );
  CERR( "不等式の方が扱いやすいのでゼータ変換／メビウス変換" );
  CERR( "\\Mathematics\\Combinatorial\\ZetaTransform" );
  CERR( "を検討しましょう。" );
}
AC( CountingRestrctedContinuousSubArray )
{
  CERR( "P(B)を満たすAの連続部分列Bの数え上げは、" );
  CERR( "- R_lたちがlに依存しないならば尺取り法O(N)" );
  CERR( "- R_lたちがlに依存する場合、" );
  CERR( "  - O(N^2)が通りそうなら左端を固定した愚直探索" );
  CERR( "  - O(N^2)が通らなさそうならR_lたちの読み替え" );
  CERR( "を検討しましょう。" );
}
AC( CountingRestrctedDiscontinuousSubArray )
{
  CERR( "P(B)を満たすAの連続とは限らない部分列Bの数え上げは、" );
  CERR( "- n-1<=i<=max{j<=N|Q(j)}を満たす各i" );
  CERR( "- (0,1,...,N-1)の長さn-1の各部分列s" );
  CERR( "に対する" );
  CERR( "「長さiで、任意の0<=l<=i-nに対しR_l(B)を満たし、" );
  CERR( "　末尾n-1項がsに対応するAの部分列Bの個数dp[i][s]」" );
  CERR( "を管理するi,sに関する動的計画法" );
  CERR( "\\Mathematics\\Combinatorial\\Counting\\IncreasingSubsequence" );
  CERR( "\\Mathematics\\Combinatorial\\Counting\\IncreasingSubsequence\\Subwalk" );
  CERR( "を検討しましょう。" );
}
AC( CountingRestrctedSubPermutation )
{
  CERR( "P(B)を満たすAの部分順列Bの数え上げは、" );
  CERR( "- n-1<=|S|<=max{j<=N|Q(j)}を満たす(0,1,...,N-1)の部分集合S" );
  CERR( "- Sの長さn-1の各部分順列s" );
  CERR( "に対する" );
  CERR( "「任意の0<=l<=|S|-nに対しR_l(B)を満たし、末尾n-1項がsに対応し、」" );
  CERR( "　全体がSに対応するAの部分順列Bの個数dp[S][s]」" );
  CERR( "を管理するS,sに関する動的計画法を検討しましょう。" );
  CERR( "" );
  CERR( "sの網羅は[0,N)^{n-1}の全探策でもS内の順列探索と定数倍しか変わらないので" );
  CERR( "実装の速さを優先しましょう。" );
  CERR( "" );
  CERR( "Nが小さい場合は概算値" );
  CERR( "7! ≒ 5×10^3" );
  CERR( "8! ≒ 4×10^4" );
  CERR( "9! ≒ 4×10^5" );
  CERR( "10! ≒ 4×10^6" );
  CERR( "11! ≒ 4×10^7" );
  CERR( "12! ≒ 5×10^8" );
  CERR( "を参考に順列の全列挙" );
  CERR( "\\Mathematics\\Combinatorial\\Permutation" );
  CERR( "を検討しましょう。" );
}
AC( CountingArbitraryArray )
{
  ASK_NUMBER(
	     "配列を受け取る関数の値の数え上げ問題" ,
	     "隣接成分間関係式を満たす配列の数え上げ問題"
	     );
  if( num == num_temp++ ){
    CERR( "- 配列の種類が少ない場合は、全ての配列に対する関数の値の前計算" );
    CERR( "- 取り得る値が少なく関数が長さに関して再帰的構造を持つ場合は、" );
    CERR( "  「長さiの時に値vである配列の総数dp[i][v]」" );
    CERR( "  を管理するi,vに関する動的計画法" );
  } else if( num == num_temp++ ){
    CERR( "- いくつかの条件の重ね合わせの時は包除原理" );
    CERR( "- 全順序の場合は数の分割方法などへの翻訳" );
    CERR( "- 疎な半順序の場合はグラフの前計算" );
  }
  CERR( "を検討しましょう。" );
}
AC( CountingSubArrayImage )
{
  CERR( "入力で与えられる配列をAと置きます。" );
  CERR( "配列として等しいAの部分列のうち辞書式順序最小のものを数え上げる" );
  CERR( "部分列DPを検討しましょう。具体的には" );
  CERR( "「末尾が第i成分由来で辞書順最小なAの部分列の個数dp[i]」" );
  CERR( "「s=A[j]を満たすj<iの最大値last[i][s]」" );
  CERR( "の２つを管理するiに関する動的計画法を検討しましょう。" );
}
AC( CountingPartitionOfTree )
{
  CALL_AC( FunctionOnTree );
  CERR( "" );
  CERR( "F(P)が固定された時のPの数え上げ問題は" );
  CERR( "「第i成分までで切った時のF(P)=vを満たすPの個数dp[i][v]」" );
  CERR( "を管理するi,vに関する動的計画法（O(N^2 v_max×fの計算量)）" );
  CERR( "を検討しましょう。" );
}
AC( CountingString )
{
  ASK_NUMBER(
	     "部分文字列から取得位置情報を落とした文字列全体の数え上げ問題" ,
	     "マッチングに関する性質を満たす部分文字列の数え上げ問題"
	     );
  if( num == num_temp++ ){
    CERR( "文字列を文字の配列とみなすことで、配列の問題に帰着させることができます。" );
    CALL_AC( CountingSubArrayImage );
  } else if( num == num_temp++ ){
    CALL_AC( CountingMatchingSubString );
  }
}
AC( CountingMatchingSubString )
{
  CERR( "- 自分とマッチングする部分文字列の数え上げ問題はZアルゴリズム" );
  CERR( "  \\Utility\\String\\Z-Algorithm" );
  CERR( "- 回文である部分文字列の数え上げ問題は" );
  CERR( "  - O(N^2)が通る場合、尺取り法による前計算" );
  CERR( "    \\Utility\\String\\Palindrome" );
  CERR( "  - O(N^2)が通らない場合、Manacherのアルゴリズムやローリングハッシュで前計算" );
  CERR( "    https://snuke.hatenablog.com/entry/2014/12/02/235837" );
  CERR( "    \\Utility\\String\\RollingHash" );
  CERR( "を検討しましょう。" );
}
AC( Solving )
{
  CERR( "- 単調関数は二分探索" );
  CERR( "- 可微分関数はニュートン法" );
  CERR( "- 一次関数は掃き出し法" );
  CERR( "を検討しましょう。" );
}
AC( Query )
{
  ASK_NUMBER(
	     "配列の問題" ,
	     "グラフの問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( QueryArray );
  } else if( num == num_temp++ ){
    CALL_AC( QueryGraph );
  }
}
AC( QueryArray )
{
  ASK_NUMBER(
	     "可換群構造+を使う問題" ,
	     "可換羃等モノイド構造∨を使う問題" ,
	     "モノイド構造*を使う問題" ,
	     "非結合的マグマ構造*を使う問題" ,
	     "集合へのマグマ作用(*,\\cdot)を使う問題" ,
	     "モノイドへのマグマ作用(+,\\cdot)を使う問題" ,
	     "一次関数とのmaxを取った値を使う問題" ,
	     "定数とのmaxを取った値の区間和取得を使う問題"
	     );
  if( num == num_temp++ ){
    CERR( "- 区間加算／区間取得が必要ならば可換群BIT" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\Template" );
    CERR( "- 一点代入／一点加算／区間取得が必要ならば可換群平方分割" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Template" );
    CERR( "- 区間以外の領域で加算／全更新後の一点取得が必要ならば階差数列" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\Tree\\DifferenceSeqeuence" );
    CERR( "を検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "- 一点代入／区間加算／一点取得／区間取得が必要ならば可換羃等モノイドBIT" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\IntervalMax\\Template" );
    CERR( "を検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "- 一点代入／区間取得が必要ならばモノイドBIT" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\Template\\Monoid" );
    CERR( "- 一点加算／区間加算／一点取得／区間取得が必要ならばモノイド平方分割" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Template\\Monoid" );
    CERR( "- 一点代入／一点取得／区間取得が必要ならばモノイドセグメント木" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SegmentTree" );
    CERR( "を検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "- 写像のコード化" );
    CERR( "  \\Mathematics\\Function\\Encoder" );
    CERR( "によりモノイドに帰着させることを検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "- 一点作用／区間作用／一点取得が必要ならば双対平方分割" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Template\\Dual" );
    CERR( "を検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "- 区間代入／区間作用／区間加算／一点取得／区間取得が必要な場合は遅延評価平方分割" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Template\\LazyEvaluation" );
    CERR( "を検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "- 一次関数による全体max更新／一点取得が必要な場合はConvex Hull Trick" );
    CERR( "  \\Mathematics\\Function\\MaxLinearFunction" );
    CERR( "を検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "maxで全体更新でなく区間更新をする場合の汎用的な解法は分かりません。" );
    CERR( "例えば区間が包含について単調でmaxを取る値も単調であれば全体更新と" );
    CERR( "同様の処理ができます。状況に応じた考察をしましょう。" );
    CERR( "" );
    CERR( "maxで全体更新をする場合、maxを取る値は単調である場合に帰着できます。" );
    CERR( "maxで全体更新をしない場合、つまりただmaxの区間和を処理するだけの場合、" );
    CERR( "クエリの順番を入れ替えることができるので、単調な全体更新に帰着できます。" );
    CERR( "従って以下では単調な全体更新の問題を考えます。" );
    CERR( "" );
    CERR( "maxを取る定数を変数化し、元の値との大小を表す{0,1}値の係数を考えます。" );
    CERR( "すると区間作用前後の値は統一的にその係数と変数を使って表せます。" );
    CERR( "配列の各成分の係数の値が変化するイベントとクエリをソートして管理し、" );
    CERR( "クエリがイベントを跨ぐたびに係数を更新することを検討しましょう。" );
    CERR( "" );
    CERR( "例えばクエリB_qに対するmax(A_i,B_q)の区間和は、" );
    CERR( "- 優先度つきキューA'={(A_i,i)|i}（構築O(N log N)）" );
    CERR( "- (B_q,q)_qをソートしたB'（構築O(Q log Q)）" );
    CERR( "- 長さNの数列C=(0,...,0)（構築O(N)）" );
    CERR( "を用意し、B'を前から探索して順に各クエリ(B_q,q)を処理します。" );
    CERR( "具体的にはA'を前から探索して順にA_i<B_qとなる各iに対し" );
    CERR( "- A'から(A_i,i)を削除（クエリ合計O(N)）" );
    CERR( "- A_iを0に更新（クエリ合計O(N log N)）" );
    CERR( "- C_iを1に更新（各クエリO(log N)）" );
    CERR( "- A+C×B_qの区間和取得（各クエリO(log N)）" );
    CERR( "とすれば合計O((N + Q)log N + Q log Q)で処理できます。" );
  }
}
AC( QueryGraph )
{
  ASK_YES_NO( "代数構造を扱う問題ですか？" );
  if( reply == "yes" ){
    CERR( "- 可換群構造に関する加算／全更新後の一点取得が必要ならば階差数列" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\Tree\\DifferenceSeqeuence" );
  } else {
    CERR( "深さ優先探索や動的木やUnionFind" );
    CERR( "\\Mathematics\\Geometry\\Graph\\DepthFirst\\Tree" );
    CERR( "\\Utility\\VLTree" );
    CERR( "\\Utility\\VLTree\\UnionFndForest" );
  }
  CERR( "を検討しましょう。" );  
}
AC( Decision )
{
  ASK_NUMBER(
	     "0次連結性判定問題" ,
	     "高次連結性判定問題" ,
	     "勝敗判定問題" ,
	     "到達可能性問題" ,
	     "充足可能性問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( DecisionConnectedness );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionHigherConnectedness );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionGame );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionAccessibility );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionSatisfiability );
  }
}
AC( DecisionConnectedness )
{
  CERR( "幅優先探索やUnionFind" );
  CERR( "\\Mathematics\\Geometry\\Graph\\BreadthFirst" );
  CERR( "\\Utility\\VLTree\\UnionFindForest" );
  CERR( "を検討しましょう。" );
  CERR( "" );
}
AC( DecisionHigherConnectedness )
{
  CERR( "- 強連結性判定は深さ優先探索" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\DepthFirst" );
  CERR( "- 高次ホモロジー計算は適当な法での掃き出し法" );
  CERR( "を検討しましょう。" );
}
AC( DecisionGame )
{
  CERR( "ゲームの和に分解できる場合は最小単位で考察をし、グランディ数を実装しましょう。" );
  CERR( "これ以上分解できないゲームには整礎構造を探し、順序数の小さい順に実験をしましょう。" );
}
AC( DecisionAccessibility )
{
  ASK_YES_NO( "矩形領域の到達可能性問題ですか？" );
  if( reply == "yes" ){
    CERR( "迷路の攻略可能性は" );
    CERR( "- スタートとゴールが同一の弧状連結成分に属すこと" );
    CERR( "- スタートとゴールを分断する壁のパスの非存在性" );
    CERR( "などに翻訳しグラフ上の最小コスト移動問題に帰着させましょう。" );
  } else {
    CERR( "適切なグラフ上の最小コスト移動問題に帰着させましょう。" );
    CALL_AC( MinimisationMovingCost );
  }
  CERR( "" );
}
AC( DecisionSatisfiability )
{
  ASK_NUMBER(
	     "命題論理の充足性判定問題" ,
	     "二部グラフの充足可能性問題"
	     );
  if( num == num_temp++ ){
    CERR( "各命題変数の真理値を頂点とするグラフを考え連結性判定に帰着させて" );
    CALL_AC( DecisionConnectedness );
    CERR( "" );
    CERR( "区間処理による真理値更新は各種代数的データ構造を用いましょう。" );
    AC( QueryArray );
  } else if( num == num_temp++ ){
    CERR( "完全二部マッチング判定は最大二部マッチングに帰着させて" );
    AC( MaximisationBipartiteMatching );
  }
}
AC( Construction )
{
  ASK_NUMBER(
	     "数や配列や文字列の構築" ,
	     "経路の構築" ,
	     "戦略の構築" ,
	     "ソースコードの構築"
	     );
  if( num == num_temp++ ){
    CERR( "p進法や階差数列を検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "可能な経路の定めるグラフの問題に帰着させましょう。" );
    CALL_AC( DecisionAccessibility );
  } else if( num == num_temp++ ){
    CERR( "ゲームの問題に帰着させましょう。" );
    CALL_AC( DecisionGame );
  } else if( num == num_temp++ ){
    CERR( "正解を出力をするソースコードを提出しましょう。" );
  }
}
