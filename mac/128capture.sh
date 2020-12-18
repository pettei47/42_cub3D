i=0
count=128
while [ $i -lt $count ]
do
	file="capture_map/${i}_cap.cub"
	dir="capture_file/${i}_cap.bmp"
	./cub3D $file --save
	mv capture_cub3D.bmp $dir
	let i++
done
