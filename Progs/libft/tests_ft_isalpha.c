#include "greatest.h"
#include "libft.h"
#include <stdio.h>

TEST should_be_more_1(void)
{
	ASSERT_LT(0, ft_isalpha('.'));
	PASS();
}

GREATEST_MAIN_DEFS();
int main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_TEST(should_be_more_1);
	printf("-- %d\n", ft_isalpha('.'));
	GREATEST_MAIN_END();
}
