/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:17:34 by rluari            #+#    #+#             */
/*   Updated: 2024/04/25 15:16:20 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T> void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T> T min(T a, T b) {
    if (a == b)
        return b;
    return (a < b) ? a : b;
}

template<typename T> T max(T a, T b) {
    if (a == b)
        return b;
    return (a > b) ? a : b;
}
