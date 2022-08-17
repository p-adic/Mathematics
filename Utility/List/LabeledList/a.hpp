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

  bool m_has_temp;
  DirectProduct<Key1,Key2...> m_temp_key;
  
public:
  inline LabeledList();

  // �f�t�H���g�R���X�g���N�^�������Ȃ����R�s�[�R���X�g���N�^�����^T���g���������́A���̃R���X�g���N�^��K�p����B
  // �X�ɃR�s�[�R���X�g���N�^�������Ȃ��^T���g����������T�̑����SmartPointer<T>��p���A���̃R���X�g���N�^��K�p����B
  inline LabeledList( const WrappedType<DirectProduct<Key1,Key2...> >& , const WrappedType<T>& );

  const VLArray<DirectProduct<Key1,Key2...> >& inline GetKey() const noexcept;
  T& operator()( const Key1& , const Key2&... );
  const T& operator()( const Key1& , const Key2&... ) const;
  void Insert( const Key1& , const Key2&... , const T& );
  void Delete( const Key1& , const Key2&... );
  bool Contain( const Key1& , const Key2&... ) const;

  // Contain�łȂ��Ȃ��insert�����A���̌�operator()������B
  T& Ref( const Key1& , const Key2&... , const T& );

};
