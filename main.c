/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaurici <dmaurici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 16:35:09 by dmaurici          #+#    #+#             */
/*   Updated: 2026/07/02 16:35:09 by dmaurici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(&data);
	if (argc == 1)
		return (0);
	if (parse_args(argc, argv, &data))
		return (1);
	debug_print_stacks(&data);

	pb(&data, 1);
	debug_print_stacks(&data);

	pb(&data, 1);
	debug_print_stacks(&data);

	pa(&data, 1);
	debug_print_stacks(&data);

	free_data(&data);
	return (0);
}