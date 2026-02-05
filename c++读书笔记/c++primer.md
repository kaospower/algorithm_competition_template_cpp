# Part I The Basics  

# Chapter 2 Variables And Basic Types

# 2.3 Compound Types
A compound type is a type that is defined in terms of another type.C++ has several compound types,two of which--  
references and pointers.  

# 2.3.1 References
When we use the term reference,we mean "lvalue reference".  
A reference defines an alternative name for an object.   
Once initialized,a reference remains bound to its initial object. There is no way to rebind a reference to refer to a different object.  
Because there is no way to rebind a reference,references must be initialized.  
A reference may be bound only to an object,not to a literal or to the result of a more general expression.  
```c++
int ival=1024;
int &refVal=ival;
```
Reference Definitions:  
We can define multiple references in a single definition.  
```c++
int i=1024,i2=2048;
int &r=i,r2=i2;
```
# 2.3.2 Pointers
A pointer holds the address of another object.We get the address of an object by using the address-of operator(the & operator).
```c++
int *p=&ival;
```
When a pointer points to an object,we can use the deference operator(the * operator) to access that object.  
```c++
cout<<*p;
```
A null pointer does not point to any object.There are several ways to obtain a null pointer:  
```c++
int *p1=nullptr;
int *p2=0;
int *p3=NULL;
```
Modern C++ programs generally should avoid using NULL and use nullptr instead.  
It is illegal to assign an int variable to a pointer,even if the variable's value happens to be 0.  

void* Pointers:  
The type void* is a special pointer type that can hold the address of any object.  
Generally,we use a void* pointer to deal with memory as memory,rather than using the pointer to access the object stored in that memory.  

# 2.3.3 Understanding Compound Type Declarations
Defining Multiple Variables:  
```c++
int i=1024,*p=&i,&r=i;
```

Pointers to Pointers:  
A pointer is an object in memory,so like any object it has an address.Therefore,we can store the address of a pointer in another pointer.
```c++
int ival=1024;
int *pi=&ival;
int **ppi=&pi;
```

References to Pointers:
```c++
int i=42;
int* p;
int* &r=p;
r=&i;
*r=0;
```

# 2.4 const Qualifier
We can make a variable unchangeable by defining the variable's type as const.  
As usual,the initializer may be an arbitrarily complicated expression.  
Const variables are defined as local to the file.  

extern:
We want to define the const in one file,and declare it in the other files that use that object.  
To share a const object among multiple files,you must define the variable as extern.  
```c++
//file_1.cc
extern const int bufSize=fcn();

//file_1.h
extern const int bufSize;
```
```c++
const int bufSize=512;
```

# 2.4.1 References to const
C++ programmers tend to abbreviate the phrase "reference to const" as "const reference".
```c++
const int ci=1024;
const int &r1=ci;
```
In particular,we can bind a reference to const to a nonconst object,a literal,or a more general expression.  
```c++
int i=42;
const int &r1=i;
const int &r2=42;
const int &r3=r1*2;
```

# 2.4.2 Pointers and const
pointer to const:
```c++
const double pi=3.14;
const double* cptr=&pi; //cptr point to a double that is const
```

const Pointers:
We indicate that the pointer is const by putting the const after the *.  
This placement indicates that it is the pointer,not the pointed-to type,that is const.
```c++
int errNumb=0;
int* const curErr=&errNumb; //curErr will always point to errNumb
const double pi=3.14159;
const double* const pip=&pi; //pip is a const pointer to a const object
```

# 2.4.3 Top-Level const
We use the term top-level const to indicate that the pointer itself is a const.  
When a pointer can point to a const object,we refer to that const as a low-level const.  
The distinction between top-level and low-level matters when we copy an object. When we copy an object,top-level consts are ignored.

# 2.4.4 constexpr and Constant Expressions
A const expression is an expression whose value cannot change and that can be evaluated at compile time.  
Under the new standard, we can ask the compiler to verify that a variable is a constant expression by declaring the variable in a constexpr declaration.  
A constexpr function is a function is a function that can be used in a constant expression.  
Generally,it is a good idea to use constexpr for variables that you intend to use as constant expressions.  
```c++
constexpr int mf=20;
constexpr int limnit=mf+1;
```
Variables defined inside a function ordinarily are not stored at a fixed address.Hence,we cannot use a constexpr pointer to point to such variables.  
The address of an object defined outside of any function is a constant expression,and so may be used to initialize a constexpr pointer.  
When we define a pointer in a constexpr declaration,the constexpr specifier applies to the pointer,not the type to which the pointer points.  
```c++
const int* p=nullptr;
constexpr int* q=nullptr;

constexpr int i=42;//i must be defined outside any function
constexpr const int* p=&i;//p is a constant pointer to the const int i
```
# 2.5 Dealing with Types

