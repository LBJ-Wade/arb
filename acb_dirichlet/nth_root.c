/*=============================================================================

    This file is part of ARB.

    ARB is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    ARB is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with ARB; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

=============================================================================*/
/******************************************************************************

    Copyright (C) 2016 Pascal Molin

******************************************************************************/

#include "acb_dirichlet.h"

static void
_acb_dirichlet_nth_root(acb_t res, ulong order, slong prec)
{
    fmpq_t t;
    fmpq_init(t);
    fmpq_set_si(t, 2, order);
    arb_sin_cos_pi_fmpq(acb_imagref(res), acb_realref(res), t, prec);
    fmpq_clear(t);
}

void
acb_dirichlet_nth_root(acb_t res, ulong order, slong prec)
{
    switch (order)
    {
       case 1:
           acb_one(res);
           break;
       case 2:
           acb_set_si(res, -1);
           break;
       case 4:
           acb_onei(res);
           break;
       default:
           _acb_dirichlet_nth_root(res, order, prec);
           break;
    }
}