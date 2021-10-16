// LabeledList/a.hpp

#pragma once

#include "../../VLArray/a.hpp"
#include "../../../Mathematics/SetTheory/DirectProduct/a.hpp"

template <typename T , typename Key1 , typename... Key2>
class LabeledList
{

private:
  VLArray<DirectProduct<Key1,Key2...> > m_key;
  VLArray<T> m_t;

public:
  inline LabeledList();
  // �R�s�[�R���X�g���N�^�������Ȃ��^T���g���������͑����SartPointer<T>��p���A���̃R���X�g���N�^��K�p����WrappedType<SmartPointer<T> >��n���B
  inline LabeledList( const WrappedType<DirectProduct<Key1,Key2...> >& , const WrappedType<T>& );
  
  T& operator()( const Key1& , const Key2&... );
  const T& operator()( const Key1& , const Key2&... ) const;
  void Insert( const Key1& , const Key2&... , const T& );
  void Delete( const Key1& , const Key2&... );
  bool Contain( const Key1& , const Key2&... ) const;

};
