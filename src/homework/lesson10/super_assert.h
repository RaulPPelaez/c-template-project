#ifndef SUPER_ASSERT_H
#define SUPER_ASSERT_H

#include <stdio.h>
#include <stdlib.h>

#ifndef SUPER_ASSERT_TRACE
#define SUPER_ASSERT_TRACE 0
#endif
#ifndef SUPER_ASSERT_PERMISSIVE
#define SUPER_ASSERT_PERMISSIVE 0
#endif
#ifndef SUPER_ASSERT_VERBOSE
#define SUPER_ASSERT_VERBOSE 0
#endif

#ifdef NDEBUG

#define super_assert(cond, msg) ((void)0)

#else

#if SUPER_ASSERT_TRACE
  #if SUPER_ASSERT_VERBOSE
    #define SA_TRACE_PASS(msg) fprintf(stderr, "[TRACE] %s:%d: %s\n", __FILE__, __LINE__, (msg))
  #else
    #define SA_TRACE_PASS(msg) fprintf(stderr, "[TRACE] %s\n", (msg))
  #endif
#else
  #define SA_TRACE_PASS(msg) ((void)0)
#endif

#if SUPER_ASSERT_VERBOSE
  #define SA_FAIL_PRINT(msg) fprintf(stderr, "[FAIL] %s:%d: %s\n", __FILE__, __LINE__, (msg))
#else
  #define SA_FAIL_PRINT(msg) fprintf(stderr, "[FAIL] %s\n", (msg))
#endif

#if SUPER_ASSERT_PERMISSIVE
  #define SA_FAIL_END() ((void)0)
#else
  #define SA_FAIL_END() abort()
#endif

#define super_assert(cond, msg)            \
  do {                                     \
    if (cond) {                            \
      SA_TRACE_PASS(msg);                  \
    } else {                               \
      SA_FAIL_PRINT(msg);                  \
      SA_FAIL_END();                       \
    }                                      \
  } while (0)

#endif /* NDEBUG */
#endif /* SUPER_ASSERT_H */
