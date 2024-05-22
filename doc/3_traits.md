## 萃取(traits)




```cpp

template<typename T>
class TraitsTest
{
public:
    /// The pointer type
    typedef T* pointer;
    /// The type pointed to
    typedef T  element_type;
    /// Type used to represent the difference between two pointers
    typedef ptrdiff_t difference_type;

    template<typename D>
    using rebind = D*;
};

class Data {
public:
    // 如果一个模板类中有内部模版，也就是类型内部模版-内部模版
    // 首先实例化 TraitsTest模板，并在这个作用域中继续实例化内部模板
    using type = typename TraitsTest<float>::template rebind<int>;


private:
    TraitsTest<Data> traits;
    type name;
};
```

这段代码展示了C++中模板类的使用，以及如何在一个类中使用另一个模板类的特性，并通过内部模板（nested template）进行类型别名的重新绑定。下面是对代码的详细解析：

### `TraitsTest`模板类

首先定义了一个名为`TraitsTest`的模板类，它接受一个类型参数`T`。这个类定义了几个类型别名（typedefs），用于描述与类型`T`相关的各种属性：

- `pointer`: 类型`T`的指针类型。
- `element_type`: 类型`T`本身，即指针所指向的类型。
- `difference_type`: 表示两个指针之间差值的类型，这里使用了标准库中的`ptrdiff_t`。

此外，`TraitsTest`还定义了一个内部模板`rebind`，它接受一个新的类型参数`D`，并返回类型`D`的指针类型。这是C++模板元编程中常用的一种技术，允许在不实例化原始模板的情况下操作类型。

### `Data`类

然后定义了一个名为`Data`的类，该类内部使用了`TraitsTest`模板类，并进行了以下操作：

1. **类型重绑定（Type Rebinding）**:
   - 在`Data`类中，使用了`TraitsTest<float>::template rebind<int>`来创建一个新的类型别名`type`。这意味着首先实例化`TraitsTest`模板类，传入`float`作为模板参数，然后调用该实例化的`rebind`内部模板，将`int`作为参数，得到的结果类型是`int*`。这是一种类型转换技巧，在处理模板和容器时特别有用，特别是在STL的allocator类中常见。

2. **使用TraitsTest实例**:
   - `Data`类中还直接实例化了`TraitsTest<Data>`，并将其实例命名为`traits`。这表明`Data`类想要利用`TraitsTest`提供的特性和功能来处理自身类型的某些方面，尽管在这个简化的例子中`traits`成员并未被进一步使用。

3. **成员变量**:
   - `Data`类声明了一个类型为`type`（即上面定义的`int*`）的成员变量`name`。这表明`Data`类计划以某种方式使用一个整数指针。



### 榨汁机

```cpp
// 将类型对应类型提取出俩
template <class _Iterator>
struct iterator_traits {
  typedef typename _Iterator::iterator_category iterator_category;
  typedef typename _Iterator::value_type        value_type;
  typedef typename _Iterator::difference_type   difference_type;
  typedef typename _Iterator::pointer           pointer;
  typedef typename _Iterator::reference         reference;
};

// 实现类型萃取，要单独处理Tp*类型
template <class _Tp>
struct iterator_traits<_Tp*> {
  typedef random_access_iterator_tag iterator_category;
  typedef _Tp                         value_type;
  typedef ptrdiff_t                   difference_type;
  typedef _Tp*                        pointer;
  typedef _Tp&                        reference;
};

// const Tp*类型也需要进行单独处理
template <class _Tp>
struct iterator_traits<const _Tp*> {
  typedef random_access_iterator_tag iterator_category;
  typedef _Tp                         value_type;
  typedef ptrdiff_t                   difference_type;
  typedef const _Tp*                  pointer;
  typedef const _Tp&                  reference;
};
```
