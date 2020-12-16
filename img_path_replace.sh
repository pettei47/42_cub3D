for file in `\find . -name '*.cub'`; do
    sed -i -e 's/\.\/path_to_the_north_texture/\.\/images\/kita.xpm/g' $file
    sed -i -e 's/\.\/path_to_the_south_texture/\.\/images\/minami.xpm/g' $file
    sed -i -e 's/\.\/path_to_the_east_texture/\.\/images\/higashi.xpm/g' $file
    sed -i -e 's/\.\/path_to_the_west_texture/\.\/images\/nishi.xpm/g' $file
    sed -i -e 's/\.\/path_to_the_sprite_texture/\.\/images\/eagle.xpm/g' $file
done
