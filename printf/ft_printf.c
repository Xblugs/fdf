/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cczerwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:44:47 by cczerwin          #+#    #+#             */
/*   Updated: 2024/12/05 16:44:54 by cczerwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <limits.h>
// "%-0# +(width).(prec)(type)\0"
int	ft_printf(const char *str, ...);

int	ft_printf(const char *str, ...)
{
	const char	type_ok[10] = {'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', '%', 0};
	int			i;
	int			count;
	t_param		par;
	va_list		args;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i] != 0)
	{
		if (str[i] == '%')
		{
			i = i + ft_printinit(&str[i], &par, args);
			if (ft_isset(&str[i], type_ok))
				count += ft_printtype(&str[i], par, args);
			else
				count = count + write (1, "%", 1);
		}
		else
			count = count + write (1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
/*
int	main(void)
{
	int		a = '~';
	int		b = 0;
	void	*c = NULL;
	// Test simple print (31)
	b = ft_printf("\n++ Simple print test ++\n-> \\n\n");
	ft_printf("%d char printed\n\n", b);

	// Ghost test - NULL input
	ft_printf("");
	ft_printf("1:%s\n", "");
	ft_printf("2:%s\n", NULL);
	ft_printf("3:%c\n", "");
	ft_printf("4:%c\n\n", NULL);

	// Test for incorrect type (as well as %%)
	ft_printf("++ Test for incorrect type: ++\n");
	ft_printf("Print %%h: a = %h\n\n", a);


		/////////////	Character	////////////////

	// Test for %c, print count (16) then with flags
	ft_printf("++ Test for %%c: ++\n");
	b = ft_printf("Print %%c: a = %c\n", a);
	ft_printf("%d char printed\n\n", b);
	ft_printf("Print %%c: -5c =|%-5c|\t 5c =|%5c|\t\n\n\n", a, a);


		/////////////	String	////////////////

	// Test for %s, print count (17 + \n) then with flags
	ft_printf("++ Test for %%s: ++\n");
	b = ft_printf("Print %%s: %s\n", "Testing");
	ft_printf("%d char printed\n\n", b);

	// Test width then precision
	ft_printf("++ Test with (width) OR (precision) ++\n");
	ft_printf("Print %%s: |%-15s|\n", "Testing '-'");
	ft_printf("Print %%s: |%1s|\t|%10s|\n", "w < len", "w > len");
	ft_printf("Print %%s: |%.5s|\t|%.20s|\n\n", "p < len", "p > len");

	// Same but left justified (prec alone doesn't use '-')
	ft_printf("++ Test with (width) AND '-' ++\n");
	ft_printf("Print %%-s: |%-1s|\t|%-10s|\n\n", "w < len", "w > len");

	// Both parameter
	ft_printf("++ Test with (width) (precision) AND '-' ++\n");
	ft_printf("Print %%-.s: |%10.2s|\t|%-10.2s|\n", "test1234", "test1234");
	ft_printf("Print %%-.s: |%2.10s|\t|%-2.10s|\n\n", "test1234", "test1234");

	ft_printf("++ Specific case \".0\" OR \".\" ++\n");
	ft_printf("Print %%.s: |%.0s| |%.s|\n", "no out", "put");
	ft_printf("Print %%.s: |%2.0s| |%2.s|\n", "only", "padding");
	ft_printf("Print %%-.s: |%-2.0s| |%-2.s|\n\n", "the", "same");

	ft_printf("++ Specific case NULL input with flags ++\n");
	ft_printf("Print %%s: s = |%1s|\ts = |%7s|\n", NULL, NULL);
	ft_printf("Print %%s: s = |%.1s|\ts = |%.7s|\n", NULL, NULL);
	ft_printf("Print %%s: s = |%7.1s|\ts = |%7.7s|\n\n", NULL, NULL);

	ft_printf("++ Same but left padded ++\n");
	ft_printf("Print %%s: s = |%-1s|\ts = |%-7s|\n", NULL, NULL);
	ft_printf("Print %%s: s = |%-.1s|\ts = |%-.7s|\n", NULL, NULL);
	ft_printf("Print %%s: s = |%-7.1s|\ts = |%-7.7s|\n\n", NULL, NULL);
	// Testing '*' argument for both width and prec
	ft_printf("++ Test %*.* ++\n");
	ft_printf("Print %%-.s: |%*s|\t|%.*s|\n\n\n", 8, "born2print", 2, "test");


		/////////////	Signed int	////////////////

	ft_printf("++ Test for %%d: ++\n");
	b = ft_printf("Print %%d: a = %d\n", a);
	ft_printf("%d char printed\n\n", b);

	ft_printf("Print %%d: d = %d\t -d = %d\t d = %d\n", a, -a, 0);
	ft_printf("Print %%d: max = %d\t min = %d\n\n\n", 2147483647, -2147483648);
	ft_printf("++ Test with ' ' then '+' ++\n");
	ft_printf("Print %%d: d = |% d|\td = |%+d|\n", 42, 42);
	ft_printf("Print %%d: d = |%d|\td = |%+d|\n\n", -42, -42);

	ft_printf("++ Test with width then prec ++\n");
	ft_printf("Print %%d: d = |%1d|\td = |%3d|\n", 42, 42);
	ft_printf("Print %%d: d = |%.1d|\td = |%.3d|\n\n", 42, 42);

	ft_printf("++ Same but left justified ++\n");
	ft_printf("Print %%d: d = |%-1d|\td = |%-3d|\n", 42, 42);
	ft_printf("Print %%d: d = |%-.1d|\td = |%-.3d|\n\n", 42, 42);

	ft_printf("++ Test with width AND prec ++\n");
	ft_printf("Print %%d: d = |%6.4d|\td = |%6.1d|\n", 42, 42);
	ft_printf("Print %%d: d = |%1.5d|\td = |%3.5d|\n\n", 42, 42);

	ft_printf("++ Same but left justified ++\n");
	ft_printf("Print %%-d: -d = |%-6.4d|\t-d = |%-6.1d|\n", 42, 42);
	ft_printf("Print %%-d: -d = |%-1.5d|\t\t-d = |%-3.5d|\n\n", 42, 42);

	ft_printf("++ Both previous test but with sign ++\n");
	ft_printf("Print %%+d: +d = |%+6.4d|\t+d = |%+6.1d|\n", 42, 42);
	ft_printf("Print %%+d: +d = |%+1.5d|\t+d = |%+3.5d|\n\n", 42, 42);

	ft_printf("Print %%-+d: -+d = |%-+6.4d|\t-+d = |%-+6.1d|\n", 42, 42);
	ft_printf("Print %%-+d: -+d = |%-+1.5d|\t-+d = |%-+3.5d|\n\n", 42, 42);

	ft_printf("Print %%di: |%5.0d|\t |%-5.i|\n\n", 0, 0);


			/////////////	Unsigned int	////////////////

	// Test for %u, print count (17 + \n) then with flags
	ft_printf("++ Test for %%u: ++\n");
	b = ft_printf("Print %%u: a = %u\n", a);
	ft_printf("%d char printed\n\n", b);

	// Negative number works but result in an underflow
	// printf gives a compil. error because he consider the number as a long
	// meanwhile our function doesn't trigger gcc
	ft_printf("Print %%u: a = %u\n", -200);
	//printf("Printf %%u: a = %u\n", -200);
	//printf("Printf %%u: a = %u\n", (unsigned int)3000000000);
	ft_printf("Print %%u: u = %u\td = %d\n\n", 3000000000, 3000000000);

	ft_printf("++ Test with width ++\n");
	ft_printf("Print %%u: u = |%1u|\tu = |%5u|\n\n", 42, 42);
	ft_printf("++ Test with prec ++\n");
	ft_printf("Print %%u: u = |%.1u|\tu = |%.5u|\n\n", 42, 42);

	ft_printf("++ Same but left justified ++\n");
	ft_printf("Print %%u: u = |%-1u|\tu = |%-5u|\n", 42, 42);
	ft_printf("Print %%u: u = |%-.1u|\tu = |%-.5u|\n\n", 42, 42);

	ft_printf("++ Test with width AND prec ++\n");
	ft_printf("Print %%u: u = |%1.1u|\tu = |%3.5u|\n", 42, 42);
	ft_printf("Print %%u: u = |%5.3u|\tu = |%5.6u|\n\n", 42, 42);

	ft_printf("++ Same but with '-' ++\n");
	ft_printf("Print %%u: u = |%-1.1u|\tu = |%-3.5u|\n", 42, 42);
	ft_printf("Print %%u: u = |%-5.3u|\tu = |%-5.6u|\n", 42, 42);
	ft_printf("Print %%u: u = |%u|\t\t\t.0u = |%.0u|\n", 0, 0);
	ft_printf("Print %%u: .u = |%.u|\n\n", 0);

	ft_printf("Print %%u: u = |%6.5u|\tu = |%-6.5u|\n\n", 42, 42);
	// paco was here


			/////////////	Hexa	////////////////

	ft_printf("++ Test for %%x: ++\n");
	b = ft_printf("Print %%x: a = %x\n", 0xFF);
	ft_printf("%d char printed\n\n", b);

	ft_printf("Print %%x: a = |%#x|\t a = |%#X|\n", 0xFF, 0xFF);
	b = ft_printf("Print %%x: a = |%-2x|\t a = |%#X|\n", -1, 0xFF);
	ft_printf("%d char printed\n\n", b);

	ft_printf("Print %%x: a = |%#x|\t a = |%#X|\n\n", 0, 0);
	// paco was also here


			/////////////	Pointer	////////////////

	ft_printf("++ Test for %%p: ++\n");
	b = ft_printf("Print %%p: c = |%p|\n", c);
	ft_printf("%d char printed\n\n", b);
	b = ft_printf("Print %%p: a = |%20p|\n", &a);
	ft_printf("%d char printed\n\n", b);

	b = printf("Print %%p: a = |%p|\n", &a);
	ft_printf("%d char printed\n\n", b);

	ft_printf("Print %%p: a = |%p|\n", -1);
	ft_printf("Print %%p: a = |%p|\n\n", 1);
	//printf("Print %%p: a = |%p|\n", 1);

	//ft_printf("Print %%p: a = |%-9p|\t |%-10p|\n", LONG_MIN, LONG_MAX);
	//ft_printf("Print %%p: a = |%-11p|\t\t |%-12p|\n", INT_MIN, INT_MAX);
	//ft_printf("Print %%p: a = |%-13p|\t |%-14p|\n\n", ULONG_MAX, -ULONG_MAX);

	ft_printf("%-108p\n" ,(void*)11646713326646154808lu);
	return (0);
}*/
