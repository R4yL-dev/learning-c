#include "greatest.h"
#include "../libft/libft.h"
#include <stdio.h>

char	*LOWER = "abcdefghijklmnopqrstuvwxyz";
char	*UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char	*NUM = "0123456789";
char	*SPE = ".,-_!? +*";
char	*STR1 = ""; // 0
char	*STR2 = "Salut"; // 5
char	*STR3 = "Salut les amis comment aller vous"; // 33
char	*STR4 = "Salut les amis \ncomme\tnt al#ler 1283as d££$$$$ àäàéàéq1234vous"; // 70
char	*STR5 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. \
Duis rhoncus diam non elit hendrerit sollicitudin. Aenean nec commodo sapien, \
non bibendum lectus. In id metus at purus viverra sodales sed ut enim. Quisque \
tempor nisi ut justo rutrum, ut porta sapien condimentum. Morbi ex sem, gravida \
eget lobortis nec, tincidunt at neque. Ut accumsan, massa elementum scelerisque \
ultrices, enim eros suscipit turpis, eget mattis orci leo eget risus. Vestibulum \
aliquet mi pellentesque lorem posuere ultrices. Aenean ut odio nec est fringilla \
placerat. Duis non fermentum felis. Vestibulum pellentesque posuere ornare. Fusce \
sit amet ex imperdiet, consectetur tellus eu, tempus mi. Nulla non ex dui. Lorem \
ipsum dolor sit amet, consectetur adipiscing elit. Morbi ornare vehicula elit, \
porta mollis orci placerat in. Etiam dapibus justo sit amet ligula auctor venenatis \
et quis ligula. Suspendisse dignissim fermentum elit at ultrices. Integer tempor \
nunc mauris, sed gravida ipsum convallis et. Suspendisse varius condimentum vehicula. \
Donec laoreet varius orci, ut elementum tortor vehicula eget. Etiam tempus, neque \
finibus malesuada consequat, sem massa dapibus turpis, nec fringilla libero sapien \
vel risus. Praesent felis risus, pharetra in arcu nec, facilisis egestas nulla. Morbi \
in ipsum vel nulla pharetra posuere ut vel tortor. Vestibulum vulputate tempor tellus, \
rutrum ornare lectus lobortis sit amet. Nulla dictum at metus ac euismod. Sed rutrum \
suscipit orci vel sagittis. Quisque enim est, dictum a turpis sit amet, \
hendrerit venenatis eros. Suspendisse potenti. Nulla sed sem in leo eleifend \
fermentum. Vestibulum in arcu nulla. Nunc ut feugiat justo, in ullamcorper libero. \
Phasellus a odio in metus pulvinar sodales. Nunc cursus aliquam risus non ultrices. \
Cras pellentesque nisl non augue tincidunt gravida. Mauris tempor nibh vitae \
dolor efficitur faucibus. Suspendisse sit amet laoreet nulla, congue semper \
est. Cras sit amet iaculis massa, vel accumsan dolor. Aliquam arcu lacus, \
pretium pulvinar erat hendrerit, varius finibus enim. Proin et condimentum \
lacus. Vivamus quis est vehicula, dapibus turpis sit amet, tincidunt odio. \
In accumsan felis ut mauris vestibulum, vel vehicula ante sollicitudin. \
Pellentesque consectetur enim metus, vel pulvinar dui ornare eget. Sed \
auctor neque sit amet metus vestibulum dignissim. Cras condimentum \
malesuada efficitur. Maecenas luctus dictum ante maximus pretium. Duis \
id quam at odio suscipit condimentum quis eget arcu. Pellentesque lobortis \
ut lorem id euismod. Integer non consectetur ex. Fusce venenatis augue vel \
turpis ullamcorper, sed molestie ante pretium. Sed sed mattis libero. Cras \
id accumsan justo, eu viverra magna. Cras dictum viverra orci, a eleifend \
odio consectetur in. Aenean id lacus at arcu ullamcorper mollis. Nulla posuere \
lorem urna, in accumsan purus cursus sed. Duis sed lacinia nisi. Nullam ac tincidunt \
ligula. Curabitur condimentum fringilla tellus eget tincidunt. Orci varius natoque \
penatibus et magnis dis parturient montes, nascetur ridiculus mus."; // 3038


TEST	tests_ft_isalpha(void)
{
	int i;

	i = 0;
	while (LOWER[i])
	{
		ASSERT_GT(ft_isalpha(LOWER[i]), 0);
		i++;
	}
	i = 0;
	while (UPPER[i])
	{
		ASSERT_GT(ft_isalpha(UPPER[i]), 0);
		i++;
	}
	i = 0;
	while (NUM[i])
	{
		ASSERT_EQ(ft_isalpha(NUM[i]), 0);
		i++;
	}
	i = 0;
	while (SPE[i])
	{
		ASSERT_EQ(ft_isalpha(SPE[i]), 0);
		i++;
	}
	ASSERT_EQ(ft_isalpha(-0), 0);
	ASSERT_EQ(ft_isalpha(128), 0);
	ASSERT_EQ(ft_isalpha(100000), 0);
	ASSERT_EQ(ft_isalpha(-1), 0);
	ASSERT_EQ(ft_isalpha(-100000), 0);
	PASS();
}

