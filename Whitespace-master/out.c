#include <assert.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef __cplusplus
#  if defined(_MSC_VER)
#    define inline      __inline
#    define __inline__  __inline
#  elif !defined(__GNUC__) && (!defined(__STDC_VERSION__) || __STDC_VERSION__ < 199901L)
#    define inline
#    define __inline
#  endif
#endif

#define STACK_SIZE 65536
#define HEAP_SIZE 65536
#define CALL_STACK_SIZE 65536

#define LENGTHOF(array) (sizeof(array) / sizeof((array)[0]))
#define SWAP(type, a, b) \
  do { \
    type __tmp_swap_var__ = *(a); \
    *(a) = *(b); \
    *(b) = __tmp_swap_var__; \
  } while (0)

inline static int  pop(void);
inline static void push(int e);
inline static void dup_n(size_t n);
inline static void slide(size_t n);
inline static void swap(void);
inline static void arith_add(void);
inline static void arith_sub(void);
inline static void arith_mul(void);
inline static void arith_div(void);
inline static void arith_mod(void);
inline static void heap_store(void);
inline static void heap_read(void);

static int stack[STACK_SIZE];
static int heap[HEAP_SIZE];
static jmp_buf call_stack[CALL_STACK_SIZE];
static size_t stack_idx = 0;
static size_t call_stack_idx = 0;


int main(void)
{
  push(80);
  putchar(pop());
  push(73);
  putchar(pop());
  push(78);
  putchar(pop());
  push(58);
  putchar(pop());
  push(32);
  putchar(pop());
  push(0);
  fflush(stdout);
  scanf("%d", &heap[pop()]);
  push(0);
  heap_read();
  push(33355524);
  arith_sub();
  if (!pop()) {
    goto T;
  }
  push(78);
  putchar(pop());
  push(79);
  putchar(pop());
  exit(EXIT_SUCCESS);

T:
  push(79);
  putchar(pop());
  push(75);
  putchar(pop());
  push(10);
  putchar(pop());
  push(0);
  heap_read();
  push(33355454);
  arith_sub();
  dup_n(0);
  putchar(pop());
  push(6);
  arith_add();
  dup_n(0);
  putchar(pop());
  push(11);
  arith_sub();
  dup_n(0);
  putchar(pop());
  push(6);
  arith_add();
  dup_n(0);
  putchar(pop());
  push(24);
  arith_add();
  dup_n(0);
  putchar(pop());
  push(26);
  arith_sub();
  dup_n(0);
  putchar(pop());
  push(40);
  arith_add();
  dup_n(0);
  putchar(pop());
  push(25);
  arith_sub();
  dup_n(0);
  putchar(pop());
  push(36);
  arith_add();
  dup_n(0);
  putchar(pop());
  push(66);
  arith_sub();
  dup_n(0);
  putchar(pop());
  push(16);
  arith_add();
  dup_n(0);
  putchar(pop());
  push(14);
  arith_add();
  dup_n(0);
  putchar(pop());
  push(14);
  arith_add();
  dup_n(0);
  putchar(pop());
  push(27);
  arith_sub();
  dup_n(0);
  putchar(pop());
  push(5);
  arith_add();
  dup_n(0);
  putchar(pop());
  push(29);
  arith_add();
  dup_n(0);
  putchar(pop());
  push(4);
  arith_sub();
  dup_n(0);
  putchar(pop());
  push(4);
  arith_add();
  dup_n(0);
  putchar(pop());
  push(28);
  arith_sub();
  dup_n(0);
  putchar(pop());
  push(22);
  arith_add();
  dup_n(0);
  putchar(pop());
  push(34);
  arith_sub();
  dup_n(0);
  putchar(pop());
  push(55);
  arith_sub();
  dup_n(0);
  putchar(pop());
  exit(EXIT_SUCCESS);

  return EXIT_SUCCESS;
}


inline static int pop(void)
{
  assert(stack_idx < LENGTHOF(stack));
  return stack[--stack_idx];
}


inline static void push(int e)
{
  assert(stack_idx < LENGTHOF(stack));
  stack[stack_idx++] = e;
}


inline static void dup_n(size_t n)
{
  assert(n < stack_idx && stack_idx < LENGTHOF(stack) - 1);
  stack[stack_idx] = stack[stack_idx - (n + 1)];
  stack_idx++;
}


inline static void slide(size_t n)
{
  assert(stack_idx > n);
  stack[stack_idx - (n + 1)] = stack[stack_idx - 1];
  stack_idx -= n;
}


inline static void swap(void)
{
  assert(stack_idx > 1);
  SWAP(int, &stack[stack_idx - 1], &stack[stack_idx - 2]);
}


inline static void arith_add(void)
{
  assert(stack_idx > 1);
  stack_idx--;
  stack[stack_idx - 1] += stack[stack_idx];
}


inline static void arith_sub(void)
{
  assert(stack_idx > 1);
  stack_idx--;
  stack[stack_idx - 1] -= stack[stack_idx];
}


inline static void arith_mul(void)
{
  assert(stack_idx > 1);
  stack_idx--;
  stack[stack_idx - 1] *= stack[stack_idx];
}


inline static void arith_div(void)
{
  assert(stack_idx > 1);
  stack_idx--;
  assert(stack[stack_idx] != 0);
  stack[stack_idx - 1] /= stack[stack_idx];
}


inline static void arith_mod(void)
{
  assert(stack_idx > 1);
  stack_idx--;
  assert(stack[stack_idx] != 0);
  stack[stack_idx - 1] %= stack[stack_idx];
}


inline static void heap_store(void)
{
  int value = pop();
  int addr  = pop();
  assert(0 <= addr && addr < (int) LENGTHOF(heap));
  heap[addr] = value;
}


inline static void heap_read(void)
{
  int addr = pop();
  assert(0 <= addr && addr < (int) LENGTHOF(heap));
  push(heap[addr]);
}
