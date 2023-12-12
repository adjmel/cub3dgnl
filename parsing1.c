#include "cub3d.h"

void	init_struct(t_parsing	*parsing)
{
    //parsing->text_file = NULL;
    
    // Initialisation des valeurs RGB dans la structure
    parsing->floor_value_1 = -1;  // Valeur par défaut -> mettre 0 ?
    parsing->floor_value_2 = -1;  // Valeur par défaut
    parsing->floor_value_3 = -1;  // Valeur par défaut
    parsing->sky_value_1 = -1;  // Valeur par défaut
    parsing->sky_value_2 = -1;  // Valeur par défaut
    parsing->sky_value_3 = -1;  // Valeur par défaut

    //init textures
    parsing->no_texture_value = NULL;
    parsing->we_texture_value = NULL;
    parsing->so_texture_value = NULL;
    parsing->ea_texture_value = NULL;
    parsing->s_texture_value = NULL;

    //init map
    parsing->map = NULL;
    parsing->config_elements = NULL;
	parsing->copied_map = NULL;
	parsing->map_height = 0;

    //ETC
}

int parsing(char *file_cub3d_name)
{
    t_parsing *parsing;
    int fd = open(file_cub3d_name, O_RDONLY);
    t_data	data; //sert a rien en vrai

    init_struct(&data.parsing);

    //parsing pointe vers la même structure que data.parsing
    parsing = &data.parsing;
    if (fd != -1)
        {
        // Le fichier existe.
        if (put_text_struct(&data.parsing) == 1)
        {
            printf("Error : text cannot be put into structure\n");
            return 1;
        }
        // Vérifiez si parsing->text_file a été correctement initialisé
 
        //printf("ici 2 = %s\n", parsing->map[15]);
        //printf("ici 3 = %s\n", parsing->config_elements[5]);

        if (*parsing->num_lines_ptr == 0)
            {
                printf("Error : the file is empty\n");
                return 1;
            }

        if (!parsing->map || !parsing->config_elements) 
        {
            printf("Error: struct is not properly initialized\n");
            return 1;
        }
        // printf("ici = %s\n", parsing->text_file[9]);

        if (parsing_cub3d(parsing->config_elements, &data.parsing) == 1)
        {
            //faire mes frees si parsing errone
            return 1;
        }
        
        close(fd); // Ferme le descripteur de fichier si terminé (a revoir si ok)
    } 
    else 
    {
        printf("Error : the file does not exist\n");
        return (1);
    }
return (0);
}