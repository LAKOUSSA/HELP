#include <mlx.h>
#include <stdlib.h>

struct		s_mlx
{
	void	*mlx;
	void	*win;
	void	*wind;
	int		h;
	int		w;
	void	*audio;
};
int	main(void)
{
	struct s_mlx	new;
	char			*wav_file;

	new.w = 500;
	new.h = 500;
	wav_file = "scape.wav";
	new.mlx = mlx_init();
	if (!new.mlx)
		exit(1);
	new.win = mlx_new_window(new.mlx, new.w, new.h, "audio");
	if (!new.win)
		exit(1);
	new.audio = mlx_xpm_file_to_image(new.mlx, wav_file, &new.w, &new.h);
	if (!new.audio)
		exit(1);
	mlx_put_image_to_window(new.mlx, new.win, new.audio, 0, 0);
	mlx_loop(new.mlx);
	return (0);
}
