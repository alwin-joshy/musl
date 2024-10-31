#define __SYSCALL_LL_E(x) (x)
#define __SYSCALL_LL_O(x) (x)

#define __asm_syscall(...) do { \
	__asm__ __volatile__ ( "svc 0" \
	: "=r"(x0) : __VA_ARGS__ : "memory", "cc"); \
	return x0; \
	} while (0)

extern unsigned long __sysinfo;

#define CALL_SYSINFO(n, ...) ((long(*)(long,...))__sysinfo)(n, ##__VA_ARGS__)

static inline long __syscall0(long n)
{
	return CALL_SYSINFO(n)
}

static inline long __syscall1(long n, long a)
{
	return CALL_SYSINFO(n, a);
}

static inline long __syscall2(long n, long a, long b)
{
	return CALL_SYSINFO(n, a, b);
}

static inline long __syscall3(long n, long a, long b, long c)
{
	return CALL_SYSINFO(n, a, b, c);
}

static inline long __syscall4(long n, long a, long b, long c, long d)
{
	return CALL_SYSINFO(n, a, b, c, d);
}

static inline long __syscall5(long n, long a, long b, long c, long d, long e)
{
	return CALL_SYSINFO(n, a, b, c, d, e);
}

static inline long __syscall6(long n, long a, long b, long c, long d, long e, long f)
{
	return CALL_SYSINFO(n, a, b, c, d, e, f);
}
