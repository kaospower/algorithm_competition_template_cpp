# 3.3 Library vector Type
```c++
#include<vector>
using std::vector;
//vector声明举例
vector<int>a(5,104);
vector<vector<int>>b(5,vector<int>(8,1000));
```
vector is a template,not a type.

# 3.1 Namespace using Declarations
# 作用域解析运算符(scope operator)::
std::cout表明cout定义在命名空间std中
```c++
//举例
using std::cin;
using std::endl;
注意using一次只能声明一个变量,当有多个变量需要声明时,需要用分号分隔写在多行

```

# 7.2 Access Control and Encapsulation
In C++ we use access specifiers to enforce encapsulation.  
Members defined after a public specifier are accessible to all parts of the program.  
The public members define the interface to the class.  
Members defined after a private specifier are accessible to the member functions of the class but are not accessible to code that uses the class.  
The private sections encapsulate the implementation.  

# 模版

