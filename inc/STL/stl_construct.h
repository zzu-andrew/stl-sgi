/*
 *
 * Copyright (c) 1994
 * Hewlett-Packard Company
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.  Hewlett-Packard Company makes no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied warranty.
 *
 *
 * Copyright (c) 1996,1997
 * Silicon Graphics Computer Systems, Inc.
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.  Silicon Graphics makes no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied warranty.
 */

/* NOTE: This is an internal header file, included by other STL headers.
 *   You should not attempt to use it directly.
 */

#ifndef __SGI_STL_INTERNAL_CONSTRUCT_H
#define __SGI_STL_INTERNAL_CONSTRUCT_H

#include <new.h>   // 使用placement new 需要使用此文件

__STL_BEGIN_NAMESPACE

// construct and destroy.  These functions are not part of the C++ standard,
// and are provided for backward compatibility with the HP STL.  We also
// provide internal names _Construct and _Destroy that can be used within
// the library, so that standard-conforming pieces don't have to rely on
// non-standard extensions.

// Internal names

template <class _T1, class _T2>
inline void _Construct(_T1* __p, const _T2& __value) {
  //  使用指定的内存来初始化__T1类对象
  new ((void*) __p) _T1(__value);
}

template <class _T1>
inline void _Construct(_T1* __p) {
  //  使用placement order 使用当前内存new一个对象，其实还是使用了new里面创建独享时调用构造函数的功能
  new ((void*) __p) _T1();
}

template <class _Tp>
inline void _Destroy(_Tp* __pointer) {
  __pointer->~_Tp();
}

template <class _ForwardIterator>
void
__destroy_aux(_ForwardIterator __first, _ForwardIterator __last, __false_type)
{
  for ( ; __first != __last; ++__first)
    destroy(&*__first);
}

template <class _ForwardIterator> 
inline void __destroy_aux(_ForwardIterator, _ForwardIterator, __true_type) {}

template <class _ForwardIterator, class _Tp>
inline void 
__destroy(_ForwardIterator __first, _ForwardIterator __last, _Tp*)
{
  //   真正的析构函数是否真的值的调用
  typedef typename __type_traits<_Tp>::has_trivial_destructor
          _Trivial_destructor;
  __destroy_aux(__first, __last, _Trivial_destructor());
}

template <class _ForwardIterator>
inline void _Destroy(_ForwardIterator __first, _ForwardIterator __last) {
  __destroy(__first, __last, __VALUE_TYPE(__first));
}

inline void _Destroy(char*, char*) {}
inline void _Destroy(int*, int*) {}
inline void _Destroy(long*, long*) {}
inline void _Destroy(float*, float*) {}
inline void _Destroy(double*, double*) {}
#ifdef __STL_HAS_WCHAR_T
inline void _Destroy(wchar_t*, wchar_t*) {}
#endif /* __STL_HAS_WCHAR_T */

// --------------------------------------------------
// Old names from the HP STL.
// 通过new place order功能，调用构造函数
template <class _T1, class _T2>
inline void construct(_T1* __p, const _T2& __value) {
  _Construct(__p, __value);
}
// 调用析构函数
template <class _T1>
inline void construct(_T1* __p) {
  _Construct(__p);
}

template <class _Tp>
inline void destroy(_Tp* __pointer) {
  _Destroy(__pointer);
}

template <class _ForwardIterator>
inline void destroy(_ForwardIterator __first, _ForwardIterator __last) {
  // 利用 __type_traits 求取最适当的措施
  _Destroy(__first, __last);
}

__STL_END_NAMESPACE

#endif /* __SGI_STL_INTERNAL_CONSTRUCT_H */

// Local Variables:
// mode:C++
// End:
