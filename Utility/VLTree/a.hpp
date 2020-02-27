// c:/Users/user/Documents/Programming/Utility/VLTree/a.hpp

#pragma once

// VLTtree<T>���g�����߂ɂ��̃t�@�C����include����B
// Iterator��s���S�^�Ƃ��Ďg�����Ƃ�����邽�߂Ɉȉ���include���Ă���B
#include "Entry/a.hpp"
#include "Iterator/a.hpp"
#include "SubTree/Const/a.hpp"

// SequentialIterator���g�����͍X��Iterator/Sequential/a_Body.hpp��include����K�v������B

template <typename T>
class VLTree :
  public VLSubTree<T>
{

public:
  template <typename... Args> inline VLTree( const Args&... );
  inline ~VLTree();

  template <typename Arg> VLTree<T>& operator=( const Arg& );

};
