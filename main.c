#include "lem_in.h"

void		lem_errors(int errnum)
{
	if (errnum == ANT_ERR)
		ft_printf("{fd}ERROR: Invalid number of ants\n", 2);
	else if (errnum == INPUT_ERR)
		ft_printf("{fd}ERROR\n", 2);
	else if (errnum == MLC_ERR)
		ft_printf("{fd}Can't allocate memory\n", 2);
	else
		ft_printf("{fd}ERROR %d\n", 2, errnum);
	exit(errnum);
}

static void	lem_struct_init(t_lem *lem)
{
	lem->ants = 0;
	lem->start = 0;
	lem->end = 0;
	lem->room = 0;
	lem->room_end = 0;
	lem->rooms = NULL;
	lem->hash = NULL;
}

int			main()
{
	t_lem	lem;
	int		*path;
	int		i;

	lem_struct_init(&lem);
	lem_read(&lem);
	lem_make_hash(&lem);
	i = 0;
	path = (int*)malloc(sizeof(int) * lem.room);
	while (i < lem.room)
		path[i++] = -1;
	lem_find_paths(&lem, lem.start, path, 0);
	return 0;
}