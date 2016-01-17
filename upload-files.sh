#!/bin/bash

upload_to_remote () {
	echo -n Uploading to Remote...' '

	remote="ghorbanzade.com"
	puts=$(print_put_statements_from_file $1)
	
	ftp $remote <<-EOT
	binary
	cd public_html
	$puts
	quit
	EOT
	
	echo OK
}

print_put_statements_from_file () {
	src_dir="bin/documents/"
	dst_dir="bin/courses/CS240-2016S/"
	while IFS='' read -r line || [[ -n "$line" ]]; do
		if [ ! -z "$line" ] && [ ${line::1} != '#' ]; then
			src_path=$src_dir$line
			dst_path=$dst_dir$line
			echo "put $src_path $dst_path"
		fi
	done < "$1"
}

upload_to_remote cfg/remote-files.list
