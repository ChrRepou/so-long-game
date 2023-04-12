/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:30:12 by crepou            #+#    #+#             */
/*   Updated: 2022/12/22 16:16:27 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <errno.h>
# include <stdarg.h>
# define HEX "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

int		ft_printf(const char *str, ...);
char	*ft_itoa_u(unsigned int n);
int		ft_type_d(va_list args);
int		ft_type_u(va_list args);
int		ft_type_s(va_list args);
int		ft_type_c(va_list args);
int		ft_type_perc(void);
int		ft_print_null(void);
int		ft_dec_to_hex_ui(unsigned int val, char type);
int		ft_dec_to_hex(size_t val);

#endif