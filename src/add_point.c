

#include "fdf.h"

void	add_point_end(t_point **point, t_point pt)
{
	t_point *tmp;
	t_point *list;

	tmp = NULL;
	if ((tmp = (t_point*)malloc(sizeof(t_point))))
	{
		tmp->x = pt.x;
		tmp->y = pt.y;
		tmp->z = pt.z;
		tmp->c = pt.c;
		tmp->firstx = pt.firstx;
        tmp->lasty = pt.lasty;
        tmp->next = NULL;
		if (!*point)
			*point = tmp;
		else
		{
			list = *point;
			while (list->next)
				list = list->next;
			list->next = tmp;
		}
	}
	return ;
}
