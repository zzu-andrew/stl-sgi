//
// Created by wangyz38535 on 2024/5/23.
//

#ifndef STL_SGI_4_2_5_STL_LIST_H
#define STL_SGI_4_2_5_STL_LIST_H


struct _List_node_base {
    _List_node_base* _M_next;
    _List_node_base* _M_prev;
};

 //节点类型将具体数据和链表通过继承分开开来这样可以将存储指针的地方放到父类里面
// 这样一来构造节点链表也比较方便
template <class _Tp>
struct _List_node : public _List_node_base {
    _Tp _M_data;
};

struct _List_iterator_base {
    typedef size_t                     size_type;
    typedef ptrdiff_t                  difference_type;
    typedef bidirectional_iterator_tag iterator_category;

    // 全是public类型的成员变量
    _List_node_base* _M_node; // 迭代器内部当然要有一个普通的指针，指向list节点

    _List_iterator_base(_List_node_base* __x) : _M_node(__x) {}
    _List_iterator_base() {}

    // 真正执行　＋＋的其实就是链表向前进
    void _M_incr() { _M_node = _M_node->_M_next; }
    void _M_decr() { _M_node = _M_node->_M_prev; }
    // 是否相等看对应的指针是否是同一个
    bool operator==(const _List_iterator_base& __x) const {
        return _M_node == __x._M_node;
    }
    bool operator!=(const _List_iterator_base& __x) const {
        return _M_node != __x._M_node;
    }
};

//typedef _List_iterator<_Tp,_Tp&,_Tp*>             iterator;
template<class _Tp, class _Ref, class _Ptr>
struct _List_iterator : public _List_iterator_base {
    typedef _List_iterator<_Tp,_Tp&,_Tp*>             iterator;
    typedef _List_iterator<_Tp,const _Tp&,const _Tp*> const_iterator;
    typedef _List_iterator<_Tp,_Ref,_Ptr>             _Self;

    typedef _Tp value_type;
    typedef _Ptr pointer;
    typedef _Ref reference;
    typedef _List_node<_Tp> _Node;

    _List_iterator(_Node* __x) : _List_iterator_base(__x) {}
    _List_iterator() {}
    _List_iterator(const iterator& __x) : _List_iterator_base(__x._M_node) {}

    // 对节点取值其实取的事_M_data的值
    reference operator*() const { return ((_Node*) _M_node)->_M_data; }

#ifndef __SGI_STL_NO_ARROW_OPERATOR
    pointer operator->() const { return &(operator*()); }
#endif /* __SGI_STL_NO_ARROW_OPERATOR */

    _Self& operator++() {
        this->_M_incr();
        return *this;
    }
    //　＋＋　分为左＋＋和右　＋＋，这里这个是右＋＋
    _Self operator++(int) {
        _Self __tmp = *this;
        this->_M_incr();
        return __tmp;
    }
    _Self& operator--() {
        this->_M_decr();
        return *this;
    }
    _Self operator--(int) {
        _Self __tmp = *this;
        this->_M_decr();
        return __tmp;
    }
};



#endif //STL_SGI_4_2_5_STL_LIST_H