TEST	tests_ft_isdigit(void)
{
	int i;

	i = 0;
	while (LOWER[i])
	{
		ASSERT_EQ(ft_isdigit(LOWER[i]), 0);
		i++;
	}
	i = 0;
	while (UPPER[i])
	{
		ASSERT_EQ(ft_isdigit(UPPER[i]), 0);
		i++;
	}
	i = 0;
	while (NUM[i])
	{
		ASSERT_GT(ft_isdigit(NUM[i]), 0);
		i++;
	}
	i = 0;
	while (SPE[i])
	{
		ASSERT_EQ(ft_isdigit(SPE[i]), 0);
		i++;
	}
	ASSERT_EQ(ft_isdigit(-0), 0);
	ASSERT_EQ(ft_isdigit(128), 0);
	ASSERT_EQ(ft_isdigit(100000), 0);
	ASSERT_EQ(ft_isdigit(-1), 0);
	ASSERT_EQ(ft_isdigit(-100000), 0);
	PASS();
}

TEST	tests_ft_isalnum(void)
{
	int i;

	i = 0;
	while (LOWER[i])
	{
		ASSERT_GT(ft_isalnum(LOWER[i]), 0);
		i++;
	}
	i = 0;
	while (UPPER[i])
	{
		ASSERT_GT(ft_isalnum(UPPER[i]), 0);
		i++;
	}
	i = 0;
	while (NUM[i])
	{
		ASSERT_GT(ft_isalnum(NUM[i]), 0);
		i++;
	}
	i = 0;
	while (SPE[i])
	{
		ASSERT_EQ(ft_isalnum(SPE[i]), 0);
		i++;
	}
	ASSERT_EQ(ft_isalnum(-0), 0);
	ASSERT_EQ(ft_isalnum(128), 0);
	ASSERT_EQ(ft_isalnum(100000), 0);
	ASSERT_EQ(ft_isalnum(-1), 0);
	ASSERT_EQ(ft_isalnum(-100000), 0);
	PASS();
}

TEST tests_ft_isascii(void)
{
	int i;

	i = 0;
	while (LOWER[i])
	{
		ASSERT_GT(ft_isascii(LOWER[i]), 0);
		i++;
	}
	i = 0;
	while (UPPER[i])
	{
		ASSERT_GT(ft_isascii(UPPER[i]), 0);
		i++;
	}
	i = 0;
	while (NUM[i])
	{
		ASSERT_GT(ft_isascii(NUM[i]), 0);
		i++;
	}
	i = 0;
	while (SPE[i])
	{
		ASSERT_GT(ft_isascii(SPE[i]), 0);
		i++;
	}
	ASSERT_GT(ft_isascii(-0), 0);
	ASSERT_EQ(ft_isascii(128), 0);
	ASSERT_EQ(ft_isascii(100000), 0);
	ASSERT_EQ(ft_isascii(-1), 0);
	ASSERT_EQ(ft_isascii(-100000), 0);
	PASS();
}

TEST tests_ft_isprint(void)
{
		int i;

	i = 0;
	while (LOWER[i])
	{
		ASSERT_GT(ft_isprint(LOWER[i]), 0);
		i++;
	}
	i = 0;
	while (UPPER[i])
	{
		ASSERT_GT(ft_isprint(UPPER[i]), 0);
		i++;
	}
	i = 0;
	while (NUM[i])
	{
		ASSERT_GT(ft_isprint(NUM[i]), 0);
		i++;
	}
	i = 0;
	while (SPE[i])
	{
		ASSERT_GT(ft_isprint(SPE[i]), 0);
		i++;
	}
	i = 0;
	while (i < 32)
	{
		ASSERT_EQ(ft_isprint(i), 0);
		i++;
	}

	ASSERT_EQ(ft_isprint(-0), 0);
	ASSERT_EQ(ft_isprint(128), 0);
	ASSERT_EQ(ft_isprint(100000), 0);
	ASSERT_EQ(ft_isprint(-1), 0);
	ASSERT_EQ(ft_isprint(-100000), 0);
	PASS();
}

TEST tests_ft_strlen(void)
{
	ASSERT_EQ(ft_strlen(STR1), 0);
	ASSERT_EQ(ft_strlen(STR2), 5);
	ASSERT_EQ(ft_strlen(STR3), 33);
	ASSERT_EQ(ft_strlen(STR4), 70);
	ASSERT_EQ(ft_strlen(STR5), 3038);
	PASS();
}

GREATEST_MAIN_DEFS();
int main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_TEST(tests_ft_isalpha);
	RUN_TEST(tests_ft_isdigit);
	RUN_TEST(tests_ft_isalnum);
	RUN_TEST(tests_ft_isascii);
	RUN_TEST(tests_ft_isprint);
	RUN_TEST(tests_ft_strlen);
	GREATEST_MAIN_END();
}
