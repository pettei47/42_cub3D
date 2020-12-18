i=0
count=128
while [ $i -lt $count ]
do
	file="${i}_cap.cub"
	x=`expr $i + 640`
	echo $x
	cp ok_test.cub $file
	sed -i -e "s/640/$x/" $file
	$i=$((i++))
	echo $i
done
