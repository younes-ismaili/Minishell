/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <souchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:30:46 by souchen           #+#    #+#             */
/*   Updated: 2022/06/24 15:38:21 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <signal.h>
# include <fcntl.h>

# define Double_Quote '\"'
# define QUOTE '\''
# define D_QUOTE_S "\""
# define QUOTE_S "\'"
# define WHITE "\001\033[0m\002"
# define GREEN "\001\033[1;32m\002"
# define RED "\033[0;31m"

int	global_number;

typedef struct s_env
{
	char	**env;
	int		len;
	char	**tab1;
	char	**tab2;
	int		position;
}			t_env;

typedef struct s_divise
{
	int		number_command;
	int		initial;
	int		len;
	int		quote;
	int		pipe;
}			t_divise;

typedef struct s_arg
{
	char	*Lechemin;
	char	*to_exec;
	char    *txt_toprint;
	char	quote;
	char	*seconde;
	char	*first;
	int		i;
	int		init;
	int		len;
	int		position;
}			t_arg;

typedef struct s_struct
{
	int	builtin_exist;
	int		last_redir;
	int		output_fd;
	int		input_fd;
	int		cmp;
	char	*line_commande;
	char	*commande_tape;
	char	*home;
	char	*commands[600];
	char	**arguments;
	char	**path;
	t_env	env_aux;
	t_env	env;
	t_divise divise;
	t_arg	arg;
}			t_struct;

int	builtin_exist(t_struct *shell);
void	run_builtin(t_struct *shell);
char	*find_envernement(t_struct *shell, char *needle);
void	create_envernement(t_struct *shell, char **my_env);
void	len_envernement(t_struct *shell);
void	envernoment(t_struct *shell);
void	init_tabs_struct_env(t_struct *shell);
void	ft_exit(t_struct *shell);
void	free_line(char *line_read);
void	free1(char **array);
void	free2(char **array);
void	ft_unset(t_struct *shell);
void	rm_envernement(t_struct *shell);
void	Malloc_env_aux(t_struct *shell);
int		initial_path(t_struct *shell);
int		main(void);
void	print_welcome(void);
char *get_current_dir(void);
void    commande_tape(t_struct *shell);
char	*create_prompt(void);
void	run_commands(t_struct *shell);
void	run_commande_next(t_struct *shell);
void	fun_redirection(t_struct *shell);
void	execution(t_struct *shell);
//void execution(t_struct *shell);
void	divise_commande(t_struct *shell, char *in);
void	arguments_func(t_struct *shell);
int		argument_find_char(char *string, char needle);
void	free_arg(t_arg *arg);
void	finish_put_arg(t_struct *shell, t_arg *arg);
void init_divise_struct(t_struct *shell);
t_arg *initial_arg();
void ft_env(t_struct *shell);
void ft_export(t_struct *shell);
bool there_is_home(t_struct *shell);
int ft_cd(t_struct *shell);
void ft_pwd();
void ft_echo(t_struct *shell);
int init_echo(t_struct *shell, int n);
void print_echo(t_struct *shell,char* shell_print);
void ft_export(t_struct *shell);
void verify_if_env_exists(t_struct *shell, char **env_aux);
void ajouter_envernement(t_struct *shell, char *new_elem_tab1, char *new_elem_tab2);
void pipe_next(t_struct *shell, int i, char *command);
void inredirection(t_struct *shell);
void outredirection(t_struct *shell);
void next_run_commands(t_struct *shell);
void next(int i, t_struct *shell, char*commande_read);
void next_execution(t_struct *shell, int i);
void output_input(t_struct *shell);
void check_to_execute(t_struct *shell);
#endif