#ifndef __N1GHTTHEF0X_LIBKITSUNE_MACROS_HPP
#define __N1GHTTHEF0X_LIBKITSUNE_MACROS_HPP

#include "Memory.hpp"

#define KITSUNE_MODEL(type) \
typedef const type Const##type; \
typedef N1ghtTheF0x::LibKitsune::Ref<##type> Ref##type; \
typedef N1ghtTheF0x::LibKitsune::Ptr<##type> Ptr##type; \
typedef N1ghtTheF0x::LibKitsune::Ref<Const##type> RefConst##type; \
typedef N1ghtTheF0x::LibKitsune::Ptr<Const##type> PtrConst##type;
#define KITSUNE_CLASS(type) \
class type; \
KITSUNE_MODEL(type)
#define KITSUNE_STRUCT(type) \
struct type; \
KITSUNE_MODEL(type)
#define KITSUNE_SINGLETON(type) \
private: \
    static type _instance; \
public: \
    type(const type &) = delete; \
    static type &instance() { return _instance; };
#endif