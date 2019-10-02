/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berry <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 18:41:32 by berry             #+#    #+#             */
/*   Updated: 2019/06/22 23:26:27 by wdaher-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <dirent.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft/libft.h"
# include <unistd.h>
# include <pwd.h>
# include <time.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <limits.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# define MAX_TIME 15552000

void			error(char *message, int output);
void			print_usage();
void			open_error(char *path);

typedef struct	s_mylist
{
	struct dirent	*entry;
	char			name[NAME_MAX + 1];
	char			path[PATH_MAX + 1];
	struct s_mylist	*next;
}				t_mylist;

typedef struct	s_options
{
	int			verb;
	int			recur;
	int			all;
	int			rev;
	int			sort_bytime;
	int			index;
	int			full_time;
	t_mylist	*errors;
	t_mylist	*files;
	t_mylist	*all_args;
}				t_options;

void			white(void);
void			bold_green(void);
void			magenta(void);
void			bold_blue(void);

t_options		*myparser(int ac, char **av);
t_options		*options_new();
void			load_args(int ac, char **av, t_options *options);

void			print_details(char *path, struct stat *dirstat, t_options *options);	
void			detailed_display(t_mylist *dirp, t_options *options);
void			display_one_mylist(t_mylist *dirp);
void			display_recur(char *path, t_options *options);

void			get_mode(char *path, struct stat *filestat);
char			*get_ownername(struct stat *filestat);
char			*get_ownergroup(struct stat *filestat);
char			*get_size(struct stat *filestat);
char			*get_atime(struct stat *filestat, t_options *options);
char			*get_mtime(struct stat *filestat, t_options *options);
char			*get_ctime(struct stat *filestat, t_options *options);
char			*get_xtime(char x, struct stat *filestat, t_options *options);
char			*get_nlinks(struct stat *filestat);
t_mylist		*get_dirs(char *name, t_options *options);
long long		read_total(t_mylist *dirp);

void			sort_xtime(char x, t_mylist *lst, t_options *options);
void			sort_ascii(t_mylist *lst, t_options *options);
void			sort_sametime(char x, t_mylist *lst);
void			sort_args(t_options *options);

t_mylist		*init_mylist(char *name, char *path);
void			append_byascii(t_mylist **dest, t_mylist *new);
void			mylist_append_args(t_mylist **dest, t_mylist *new);
void			mylist_del(t_mylist **target);
void			mylist_del_top(t_mylist **target);
void			mylist_rev(t_mylist **lst);
void			mylist_merge(t_mylist **begin, t_mylist *tail);

int				is_directory(const char *path);
int				is_linked(const char *path);
int				ft_strchrl(const char *s, int c);
time_t			get_xtime_t(char x, t_mylist *target);
int				dirs_n(t_mylist *dirp);
void			mylist_copy(t_mylist *dest, t_mylist *src);
void			mylist_swap(t_mylist *a, t_mylist *b);
void			print_dir(t_mylist *dirp);
void			print_linked(t_mylist *dirp);
int				is_there_capital(t_mylist *dirp);
int				is_capital(char *s);

#endif
