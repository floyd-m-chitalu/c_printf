#include "cprintf/cprintf.h"

int main(void)
{
	bool exec_ok = true;
	
	try
	{
		cprintf("foo $r`red\n");
	}
	catch (_cpf_type::error &e)
	{
		fprintf(stderr, "cprintf sample failed\n%s\n", e.what());
		exec_ok = false;;
	}
	return exec_ok ? EXIT_SUCCESS : EXIT_FAILURE;
}