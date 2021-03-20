#!/bin/bash
name="$1"
if ! grep -qE "KO306482" "$name";then
	cat "$name"
	echo "Commit needs to start with initials and inex number"
	exit 1
fi
