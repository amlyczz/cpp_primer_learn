cmake_minimum_required(VERSION 3.20)
project(cpp_primer_learn)

set(CMAKE_CXX_STANDARD 11)

add_executable(cpp_primer_learn main.cpp)

add_executable(initialize cp2/initialize.cpp cp2/extern_xx.cpp)

add_executable(refer_xx cp2/refer_xx.cpp)
add_executable(pointer_xx cp2/pointer_xx.cpp)
add_executable(const_xx cp2/const_xx.cpp)
add_executable(type_alias_xx cp2/type_alias_xx.cpp)
add_executable(decltype_xx cp2/decltype_xx.cpp cp2/Old_sales_data.h)
add_executable(string_xx cp3/string_xx.cpp)
add_executable(vector_xx cp3/vector_xx.cpp)
add_executable(array_xx cp3/array_xx.cpp)
add_executable(function_xx cp6_function/function_basic.cpp)
add_executable(function_xx2 cp6_function/function_main.cpp)
add_executable(function_changeable cp6_function/function_changeable.cpp cp6_function/function_changeable.h)
add_executable(function_pointer cp6_function/function_pointer.cpp)
add_executable(Sales_data cp7_class/Sales_data.h cp7_class/Sales_data.cpp)
add_executable(Screen cp7_class/Screen.cpp cp7_class/Screen.h cp7_class/Window_mgr.h cp7_class/Link_screen.h cp7_class/ConstRef.h)
add_executable(Data cp7_class/Data.cpp)