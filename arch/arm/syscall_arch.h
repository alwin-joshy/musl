#define __SYSCALL_LL_E(x) \
((union { long long ll; long l[2]; }){ .ll = x }).l[0], \
((union { long long ll; long l[2]; }){ .ll = x }).l[1]
#define __SYSCALL_LL_O(x) 0, __SYSCALL_LL_E((x))

extern unsigned int __sysinfo;
#define CALL_SYSINFO(n, ...) (__sysinfo ? ((long(*)(long,...))__sysinfo)(n, ##__VA_ARGS__) : -1)

static inline long __syscall0(long n)
{
	return CALL_SYSINFO(n);
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

#define SYSCALL_FADVISE_6_ARG
