#!/bin/bash

upload_to_remote () {
	remote="ghorbanzade.com"
	puts=$(print_put_statements_from_file $1)
	
	ftp $remote <<-EOT
	binary
	cd public_html
	$puts
	quit
	EOT
}

print_put_statements_from_file () {
	src_dir="bin/documents/"
	dst_dir="bin/courses/CS240-2016S/"
	while IFS='' read -r line || [[ -n "$line" ]]; do
		if [ ! -z "$line" ] && [ ${line::1} != '#' ]; then
			line=($line)
			if [ ${#line[@]} == 2 ]; then
				src_path=$src_dir${line[0]}
				dst_path=$dst_dir${line[1]}
			else
				src_path=$src_dir$line
				dst_path=$dst_dir$line
			fi
			echo "put $src_path $dst_path"
		fi
	done < "$1"
}

upload_to_remote cfg/remote-files.list