# 2.5.1 Type Aliases
A type alias is a name that is a synonym for another type.  
We can define a type alias in one of two ways.Traditionally,we use a typedef.  
```c++
typedef double wages;//wages is a synonym for double
typedef wages base,*p;//base is a synonym for double,p for double*
```
The new standard introduced a second way to define a type alias,via an alias declaration:
```c++
using SI=Sales_item;
```

化名和复合数据类型作用在一起时会产生一些特殊的效果  
```c++
typedef char* pstring;
const pstring cstr=0;//cstr is a constant pointer to char
const pstring* ps;//ps is a pointer to a const pointer to char,const pstring is a const pointer to char,not a pointer to const char
```
# 2.5.2 The auto Type Specifier
主要用于存储表达式形式的变量,可以让编译器根据初始化信息推断表达式类型  
使用auto的变量必须要初始化
```c++
auto i=0,*p=&i;//auto 声明多个变量时,它们类型需要一致
```
auto ordinarily ignores top-level consts,low-level consts are kept.
If we want the deduced type to have a top-level const,we must say so explicitly:
```c++
int i=0;
const int ci=i;
const auto f=ci;
```

# Chapter 3 Strings,Vectors, and Arrays  

# 3.1 Namespace using Declarations  
# 作用域解析运算符(scope operator)::  
std::cout表明cout定义在命名空间std中  
```c++
//举例
using std::cin;
using std::endl;
注意using一次只能声明一个变量,当有多个变量需要声明时,需要用分号分隔写在多行
```

# 3.3 Library vector Type
```c++
#include<vector>
using std::vector;
//vector声明举例
vector<int>a(5,104);
vector<vector<int>>b(5,vector<int>(8,1000));
```
vector is a template,not a type.

# 3.4 Introducing Iterators
```c++
auto b=v.begin(),e=v.end();
begin()表示第一个元素的位置,end()表示最后一个元素右边一位的位置
当容器为空时,begin()==end()
当容器不空时,begin()!=end()
*iter,解引用,访问对象的引用
iter->mem,解引用并取回名为mem的成员
```
# Chapter 4 Expressions

# 4.5 Increment and Decrement Operators
```c++
a*=b--  
后缀--优先级高于*=,但是后缀-是先赋值,后--,因此代码执行顺序是:
a*=b;
b--;
```

# 4.6 The Member Access Operators

# Chapter 6 Functions

Functions can be overloaded(重载),meaning that the same name may refer to several different functions.  

# 6.1 Functions Basics

# Chapter 7 Classes

The fundamental ideas behind classes are data abstraction and encapsulation.  
Data abstraction is a programming technique that relies on the separation of interface and implementation.  
The interface of a class consists of the operations that users of the class can execute.  
The implementation includes the class' data members, the bodies of the functions that constitute the interface,   
and any functions needed to define the class that are not intended for general use.  
Encapsulation enforces the separation of a class' interface and implementation.  
A class that is encapsulated hides its implementation-users of the class can use the interface but have no access to the implementation.   
A class that uses data abstraction and encapsulation defines an abstract data type.  

# 7.2 Access Control and Encapsulation
In C++ we use access specifiers to enforce encapsulation.  
Members defined after a public specifier are accessible to all parts of the program.  
The public members define the interface to the class.  
Members defined after a private specifier are accessible to the member functions of the class but are not accessible to code that uses the class.  
The private sections encapsulate the implementation.  
A class uses protected for those members that it is willing to share with its derived classes but wants to protect from general access.

# Part II The C++ Library

# Chapter 12 Dynamic Memory

Smart pointers ensure that the objects to which they point are automatically freed when it is appropriate to do so.  
# Part III Tools for Class Authors

# Chapter 15 Object-Oriented Programming

# 15.1 OOP: An Overview
The key ideas in object-oriented programming are data abstraction,inheritance, and dynamic binding.  
Inheritance:  
Classes related by inheritance form a hierarchy.  
Typically there is a base class at the root of the hierarchy,from which the other classes inherit,directly or indirectly.  
These inheriting classes are known as derived classes.  
对于期望派生类自己定义的函数,基类将它们定义成虚拟的(virtual),即虚函数(virtual functions)
Dynamic binding(run-time binding):  
In C++,dynamic binding happens when a virtual function is called through a reference(or a pointer) to a base class.  

# Chapter 16 Template and Generic Programming(模版和泛型编程)

# 16.1 Defining a Template
A function template is a formula from which we can generate type-specific versions of that function.  
```c++
template<typename T>
int compare(const T &v1,const T &v2){
    return v1<v2?-1:1;
}
```

# Part IV Advanced Topics

# Chapter 17 Specialized Library Facilities

# Chapter 18 Tools for Large Programs

# Chapter 19 Specialized Tools and Techniques

# 动态内存

# 智能指针

# IO

# 特殊库tuple/bitset

# 异常和命名空间

# 控制内存分配


