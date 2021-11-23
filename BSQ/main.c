/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:05:20 by lmunoz-m          #+#    #+#             */
/*   Updated: 2021/10/14 13:37:37 by guvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char *argv[])
{
	t_main	st;

	set_main(&st);
	if (argc == 1)
	{
		create_map();
		st.fl = arr_asg("input_map", c_l("input_map", 0), c_c("input_map"));
		if (m_cr(st.fl) == 1 || m_f(st.fl) == 1 || m_c(st.fl) == 1)
			func_fail();
		if (st.fl != 0)
			bsq(st.fl);
	}
	while (argc-- > 1)
	{
		if (c_l(argv[st.i], argc) != 0 && c_c(argv[st.i]) != 0)
		{
			st.fl = arr_asg(argv[st.i], c_l(argv[st.i], 0), c_c(argv[st.i]));
			if (m_cr(st.fl) == 1 || m_f(st.fl) == 1 || m_c(st.fl) == 1)
				func_aux(argv, st.fl, st.i);
			else if (st.fl != 0)
				func_aux2(argv, st.fl, st.i, argc);
		}
		st.i++;
	}
	return (0);
}
